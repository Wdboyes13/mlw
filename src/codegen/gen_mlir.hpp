#include <string>

#include <stack>
#include <map>

#include <MLWParser.h>
#include <MLWBaseListener.h>

#include <mlir/IR/Builders.h>
#include <mlir/IR/MLIRContext.h>
#include <mlir/IR/BuiltinOps.h>
#include <mlir/IR/Operation.h>
#include <mlir/Dialect/Func/IR/FuncOps.h>
#include <mlir/Dialect/Arith/IR/Arith.h>

using namespace mlir;

class MLIRGen : public MLWBaseListener {
    public:
        MLIRGen(MLIRContext* ctx);
        ModuleOp getModule() { return module; }

          // Override key listener methods
        void enterProgram(MLWParser::ProgramContext *ctx) override;
        void exitProgram(MLWParser::ProgramContext *ctx) override;
        
        void enterFunctionDefinition(MLWParser::FunctionDefinitionContext *ctx) override;
        void exitFunctionDefinition(MLWParser::FunctionDefinitionContext *ctx) override;
        
        void exitVarDeclWithInit(MLWParser::VarDeclWithInitContext *ctx) override;
        void enterVarDeclWithoutInit(MLWParser::VarDeclWithoutInitContext *ctx) override;
        
        void exitRetStmt(MLWParser::RetStmtContext *ctx) override;

        void enterCallExpr(MLWParser::CallExprContext *ctx) override;
        void exitCallExpr(MLWParser::CallExprContext *ctx) override;

        void exitIntLiteral(MLWParser::IntLiteralContext *ctx) override;
        void exitStringLiteral(MLWParser::StringLiteralContext *ctx) override;
        void exitBoolLiteral(MLWParser::BoolLiteralContext *ctx) override;
        
        void enterIdentifierExpr(MLWParser::IdentifierExprContext *ctx) override;
        
        void enterAdditiveExpr(MLWParser::AdditiveExprContext *ctx) override;
        void exitAdditiveExpr(MLWParser::AdditiveExprContext *ctx) override;
        
        void enterMultiplicativeExpr(MLWParser::MultiplicativeExprContext *ctx) override;
        void exitMultiplicativeExpr(MLWParser::MultiplicativeExprContext *ctx) override;

        void enterImportStatement(MLWParser::ImportStatementContext *ctx) override;

        void enterExternStatement(MLWParser::ExternStatementContext *ctx) override;

        void exitExprStatement(MLWParser::ExprStatementContext *ctx) override;
    private:
        MLIRContext* ctx;
        OpBuilder builder;
        ModuleOp module;

        std::map<std::string, Value> symbolTable;
        std::stack<std::stack<Value>> valueStacks;
        std::stack<std::string> operatorStack;
        func::FuncOp currentFunction;

        std::vector<Attribute> libs;
        bool inCallExpr;
        // Helper methods
        Type getType(const std::string& typeName);
        Location getLoc() { return builder.getUnknownLoc(); }
        Value popValue();
        void pushValue(Value value);

        struct InsertionPoint {
            Block* block;
            Block::iterator iterator;
        };
        std::vector<InsertionPoint> insertionStack;
        Block* previousInsertionBlock = nullptr;

    void debugValueStacks(const char* location) {
        llvm::errs() << "=== VALUE STACKS at " << location << " ===\n";
        llvm::errs() << "Number of value stacks: " << valueStacks.size() << "\n";

        if (valueStacks.empty()) {
            llvm::errs() << "NO ACTIVE VALUE STACK!\n";
            return;
        }

        auto& currentStack = valueStacks.top();
        llvm::errs() << "Current stack size: " << currentStack.size() << "\n";

        // Copy and print current stack contents
        std::vector<Value> temp;
        while (!currentStack.empty()) {
            temp.push_back(currentStack.top());
            currentStack.pop();
        }

        for (int i = temp.size() - 1; i >= 0; --i) {
            llvm::errs() << "  Stack[" << i << "]: " << temp[i];
            if (auto* op = temp[i].getDefiningOp()) {
                llvm::errs() << " (from " << op->getName() << ")";
            }
            llvm::errs() << "\n";
            currentStack.push(temp[i]);
        }
        llvm::errs() << "========================\n";
    }
};