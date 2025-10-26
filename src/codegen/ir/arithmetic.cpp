#include "../gen_mlir.hpp"

void LLVMGen::enterAdditiveExpr(MLWParser::AdditiveExprContext *ctx) {
    operatorStack.push(ctx->op->getText());
}

void LLVMGen::exitAdditiveExpr(MLWParser::AdditiveExprContext *ctx) {
    if (valueStacks.top().size() < 2) {
        llvm::errs() << "Not enough values for additive expression\n";
        return;
    }

    auto rhs = popValue();
    auto lhs = popValue();
    auto op = operatorStack.top();
    operatorStack.pop();

    // Verify both operands have the same type
    if (lhs->getType() != rhs->getType()) {
        llvm::errs() << "Type mismatch in additive expression\n";
        return;
    }

    llvm::Value* result = nullptr;

    if (op == "+") {
        result = builder.CreateAdd(lhs, rhs);
    } else if (op == "-") {
        result = builder.CreateSub(lhs, rhs);  // Fixed: CreateSub instead of CreateAdd
    } else {
        llvm::errs() << "Unknown additive operator: " << op << "\n";
        return;
    }

    if (result) {
        pushValue(result);
    }
}

void LLVMGen::enterMultiplicativeExpr(MLWParser::MultiplicativeExprContext *ctx) {
    operatorStack.push(ctx->op->getText());
}

void LLVMGen::exitMultiplicativeExpr(MLWParser::MultiplicativeExprContext *ctx) {
    if (valueStacks.top().size() < 2) {
        llvm::errs() << "Not enough values for multiplicative expression\n";
        return;
    }

    auto rhs = popValue();
    auto lhs = popValue();
    auto op = operatorStack.top();
    operatorStack.pop();

    // Verify both operands have the same type
    if (lhs->getType() != rhs->getType()) {
        llvm::errs() << "Type mismatch in multiplicative expression\n";
        return;
    }

    llvm::Value* result = nullptr;

    if (op == "*") {
        result = builder.CreateMul(lhs, rhs);
    } else if (op == "/") {
        // Use signed division for integers
        if (lhs->getType()->isIntegerTy()) {
            result = builder.CreateSDiv(lhs, rhs);
        } else {
            result = builder.CreateFDiv(lhs, rhs);  // For floating point
        }
    } else if (op == "%") {
        // Handle modulo operation
        if (lhs->getType()->isIntegerTy()) {
            result = builder.CreateSRem(lhs, rhs);
        } else {
            llvm::errs() << "Modulo operator only supported for integer types\n";
            return;
        }
    } else {
        llvm::errs() << "Unknown multiplicative operator: " << op << "\n";
        return;
    }

    if (result) {
        pushValue(result);
    }
}