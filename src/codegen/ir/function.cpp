/* Copyright (c) 2025 Wdboyes13
   SPDX-License-Identifier: Wdboyes13
   This code is part of the MLW Project
   Function Generation (function.cpp) */

#include "../gen_llvm.hpp"

#include <MLWLexer.h>
#include <MLWParser.h>

using namespace antlr4;

void LLVMGen::enterFunctionDefinition(
    MLWParser::FunctionDefinitionContext* ctx) {
    value_stacks.push(std::stack<llvm::Value*>());

    std::string fn_name = ctx->identifier()->getText();
    symbol_table.clear();
    std::vector<llvm::Type*> param_types;
    if (auto param_list = ctx->parameterList()) {
        for (auto param : param_list->parameter()) {
            auto typnam = param->type()->getText();
            param_types.push_back(get_type(typnam));
        }
    }

    llvm::Type* return_type = get_type(ctx->type()->getText());
    auto fntype = llvm::FunctionType::get(return_type, param_types, false);

    current_function = llvm::Function::Create(
        fntype,
        llvm::Function::ExternalLinkage,
        fn_name,
        module.get());

    auto entry_block = llvm::BasicBlock::Create(*this->ctx, "entry", current_function);
    builder.SetInsertPoint(entry_block);

    if (auto param_list = ctx->parameterList()) {
        size_t i = 0;
        // Use the function's arg_iterator to get the SSA values for parameters
        for (auto& arg : current_function->args()) {
            // Get the name from your parser context
            std::string param_name = param_list->parameter(i)->identifier()->getText();

            // Set the SSA name in the IR for debugging (optional but
            // recommended)
            arg.setName(param_name);

            // Store the llvm::Value* (the argument itself) in the symbol table
            symbol_table[param_name] = &arg;
            i++;
        }
    }
}

void LLVMGen::exitFunctionDefinition(
    MLWParser::FunctionDefinitionContext* ctx) {
    if (!builder.GetInsertBlock()->getTerminator()) {
        if (current_function->getReturnType()->isVoidTy()) {
            builder.CreateRetVoid();
        } else {
            // For non-void functions, this is an error
            llvm::errs()
                << "Error: Non-void function missing return statement: "
                << current_function->getName() << "\n";
            // Create an undef return as fallback (not ideal, but prevents
            // crash)
            builder.CreateRet(llvm::UndefValue::get(current_function->getReturnType()));
        }
    }

    current_function = nullptr;
    if (!value_stacks.empty()) {
        value_stacks.pop();
    }
}

void LLVMGen::exitRetStmt(MLWParser::RetStmtContext* ctx) {
    if (ctx->expression()) {
        if (value_stacks.top().empty()) {
            llvm::errs() << "No value for return expression\n";
            builder.CreateRet(llvm::UndefValue::get(current_function->getReturnType()));
        } else {
            llvm::Value* ret_val = pop_value();
            // Add type checking
            if (ret_val->getType() != current_function->getReturnType()) {
                llvm::errs() << "Function return type does not match return value type!\n";
            }
            builder.CreateRet(ret_val);
        }
    } else {
        // For void returns, ensure function returns void
        if (!current_function->getReturnType()->isVoidTy()) {
            llvm::errs() << "Error: Returning void from non-void function: "
                         << current_function->getName() << "\n";
        }
        builder.CreateRetVoid();
    }
}

void LLVMGen::enterCallExpr(MLWParser::CallExprContext* ctx) {
    in_call_expr = true;
}

void LLVMGen::exitCallExpr(MLWParser::CallExprContext* ctx) {
    std::string callee_name;
    auto inner_postfix = ctx->postfixExpression();

    // Check if the inner postfix expression is just an identifier
    if (auto primary_ctx = dynamic_cast<MLWParser::PrimaryPostfixContext*>(inner_postfix)) {
        if (auto identifier_ctx = dynamic_cast<MLWParser::IdentifierExprContext*>(primary_ctx->primaryExpression())) {
            callee_name = identifier_ctx->identifier()->getText();
        } else {
            llvm::errs() << "Call expression must be an identifier\n";
            return;
        }
    }

    // Collect arguments from value stack
    std::vector<llvm::Value*> args;

    MLWParser::ArgumentListContext* arg_lists = ctx->argumentList();
    if (arg_lists && !arg_lists->isEmpty()) {
        size_t arg_count = arg_lists->expression().size();
        args.resize(arg_count);

        // Pop arguments in reverse order
        for (int i = arg_count - 1; i >= 0; --i) {
            if (value_stacks.top().empty()) {
                llvm::errs() << "Not enough arguments for function call to " << callee_name;
                return;
            }
            args[i] = pop_value();
        }
    }

    // Look for the function
    auto func = module->getFunction(callee_name);
    if (!func) {
        llvm::errs() << "Undefined function: " << callee_name;
        return;
    }

    // Verify argument counts match
    if (args.size() != func->arg_size()) {
        llvm::errs() << "Argument count mismatch for function: " << callee_name;
        return;
    }

    auto call = builder.CreateCall(func, args);

    // ONLY push if the function returns a non-void value
    if (!call->getType()->isVoidTy()) {
        push_value(call);
    }
    in_call_expr = false;
}
