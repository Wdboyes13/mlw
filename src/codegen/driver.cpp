#include "gen_mlir.hpp"
#include "gen_tree.hpp"


#include <llvm/Support/ToolOutputFile.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Bitcode/BitcodeWriter.h>

#include <filesystem>

using namespace antlr4;

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

    llvm::LLVMContext* ctx = new llvm::LLVMContext();

    LLVMGen generator(ctx);
    tree::ParseTreeWalker walker;
    walker.walk(&generator, resources->tree);

    auto module = generator.getModule();
    if (module) {
        module->print(llvm::outs(), nullptr);
        auto outputFilename = make_bc_name(argv[1]);
        std::string errorInfo;

        std::error_code errorCode;
        auto out = std::make_unique<llvm::ToolOutputFile>(outputFilename, errorCode, llvm::sys::fs::OF_None);
        if (errorCode) {
            llvm::errs() << "Failed to write output file\n";
            return 1;
        }

        llvm::WriteBitcodeToFile(*module, out->os());
        out->keep();
    } else {
        llvm::errs() << "Failed to generate MLIR\n";
        return 1;
    }

    return 0;
}