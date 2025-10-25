#include "../gen_mlir.hpp"

#include <MLWLexer.h>
#include <MLWParser.h>

using namespace mlir;
using namespace antlr4;

#define def_mlg_fctx(method_name) void MLIRGen::method_name(MLWParser::FunctionDefinitionContext* ctx)

def_mlg_fctx(enterFunctionDefinition) {
    valueStacks.push(std::stack<Value>());
    // Save the current insertion point
    InsertionPoint savedPoint;
    savedPoint.block = builder.getInsertionBlock();
    if (savedPoint.block) {
        savedPoint.iterator = builder.getInsertionPoint();
        insertionStack.push_back(savedPoint);
    }
    
    // Create the function at module level
    builder.setInsertionPointToEnd(&module.getBodyRegion().front());
    
    std::string fn_name = ctx->identifier()->getText();
    symbolTable.clear();
    std::vector<Type> paramTypes;
    if (auto paramList = ctx->parameterList()) {
        for (auto param : paramList->parameter()) {
            auto typeName = param->type()->getText();
            paramTypes.push_back(getType(typeName));
        }
    }

    auto returnType = getType(ctx->type()->getText());
    auto fn_type = builder.getFunctionType(paramTypes, returnType);

    currentFunction = builder.create<func::FuncOp>(getLoc(), fn_name, fn_type);

    auto* entry_block = currentFunction.addEntryBlock();
    builder.setInsertionPointToStart(entry_block);

    if (auto paramList = ctx->parameterList()) {
        size_t i = 0;
        for (auto param : paramList->parameter()) {
            std::string paramName = param->identifier()->getText();
            symbolTable[paramName] = entry_block->getArgument(i++);
        }
    }
}

def_mlg_fctx(exitFunctionDefinition) {

    // Restore previous insertion point
    if (!insertionStack.empty()) {
        InsertionPoint savedPoint = insertionStack.back();
        insertionStack.pop_back();
        builder.setInsertionPoint(savedPoint.block, savedPoint.iterator);
    } else {
        // We were at module level, so go back to end of module
        builder.setInsertionPointToEnd(&module.getBodyRegion().front());
    }
    
    currentFunction = nullptr;
    if (!valueStacks.empty()) {
        valueStacks.pop();
    }
}


void MLIRGen::exitRetStmt(MLWParser::RetStmtContext *ctx) {
    if (ctx->expression()) {
        if (valueStacks.top().empty()) {
            // ✅ Create a proper default value instead of 0
            auto defaultVal = builder.create<arith::ConstantIntOp>(getLoc(), 0, builder.getI32Type());
            builder.create<func::ReturnOp>(getLoc(), defaultVal.getResult());
        } else {
            Value returnValue = popValue();
            builder.create<func::ReturnOp>(getLoc(), returnValue);
        }
    } else {
        // Void return
        builder.create<func::ReturnOp>(getLoc());
    }
}

void MLIRGen::enterCallExpr(MLWParser::CallExprContext *ctx) {
    inCallExpr = true;
}

void MLIRGen::exitCallExpr(MLWParser::CallExprContext *ctx) {
    std::string calleeName = ctx->postfixExpression()->getText();

    // Collect arguments from value stack
    std::vector<Value> args;

    // ✅ FIX: argumentList() returns a vector, not a single object
    MLWParser::ArgumentListContext* argLists = ctx->argumentList();
    if (!argLists->isEmpty()) {
        size_t argCount = argLists->expression().size();
        args.resize(argCount);

        // Pop arguments in reverse order
        for (int i = argCount - 1; i >= 0; --i) {
            if (valueStacks.top().empty()) {
                emitError(getLoc()) << "Not enough arguments for function call";
                return;
            }
            args[i] = popValue();
        }
    }

    // Look for the function
    auto func = module.lookupSymbol<func::FuncOp>(calleeName);
    if (!func) {
        emitError(getLoc()) << "Undefined function: " << calleeName;
        return;
    }

    auto callOp = builder.create<func::CallOp>(getLoc(), func, args);

    // ✅ FIX: Use mlir::isa instead of deprecated method
    if (callOp.getNumResults() > 0) {
        Value result = callOp.getResult(0);
        if (!mlir::isa<NoneType>(result.getType())) {
            pushValue(result);
        }
    }
    inCallExpr = false;
}