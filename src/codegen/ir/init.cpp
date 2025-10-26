#include "../gen_mlir.hpp"

#include <MLWLexer.h>
#include <MLWParser.h>

#include <llvm/IR/Verifier.h>

using namespace antlr4;

#define def_mlg_pctx(method_name) void LLVMGen::method_name(MLWParser::ProgramContext* ctx)
#define def_mlg_fctx(method_name) void LLVMGen::method_name(MLWParser::FunctionDefinitionContext* ctx)

LLVMGen::LLVMGen(llvm::LLVMContext* ctx, ParseResources* rsrsc, bool _debug)
    : ctx(ctx), builder(*ctx), debug_parse_rsrsc(rsrsc), debug(_debug) {}

def_mlg_pctx(enterProgram) {
    _module = std::make_unique<llvm::Module>("program", *this->ctx);
}

def_mlg_pctx(exitProgram) {

    auto val = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*this->ctx), implibs_idx);
    auto var = new llvm::GlobalVariable(
        *_module,
        val->getType(),
        true,
        llvm::GlobalVariable::ExternalLinkage,
        val,
        "__vm_implibs_count");
    if (llvm::verifyModule(*_module, &llvm::errs())) {
        llvm::errs() << "Module verification failed\n";
    }
}