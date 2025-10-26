#include <string>

#include <stack>
#include <map>

#include <MLWParser.h>
#include <MLWBaseListener.h>

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Attributes.h>
#include <llvm/IR/BasicBlock.h>


class LLVMGen : public MLWBaseListener {
    public:
        LLVMGen(llvm::LLVMContext* ctx);
        auto getModule() { return std::move(_module); }

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
};