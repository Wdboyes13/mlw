#include <llvm/IR/Module.h>
#include <memory>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/GlobalVariable.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/InitLLVM.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/ExecutionEngine/Orc/LLJIT.h>
#include <llvm/ExecutionEngine/Orc/ThreadSafeModule.h>
#include <llvm/ExecutionEngine/Orc/ObjectLinkingLayer.h>
#include <llvm/ExecutionEngine/Orc/IRCompileLayer.h>
#include <llvm/ExecutionEngine/Orc/RTDyldObjectLinkingLayer.h>
#include <llvm/Support/DynamicLibrary.h>
#include <filesystem>
#include <cstdio>

class MLWVM {
private:
    std::unique_ptr<llvm::Module> module;
    std::unique_ptr<llvm::orc::LLJIT> jit;
    llvm::LLVMContext& context;
    std::unique_ptr<llvm::InitLLVM> initLLVM;

    int num_implibs;
    std::vector<std::string> implibs;
    std::string script_path;

public:

    std::string locate_lib(const std::string &basename, std::string script_basename) {
        std::vector<std::string> search_paths = {
            script_basename, 
            "/usr/local/lib/mlw/",
            "./lib/mlw/", 
            "../lib/mlw/",
            "./"  // Add current directory as fallback
        };

        for (const auto& search_path : search_paths) {
            std::string full_path = search_path + basename;
            llvm::errs() << "Checking " << full_path << "\n";
            
            FILE* f = fopen(full_path.c_str(), "r");
            if (f != NULL) {
                return full_path;
            }
            
            llvm::errs() << "  Not found\n";
        }
        return basename;
    }

    MLWVM(std::unique_ptr<llvm::Module> mod, llvm::LLVMContext& ctx, int argc, char** argv, std::string script_pth)
        : module(std::move(mod)), context(ctx), script_path(script_pth) {
            // Initialize LLVM targets
        llvm::InitializeAllTargetInfos();
        llvm::InitializeAllTargets();
        llvm::InitializeAllTargetMCs();
        llvm::InitializeAllAsmPrinters();
        llvm::InitializeAllAsmParsers();
        
        // JIT-specific initialization
        llvm::InitializeNativeTarget();
        llvm::InitializeNativeTargetAsmPrinter();
        llvm::InitializeNativeTargetAsmParser();

        initLLVM = std::make_unique<llvm::InitLLVM>(argc, argv);
        findImplibs();
    }

    void findImplibs() {
        auto globcount = module->getNamedGlobal("__vm_implibs_count");
        if (!globcount) {
            llvm::errs() << "Couldn't find import library count\n";
            std::abort();
        }
        auto initcount = globcount->getInitializer();
        if (auto* constint = llvm::dyn_cast<llvm::ConstantInt>(initcount)) {
            num_implibs = constint->getZExtValue();
        }

        for (int i = 0; i < num_implibs; i++) {
            auto implib_var = module->getNamedGlobal("__vm_implibs." + std::to_string(i));
            if (!implib_var) {
                llvm::errs() << "Import Library Count Variable (__vm_implibs_count) contains incorrect value\n";
                std::abort();
            }

            auto implib_initializer = implib_var->getInitializer();
            if (auto* constint = llvm::dyn_cast<llvm::ConstantDataArray>(implib_initializer)) {
                implibs.push_back(constint->getAsString().str());
            }
        }

        llvm::errs() << "Found " << num_implibs << " import libraries:\n";
        for (const auto& lib : implibs) {
            llvm::errs() << "  - " << lib << "\n";
        }
    }

    void finalize() {
        // Create LLJIT instance
        auto jitResult = llvm::orc::LLJITBuilder().create();
        if (!jitResult) {
            llvm::errs() << "Failed to create LLJIT: "
                         << llvm::toString(jitResult.takeError()) << "\n";
            std::abort();
        }

        jit = std::move(*jitResult);

        // Load system libraries first
        llvm::sys::DynamicLibrary::LoadLibraryPermanently(nullptr);

        // Load your import libraries
        for (const auto& libName : implibs) {
            std::string fullLibName = std::filesystem::absolute(locate_lib(libName, script_path));

            llvm::errs() << "Loading library: " << fullLibName << "\n";

            std::string errorMsg;
            if (!llvm::sys::DynamicLibrary::LoadLibraryPermanently(fullLibName.c_str(), &errorMsg)) {
                llvm::errs() << "Successfully loaded: " << fullLibName << "\n";
            } else {
                llvm::errs() << "Warning: Failed to load " << fullLibName << ": " << errorMsg << "\n";

                // Try without prefix/suffix
                if (!llvm::sys::DynamicLibrary::LoadLibraryPermanently(libName.c_str(), &errorMsg)) {
                    llvm::errs() << "Successfully loaded: " << libName << " (raw name)\n";
                } else {
                    llvm::errs() << "Error: Could not load library in any form: " << libName << "\n";
                }
            }
        }

        // Add the module to JIT
        llvm::orc::ThreadSafeModule tsm(std::move(module), std::make_unique<llvm::LLVMContext>());
        if (auto err = jit->addIRModule(std::move(tsm))) {
            llvm::errs() << "Failed to add IR module: " << llvm::toString(std::move(err)) << "\n";
            std::abort();
        }

        llvm::errs() << "JIT engine finalized successfully with " << implibs.size() << " libraries loaded\n";
    }

    llvm::GenericValue runFunction(const std::string& functionName,
                                  const std::vector<llvm::GenericValue>& args = {}) {
        if (!jit) {
            llvm::errs() << "JIT not initialized. Call finalize() first.\n";
            return llvm::GenericValue();
        }

        // Lookup the function
        auto sym = jit->lookup(functionName);
        if (!sym) {
            llvm::errs() << "Function '" << functionName << "' not found: "
                         << llvm::toString(sym.takeError()) << "\n";
            return llvm::GenericValue();
        }

        llvm::errs() << "Executing function: " << functionName << "\n";

        // Cast to function pointer and call
        using MainFunc = int(*)(void);
        auto funcPtr = sym.get().toPtr<MainFunc>();
        int result = funcPtr();

        // Convert to GenericValue
        llvm::GenericValue gv;
        gv.IntVal = llvm::APInt(32, result);
        return gv;
    }
};

#include <llvm/Bitcode/BitcodeReader.h>
#include <llvm/Support/MemoryBuffer.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        llvm::errs() << "Usage: " << argv[0] << " <filename>\n";
        return 1;
    }

    auto filebuffer = llvm::MemoryBuffer::getFile(argv[1]);
    if (!filebuffer) {
        llvm::errs() << "Failed to read file '" << argv[1] << "'\n";
        return 1;
    }

    auto context = std::make_unique<llvm::LLVMContext>();
    auto moduleResult = llvm::parseBitcodeFile(filebuffer.get()->getMemBufferRef(), *context);

    if (!moduleResult) {
        llvm::errs() << "Failed to parse bitcode file: " << llvm::toString(moduleResult.takeError()) << "\n";
        return 1;
    }

    std::filesystem::path script = argv[1];
    std::string script_path;
    if (script.has_parent_path()) script_path = script.parent_path().string() + "/";
    else script_path = "./";

    auto vm = new MLWVM(std::move(*moduleResult), *context, argc, argv, script_path);
    vm->finalize();
    vm->runFunction("main");
}