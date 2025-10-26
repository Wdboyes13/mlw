#include "../gen_mlir.hpp"

#include <MLWLexer.h>
#include <MLWParser.h>

using namespace antlr4;

void LLVMGen::exitExprStatement(MLWParser::ExprStatementContext *ctx) {
    // Expression statements should consume their result
    if (!valueStacks.top().empty()) {
        popValue();  // Discard the expression result
    }
}

void LLVMGen::exitIntLiteral(MLWParser::IntLiteralContext *ctx) {
    auto contop = llvm::ConstantInt::get(
      llvm::Type::getInt32Ty(*this->ctx),
      std::stoi(ctx->IntegerLiteral()->getText())
    );
    pushValue(contop);
}

llvm::StringRef getFncName(llvm::IRBuilder<>& builder) {
    llvm::BasicBlock* currentBlock = builder.GetInsertBlock();
    if (!currentBlock) {
        return "";
    }

    llvm::Function* currentFunction = currentBlock->getParent();
    if (!currentFunction) {
        return "";
    }

    return currentFunction->getName();
}

std::string constructStrName(llvm::IRBuilder<>& builder, std::string dn) {
    std::stringstream ss;
    auto fnc = getFncName(builder);
    ss << "__strval_" << fnc.str() << "." << dn;
    return ss.str();
}

void LLVMGen::exitStringLiteral(MLWParser::StringLiteralContext *ctx) {
    // For now, use integer placeholder for strings
    auto contop = builder.CreateGlobalString(
      ctx->StringLiteral()->getText(),
      constructStrName(builder, std::to_string(str_idx))
    );
    str_idx++;

    pushValue(contop);
}

void LLVMGen::exitBoolLiteral(MLWParser::BoolLiteralContext *ctx) {
    bool value = (ctx->BooleanLiteral()->getText() == "true");
    auto contop = llvm::ConstantInt::get(
        llvm::Type::getInt1Ty(*this->ctx),
        value
    );
    pushValue(contop);
}

void LLVMGen::enterIdentifierExpr(MLWParser::IdentifierExprContext *ctx) {
    if (inCallExpr) return;
    std::string varName = ctx->identifier()->getText();
    auto it = symbolTable.find(varName);
    if (it != symbolTable.end()) {
        pushValue(it->second);
    } else {
        llvm::errs() << "Undefined variable: " << varName;
    }
}


void LLVMGen::exitVarDeclWithInit(MLWParser::VarDeclWithInitContext *ctx) {
  std::string varName = ctx->identifier()->getText();

  // Get the initialization value from stack
  if (valueStacks.top().empty()) {
    llvm::errs() << "No value for variable initialization: " << varName;
    return;
  }

  auto initValue = popValue();
  symbolTable[varName] = initValue;

  pushValue(initValue);
}

void LLVMGen::enterVarDeclWithoutInit(MLWParser::VarDeclWithoutInitContext *ctx) {
    std::string varName = ctx->identifier()->getText();
    auto type = getType(ctx->type()->getText());

    // Create a default value
    auto defaultVal = llvm::ConstantInt::get(type, 0);

    symbolTable[varName] = defaultVal;
    pushValue(defaultVal);
}