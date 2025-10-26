/* Copyright (c) 2025 Wdboyes13
   SPDX-License-Identifier: Wdboyes13 
   This code is part of the MLW Project 
   Import and extern support (import.cpp) */

#include "../gen_llvm.hpp"

void LLVMGen::enterImportStatement(MLWParser::ImportStatementContext *ctx) {
    if (!ctx) {
        llvm::errs() << "Null context in import statement\n";
        return;
    }
    auto identifier = ctx->identifier();
    if (!identifier) {
        llvm::errs() << "Expected identifier in import statement";
        return;
    }
    const auto libname = ctx->identifier()->getText();
    llvm::Constant* globalStr = llvm::ConstantDataArray::getString(*this->ctx, libname);
    llvm::GlobalVariable* gv = new llvm::GlobalVariable(
        *_module,
        globalStr->getType(),
        true,  // isConstant
        llvm::GlobalValue::ExternalLinkage,
        globalStr,
        "__vm_implibs." + std::to_string(implibs_idx)
    );

    implibs_idx++;
}

void LLVMGen::enterExternStatement(MLWParser::ExternStatementContext *ctx) {
    std::string fn_name = ctx->identifier()->getText();
    symbolTable.clear();
    std::vector<llvm::Type*> paramTypes;
    if (auto paramList = ctx->parameterList_typeonly()) {
        for (auto param : paramList->parameter_typeonly()) {
            auto typeName = param->type()->getText();
            paramTypes.push_back(getType(typeName));
        }
    }

    auto returnType = getType(ctx->type()->getText());
    auto fn_type = llvm::FunctionType::get(returnType, paramTypes, false);

    llvm::Function::Create(
        fn_type,
        llvm::Function::ExternalLinkage,
        fn_name,
        _module.get()
    );

}