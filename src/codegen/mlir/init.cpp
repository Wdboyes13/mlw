#include "../gen_mlir.hpp"

#include <MLWLexer.h>
#include <MLWParser.h>
#include <mlir/IR/Verifier.h>

#include <vector>

#include <MLWDialect.h>

using namespace mlir;
using namespace antlr4;

#define def_mlg_pctx(method_name) void MLIRGen::method_name(MLWParser::ProgramContext* ctx)
#define def_mlg_fctx(method_name) void MLIRGen::method_name(MLWParser::FunctionDefinitionContext* ctx)

MLIRGen::MLIRGen(MLIRContext* ctx)
    : ctx(ctx), builder(ctx) {}

def_mlg_pctx(enterProgram) {
    module = ModuleOp::create(builder.getUnknownLoc());
    builder.setInsertionPointToEnd(module.getBody());
}

std::string make_implib_str(std::vector<std::string> implibs) {
    std::stringstream ss;
    for (int i = 0; i < implibs.size() - 1; i++) {
        ss << implibs[i] << ",";
    }
    ss << implibs[implibs.size() - 1];
    return ss.str();
}

def_mlg_pctx(exitProgram) {
    builder.create<mlw::ImplibsOp>(builder.getUnknownLoc(), builder.getArrayAttr(libs));
    if (failed(verify(module))) {
        module.emitError("Module verification failed");
    }
}