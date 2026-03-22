/* Copyright (c) 2025 Wdboyes13
   SPDX-License-Identifier: Wdboyes13
   This code is part of the MLW Project
   Import and extern support (import.cpp) */

#include "../gen_llvm.hpp"

void LLVMGen::enterImportStatement(MLWParser::ImportStatementContext* ctx) {
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
    llvm::Constant* global_str = llvm::ConstantDataArray::getString(*this->ctx, libname);
    llvm::GlobalVariable* gv =
        new llvm::GlobalVariable(
            *module,
            global_str->getType(),
            true, // isConstant
            llvm::GlobalValue::ExternalLinkage,
            global_str,
            "__vm_implibs." + std::to_string(implibs_idx));

    implibs_idx++;
}

void LLVMGen::enterExternStatement(MLWParser::ExternStatementContext* ctx) {
    std::string fn_name = ctx->identifier()->getText();
    symbol_table.clear();
    std::vector<llvm::Type*> param_types;
    if (auto param_list = ctx->parameterList_typeonly()) {
        for (auto param : param_list->parameter_typeonly()) {
            auto type_name = param->type()->getText();
            param_types.push_back(get_type(type_name));
        }
    }

    auto return_type = get_type(ctx->type()->getText());
    auto fn_type = llvm::FunctionType::get(return_type, param_types, false);

    llvm::Function::Create(
        fn_type,
        llvm::Function::ExternalLinkage,
        fn_name,
        module.get());
}
