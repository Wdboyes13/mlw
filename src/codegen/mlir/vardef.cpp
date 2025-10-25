#include "../gen_mlir.hpp"

#include <MLWLexer.h>
#include <MLWParser.h>

using namespace mlir;
using namespace antlr4;

void MLIRGen::exitExprStatement(MLWParser::ExprStatementContext *ctx) {
    // Expression statements should consume their result
    if (!valueStacks.top().empty()) {
        popValue();  // Discard the expression result
    }
}

void MLIRGen::exitIntLiteral(MLWParser::IntLiteralContext *ctx) {
    int value = std::stoi(ctx->IntegerLiteral()->getText());
    auto constOp = builder.create<arith::ConstantIntOp>(getLoc(), value, builder.getI32Type());
    pushValue(constOp.getResult());
}

void MLIRGen::exitStringLiteral(MLWParser::StringLiteralContext *ctx) {
    // For now, use integer placeholder for strings
    auto constOp = builder.create<arith::ConstantIntOp>(getLoc(), 0, builder.getI32Type());
    pushValue(constOp.getResult());
}

void MLIRGen::exitBoolLiteral(MLWParser::BoolLiteralContext *ctx) {
    bool value = (ctx->BooleanLiteral()->getText() == "true");
    auto constOp = builder.create<arith::ConstantIntOp>(getLoc(), value ? 1 : 0, builder.getI1Type());
    pushValue(constOp.getResult());
}

void MLIRGen::enterIdentifierExpr(MLWParser::IdentifierExprContext *ctx) {
    if (inCallExpr) return;
    std::string varName = ctx->identifier()->getText();
    auto it = symbolTable.find(varName);
    if (it != symbolTable.end()) {
        pushValue(it->second);
    } else {
        emitError(getLoc()) << "Undefined variable: " << varName;
    }
}


void MLIRGen::exitVarDeclWithInit(MLWParser::VarDeclWithInitContext *ctx) {
  std::string varName = ctx->identifier()->getText();

  // Get the initialization value from stack
  if (valueStacks.top().empty()) {
    emitError(getLoc()) << "No value for variable initialization: " << varName;
    return;
  }

  Value initValue = popValue();
  symbolTable[varName] = initValue;

    pushValue(initValue);
}

void MLIRGen::enterVarDeclWithoutInit(MLWParser::VarDeclWithoutInitContext *ctx) {
  std::string varName = ctx->identifier()->getText();
  auto type = getType(ctx->type()->getText());

  // Create a default value
  Value defaultVal;
  if (type.isInteger(32)) {
    defaultVal = builder.create<arith::ConstantIntOp>(getLoc(), 0, builder.getI32Type());
  } else if (type.isInteger(1)) {
    defaultVal = builder.create<arith::ConstantIntOp>(getLoc(), 0, builder.getI1Type());
  } else {
    defaultVal = builder.create<arith::ConstantIntOp>(getLoc(), 0, builder.getI32Type());
  }

  symbolTable[varName] = defaultVal;
    pushValue(defaultVal);
}