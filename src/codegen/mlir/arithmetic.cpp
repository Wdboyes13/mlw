#include "../gen_mlir.hpp"

#include <MLWLexer.h>
#include <MLWParser.h>

using namespace mlir;
using namespace antlr4;

void MLIRGen::enterAdditiveExpr(MLWParser::AdditiveExprContext *ctx) {
    operatorStack.push(ctx->op->getText());
}

void MLIRGen::exitAdditiveExpr(MLWParser::AdditiveExprContext *ctx) {
    if (valueStacks.top().size() < 2) return;

    auto rhs = popValue();
    auto lhs = popValue();
    auto op = operatorStack.top();
    operatorStack.pop();

    Value result;
    if (op == "+") {
        result = builder.create<arith::AddIOp>(getLoc(), lhs, rhs);
    } else if (op == "-") {
        result = builder.create<arith::SubIOp>(getLoc(), lhs, rhs);
    }

    if (result) {
        pushValue(result);
    }
}

void MLIRGen::enterMultiplicativeExpr(MLWParser::MultiplicativeExprContext *ctx) {
    operatorStack.push(ctx->op->getText());
}

void MLIRGen::exitMultiplicativeExpr(MLWParser::MultiplicativeExprContext *ctx) {
    if (valueStacks.top().size() < 2) return;

    auto rhs = popValue();
    auto lhs = popValue();
    auto op = operatorStack.top();
    operatorStack.pop();

    Value result;
    if (op == "*") {
        result = builder.create<arith::MulIOp>(getLoc(), lhs, rhs);
    } else if (op == "/") {
        result = builder.create<arith::DivSIOp>(getLoc(), lhs, rhs);
    }

    if (result) {
        pushValue(result);
    }
}