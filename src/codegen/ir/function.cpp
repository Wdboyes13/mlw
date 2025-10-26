/* Copyright (c) 2025 Wdboyes13
   SPDX-License-Identifier: Wdboyes13 
   This code is part of the MLW Project 
   Function Generation (function.cpp) */

#include "../gen_llvm.hpp"

#include <MLWLexer.h>
#include <MLWParser.h>


using namespace antlr4;

#define def_mlg_fctx(method_name) void LLVMGen::method_name(MLWParser::FunctionDefinitionContext* ctx)

def_mlg_fctx(enterFunctionDefinition) {
    valueStacks.push(std::stack<llvm::Value*>());


    std::string fn_name = ctx->identifier()->getText();
    symbolTable.clear();
    std::vector<llvm::Type*> paramTypes;
    if (auto paramList = ctx->parameterList()) {
        for (auto param : paramList->parameter()) {
            auto typnam = param->type()->getText();
            paramTypes.push_back(getType(typnam));
        }
    }

    llvm::Type* returnType = getType(ctx->type()->getText());
    auto fntype = llvm::FunctionType::get(returnType, paramTypes, false);

    currentFunction = llvm::Function::Create(
        fntype,
        llvm::Function::ExternalLinkage,
        fn_name,
        _module.get()
    );

    auto entry_block = llvm::BasicBlock::Create(
        *this->ctx,
        "entry",
        currentFunction
    );
    builder.SetInsertPoint(entry_block);

    if (auto paramList = ctx->parameterList()) {
        size_t i = 0;
        // Use the function's arg_iterator to get the SSA values for parameters
        for (auto& Arg : currentFunction->args()) {
            // Get the name from your parser context
            std::string paramName = paramList->parameter(i)->identifier()->getText();

            // Set the SSA name in the IR for debugging (optional but recommended)
            Arg.setName(paramName);

            // Store the llvm::Value* (the argument itself) in the symbol table
            symbolTable[paramName] = &Arg;
            i++;
        }
    }
}

def_mlg_fctx(exitFunctionDefinition) {
    if (!builder.GetInsertBlock()->getTerminator()) {
        if (currentFunction->getReturnType()->isVoidTy()) {
            builder.CreateRetVoid();
        } else {
            // For non-void functions, this is an error
            llvm::errs() << "Error: Non-void function missing return statement: "
                         << currentFunction->getName() << "\n";
            // Create an undef return as fallback (not ideal, but prevents crash)
            builder.CreateRet(llvm::UndefValue::get(currentFunction->getReturnType()));
        }
    }

    currentFunction = nullptr;
    if (!valueStacks.empty()) {
        valueStacks.pop();
    }
}


void LLVMGen::exitRetStmt(MLWParser::RetStmtContext *ctx) {
    if (ctx->expression()) {
        if (valueStacks.top().empty()) {
            llvm::errs() << "No value for return expression\n";
            builder.CreateRet(llvm::UndefValue::get(currentFunction->getReturnType()));
        } else {
            llvm::Value* retVal = popValue();
            // Add type checking
            if (retVal->getType() != currentFunction->getReturnType()) {
                llvm::errs() << "Function return type does not match return value type!\n";
            }
            builder.CreateRet(retVal);
        }
    } else {
        // For void returns, ensure function returns void
        if (!currentFunction->getReturnType()->isVoidTy()) {
            llvm::errs() << "Error: Returning void from non-void function: "
                         << currentFunction->getName() << "\n";
        }
        builder.CreateRetVoid();
    }
}

void LLVMGen::enterCallExpr(MLWParser::CallExprContext *ctx) {
    inCallExpr = true;
}

void LLVMGen::exitCallExpr(MLWParser::CallExprContext *ctx) {
    std::string calleeName;
    auto innerPostfix = ctx->postfixExpression();

    // Check if the inner postfix expression is just an identifier
    if (auto primaryCtx = dynamic_cast<MLWParser::PrimaryPostfixContext*>(innerPostfix)) {
        if (auto identifierCtx = dynamic_cast<MLWParser::IdentifierExprContext*>(primaryCtx->primaryExpression())) {
            calleeName = identifierCtx->identifier()->getText();
        } else {
            llvm::errs() << "Call expression must be an identifier\n";
            return;
        }
    }

    // Collect arguments from value stack
    std::vector<llvm::Value*> args;

    MLWParser::ArgumentListContext* argLists = ctx->argumentList();
    if (argLists && !argLists->isEmpty()) {
        size_t argCount = argLists->expression().size();
        args.resize(argCount);

        // Pop arguments in reverse order
        for (int i = argCount - 1; i >= 0; --i) {
            if (valueStacks.top().empty()) {
                llvm::errs() << "Not enough arguments for function call to " << calleeName;
                return;
            }
            args[i] = popValue();
        }
    }

    // Look for the function
    auto func = _module->getFunction(calleeName);
    if (!func) {
        llvm::errs() << "Undefined function: " << calleeName;
        return;
    }

    // Verify argument counts match
    if (args.size() != func->arg_size()) {
        llvm::errs() << "Argument count mismatch for function: " << calleeName;
        return;
    }

    auto call = builder.CreateCall(func, args);

    // ONLY push if the function returns a non-void value
    if (!call->getType()->isVoidTy()) {
        pushValue(call);
    }
    inCallExpr = false;
}