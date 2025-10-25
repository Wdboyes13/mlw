#include <mlir/Parser/Parser.h>
#include <mlir/IR/MLIRContext.h>
#include <mlir/Dialect/Func/IR/FuncOps.h>
#include <mlir/Dialect/Arith/IR/Arith.h>
#include <llvm/Support/DynamicLibrary.h>
#include <mlir/ExecutionEngine/ExecutionEngine.h>

#include <MLWDialect.h>

#include <mlir/IR/BuiltinOps.h>

#include <filesystem>
#include <vector>

#include <llvm/Support/TargetSelect.h>
#include <mlir/IR/Verifier.h>

std::string locate_lib(const std::string &basename, std::string script_basename) {
    std::vector<std::string> search_paths = {
        script_basename, "/usr/local/lib/mlw/",
        "./lib/mlw/", "../lib/mlw/"
    };

    for (auto search_path : search_paths) {
        if (std::filesystem::exists(search_path + basename + ".mlwlib")) {
            return std::string(search_path + basename + ".mlwlib");
        }
    }
    throw std::invalid_argument("No such file or directory when searching for library " + basename);
}

int main(const int argc, char* argv[]) {
    if (argc < 2) {  // Fixed: should be < 2 since argv[0] is program name
        llvm::errs() << "Usage: " << argv[0] << " [bcfile.mlwbc]\n";
        return 1;
    }

    llvm::InitializeNativeTarget();
    llvm::InitializeNativeTargetAsmPrinter();
    llvm::InitializeNativeTargetAsmParser();

    std::string script_basename;
    if (std::filesystem::path(argv[1]).has_parent_path())
    script_basename = std::filesystem::path(argv[1]).parent_path().string() + "/";
    else script_basename = "./";

    try {
        auto ctx = std::make_unique<mlir::MLIRContext>();
        ctx->loadDialect<mlir::func::FuncDialect>();
        ctx->loadDialect<mlir::arith::ArithDialect>();
        ctx->loadDialect<mlw::MLWDialect>();
        ctx->allowUnregisteredDialects();

        const mlir::ParserConfig config(ctx.get(), false);
        const auto input = mlir::parseSourceFile<mlir::ModuleOp>(argv[1], config);

        if (!input) {
            llvm::errs() << "Failed to parse input file\n";
            return 1;
        }

        mlir::ExecutionEngineOptions options;

        input.get()->walk([&](mlir::Operation* op) {
           if (op->getName().getStringRef() == "mlw.implibs") {
                auto impop = llvm::dyn_cast<mlw::ImplibsOp>(op);
                auto implibs = impop.getLibraries();
                for (auto implib : implibs) {
                    llvm::outs() << "Loading " << implib << "\n";
                    auto lib = locate_lib(implib.cast<mlir::StringAttr>().getValue().str(), script_basename);
                    llvm::sys::DynamicLibrary::getPermanentLibrary(lib.c_str());
                }
               op->erase();
           }
        });

        if (failed(verify(input.get()))) {
            llvm::errs() << "Module verification failed before ExecutionEngine creation\n";
            return 1;
        }

        input.get()->print(llvm::outs());

        auto engineOrError = mlir::ExecutionEngine::create(input.get(), options);
        if (!engineOrError) {
            llvm::errs() << "JIT engine creation failed: "
                         << llvm::toString(engineOrError.takeError()) << "\n";
            return 1;
        }

        auto engine = std::move(engineOrError.get());
        if (auto main = engine->lookup("main")) {
            return reinterpret_cast<int32_t(*)()>(*main)();
        } else {
            llvm::errs() << "Could not find main function\n";
            return 1;
        }
    } catch (const std::exception& e) {
        llvm::errs() << "Exception: " << e.what() << "\n";
        return 1;
    }
}