#include "../gen_mlir.hpp"

void MLIRGen::enterImportStatement(MLWParser::ImportStatementContext *ctx) {
    const auto libname = ctx->identifier()->getText();
    libs.push_back(builder.getStringAttr(libname));
}

void MLIRGen::enterExternStatement(MLWParser::ExternStatementContext *ctx) {
    std::string fn_name = ctx->identifier()->getText();
    symbolTable.clear();
    std::vector<Type> paramTypes;
    if (auto paramList = ctx->parameterList_typeonly()) {
        for (auto param : paramList->parameter_typeonly()) {
            auto typeName = param->type()->getText();
            paramTypes.push_back(getType(typeName));
        }
    }

    auto returnType = getType(ctx->type()->getText());
    auto fn_type = builder.getFunctionType(paramTypes, returnType);

    auto extern_func = func::FuncOp::create(
        builder.getUnknownLoc(),
        fn_name,
        fn_type,
        mlir::ArrayRef<NamedAttribute>()
    );

    extern_func.setPrivate();

    module.push_back(extern_func);
}