#include "vm_class.hpp"

#include <llvm/Support/TargetSelect.h>

MLWVM::MLWVM(std::unique_ptr<llvm::Module> mod, llvm::LLVMContext& ctx, int argc, char** argv, std::string script_pth)
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