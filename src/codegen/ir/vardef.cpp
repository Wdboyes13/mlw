/* Copyright (c) 2025 Wdboyes13
   SPDX-License-Identifier: Wdboyes13
   This code is part of the MLW Project
   Variable Generation (vardef.cpp) */

#include "../gen_llvm.hpp"

#include <MLWLexer.h>
#include <MLWParser.h>

using namespace antlr4;

void LLVMGen::exitExprStatement(MLWParser::ExprStatementContext* ctx) {
    // Expression statements should consume their result
    if (!value_stacks.top().empty()) {
        pop_value(); // Discard the expression result
    }
}

void LLVMGen::exitIntLiteral(MLWParser::IntLiteralContext* ctx) {
    auto contop = llvm::ConstantInt::get(
        llvm::Type::getInt32Ty(*this->ctx),
        std::stoi(ctx->IntegerLiteral()->getText()));
    push_value(contop);
}

llvm::StringRef get_fnc_name(llvm::IRBuilder<>& builder) {
    llvm::BasicBlock* current_block = builder.GetInsertBlock();
    if (!current_block) {
        return "";
    }

    llvm::Function* current_function = current_block->getParent();
    if (!current_function) {
        return "";
    }

    return current_function->getName();
}

std::string construct_str_name(llvm::IRBuilder<>& builder, std::string dn) {
    std::stringstream ss;
    auto fnc = get_fnc_name(builder);
    ss << "__strval_" << fnc.str() << "." << dn;
    return ss.str();
}

void LLVMGen::exitStringLiteral(MLWParser::StringLiteralContext* ctx) {
    auto contop = builder.CreateGlobalString(
        ctx->StringLiteral()->getText(),
        construct_str_name(builder, std::to_string(str_idx)));
    str_idx++;

    push_value(contop);
}

void LLVMGen::exitBoolLiteral(MLWParser::BoolLiteralContext* ctx) {
    bool value = (ctx->BooleanLiteral()->getText() == "true");
    auto contop = llvm::ConstantInt::get(llvm::Type::getInt1Ty(*this->ctx), value);
    push_value(contop);
}

void LLVMGen::enterIdentifierExpr(MLWParser::IdentifierExprContext* ctx) {
    if (in_call_expr) {
        return;
    }
    std::string var_name = ctx->identifier()->getText();
    auto it = symbol_table.find(var_name);
    if (it != symbol_table.end()) {
        push_value(it->second);
    } else {
        llvm::errs() << "Undefined variable: " << var_name;
    }
}

void LLVMGen::exitVarDeclWithInit(MLWParser::VarDeclWithInitContext* ctx) {
    std::string var_name = ctx->identifier()->getText();

    // Get the initialization value from stack
    if (value_stacks.top().empty()) {
        llvm::errs() << "No value for variable initialization: " << var_name;
        return;
    }

    auto init_value = pop_value();
    symbol_table[var_name] = init_value;

    push_value(init_value);
}

void LLVMGen::enterVarDeclWithoutInit(
    MLWParser::VarDeclWithoutInitContext* ctx) {
    std::string var_name = ctx->identifier()->getText();
    auto type = get_type(ctx->type()->getText());

    // Create a default value
    auto default_val = llvm::ConstantInt::get(type, 0);

    symbol_table[var_name] = default_val;
    push_value(default_val);
}
