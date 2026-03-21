#pragma once

/* Copyright (c) 2025 Wdboyes13
   SPDX-License-Identifier: Wdboyes13
   This code is part of the MLW Project
   IR Generator Class Definition (gen_llvm.cpp) */

#include <string>

#include <map>
#include <stack>

#include <MLWBaseListener.h>
#include <MLWParser.h>

#include <llvm/IR/Attributes.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>

#include "gen_tree.hpp"

class LLVMGen : public MLWBaseListener {
  public:
    LLVMGen(llvm::LLVMContext* ctx, ParseResources* _rsrsc, bool debug = false);
    auto getModule() { return std::move(_module); }

    // Override key listener methods
    void enterProgram(MLWParser::ProgramContext* ctx) override;
    void exitProgram(MLWParser::ProgramContext* ctx) override;

    void
    enterFunctionDefinition(MLWParser::FunctionDefinitionContext* ctx) override;
    void
    exitFunctionDefinition(MLWParser::FunctionDefinitionContext* ctx) override;

    void exitVarDeclWithInit(MLWParser::VarDeclWithInitContext* ctx) override;
    void
    enterVarDeclWithoutInit(MLWParser::VarDeclWithoutInitContext* ctx) override;

    void exitRetStmt(MLWParser::RetStmtContext* ctx) override;

    void enterCallExpr(MLWParser::CallExprContext* ctx) override;
    void exitCallExpr(MLWParser::CallExprContext* ctx) override;

    void exitIntLiteral(MLWParser::IntLiteralContext* ctx) override;
    void exitStringLiteral(MLWParser::StringLiteralContext* ctx) override;
    void exitBoolLiteral(MLWParser::BoolLiteralContext* ctx) override;

    void enterIdentifierExpr(MLWParser::IdentifierExprContext* ctx) override;

    void enterAdditiveExpr(MLWParser::AdditiveExprContext* ctx) override;
    void exitAdditiveExpr(MLWParser::AdditiveExprContext* ctx) override;

    void
    enterMultiplicativeExpr(MLWParser::MultiplicativeExprContext* ctx) override;
    void
    exitMultiplicativeExpr(MLWParser::MultiplicativeExprContext* ctx) override;

    void enterImportStatement(MLWParser::ImportStatementContext* ctx) override;

    void enterExternStatement(MLWParser::ExternStatementContext* ctx) override;

    void exitExprStatement(MLWParser::ExprStatementContext* ctx) override;

    void enterEveryRule(antlr4::ParserRuleContext* ctx) override;
    void visitTerminal(antlr4::tree::TerminalNode* node) override;

  private:
    llvm::LLVMContext* ctx;
    llvm::IRBuilder<> builder;
    std::unique_ptr<llvm::Module> _module;

    std::map<std::string, llvm::Value*> symbolTable;
    std::stack<std::stack<llvm::Value*>> valueStacks;
    std::stack<std::string> operatorStack;
    llvm::Function* currentFunction;

    std::vector<llvm::Attribute> libs;
    bool inCallExpr;
    // Helper methods
    llvm::Type* getType(const std::string& typeName);
    llvm::Value* popValue();
    void pushValue(llvm::Value* value);

    std::stack<llvm::IRBuilderBase::InsertPoint> insertionStack;
    int implibs_idx = 0;
    int str_idx = 0;

    bool debug = false;
    ParseResources* debug_parse_rsrsc;
};
