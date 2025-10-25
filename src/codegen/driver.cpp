#include "gen_mlir.hpp"
#include "gen_tree.hpp"

#include <mlir/IR/MLIRContext.h>
#include <mlir/Bytecode/BytecodeWriter.h>
#include <mlir/Support/FileUtilities.h>
#include <llvm/Support/ToolOutputFile.h>

#include <MLWDialect.h>

#include <filesystem>

using namespace antlr4;
using namespace mlir;

std::string make_bc_name(std::string srcname) {
    std::filesystem::path p(srcname);
    p.replace_extension(".mlwbc");
    return p;
}


int main(int argc, char* argv[]) {
    if (argc != 2) {
        llvm::errs() << "Usage: " << argv[0] << " <source file>\n";
        return 1;
    }

    auto resources = generate_tree(argv[1]);
    if (!resources || !resources->tree) {
        llvm::errs() << "Failed to generate parse tree\n";
        return 1;
    }

    MLIRContext ctx;
    llvm::outs() << "Registering func dialect\n";
    ctx.loadDialect<func::FuncDialect>();
    llvm::outs() << "Registering arith dialect\n";
    ctx.loadDialect<arith::ArithDialect>();
    llvm::outs() << "Registering MLW dialect\n";
    ctx.loadDialect<mlw::MLWDialect>();
    ctx.allowUnregisteredDialects();

    MLIRGen generator(&ctx);
    tree::ParseTreeWalker walker;
    walker.walk(&generator, resources->tree);

    auto module = generator.getModule();
    if (module) {
        module->print(llvm::outs());
        auto outputFilename = make_bc_name(argv[1]);
        auto out = openOutputFile(outputFilename);
        if (failed(writeBytecodeToFile(module, out->os()))) {
            llvm::errs() << "Failed to write output file\n";
            return 1;
        }
        out->keep();
    } else {
        llvm::errs() << "Failed to generate MLIR\n";
        return 1;
    }

    return 0;
}