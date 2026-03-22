#include "gen_llvm.hpp"
#include <llvm/Bitcode/BitcodeWriter.h>
#include <llvm/Support/CommandLine.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/MemoryBuffer.h>
#include <llvm/Support/Program.h>
#include <llvm/Support/ToolOutputFile.h>

std::string make_bc_name(std::string srcname) {
    std::filesystem::path p(srcname);
    p.replace_extension(".mlwbc");
    return p;
}

int gen_llvm_main(bool debug, std::string file, std::string og_file) {
    auto resources = generate_tree(file);
    if (!resources || !resources->tree) {
        llvm::errs() << "Failed to generate parse tree\n";
        return 1;
    }

    llvm::LLVMContext* ctx = new llvm::LLVMContext();

    LLVMGen generator(ctx, resources.get(), debug);
    antlr4::tree::ParseTreeWalker walker;
    walker.walk(&generator, resources->tree);

    auto module = generator.get_module();
    if (module) {
        if (debug) {
            module->print(llvm::outs(), nullptr);
        }
        auto output_filename = make_bc_name(og_file);
        if (debug) {
            llvm::outs() << "Outputting to " << output_filename << "\n";
        }

        std::string error_info;

        std::error_code error_code;
        auto out = std::make_unique<llvm::ToolOutputFile>(
            output_filename,
            error_code,
            llvm::sys::fs::OF_None);

        if (error_code) {
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
