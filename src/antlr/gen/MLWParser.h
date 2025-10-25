
// Generated from MLW.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  MLWParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, T__27 = 28, T__28 = 29, T__29 = 30, T__30 = 31, T__31 = 32, 
    T__32 = 33, T__33 = 34, T__34 = 35, T__35 = 36, T__36 = 37, T__37 = 38, 
    T__38 = 39, T__39 = 40, T__40 = 41, T__41 = 42, T__42 = 43, T__43 = 44, 
    T__44 = 45, T__45 = 46, IntegerLiteral = 47, FloatLiteral = 48, StringLiteral = 49, 
    BooleanLiteral = 50, Identifier = 51, WS = 52, LINE_COMMENT = 53, BLOCK_COMMENT = 54
  };

  enum {
    RuleProgram = 0, RuleLinkerstatement = 1, RuleFunctionDefinition = 2, 
    RuleParameterList = 3, RuleParameter = 4, RuleParameterList_typeonly = 5, 
    RuleParameter_typeonly = 6, RuleType = 7, RulePrimitiveType = 8, RuleBlock = 9, 
    RuleStatement = 10, RuleVariableDeclaration = 11, RuleAssignment = 12, 
    RuleRetStmt = 13, RuleIfStmt = 14, RuleWhileStmt = 15, RulePrimaryExpression = 16, 
    RulePostfixExpression = 17, RuleExpression = 18, RuleArgumentList = 19, 
    RuleLiteral = 20, RuleIdentifier = 21
  };

  explicit MLWParser(antlr4::TokenStream *input);

  MLWParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~MLWParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProgramContext;
  class LinkerstatementContext;
  class FunctionDefinitionContext;
  class ParameterListContext;
  class ParameterContext;
  class ParameterList_typeonlyContext;
  class Parameter_typeonlyContext;
  class TypeContext;
  class PrimitiveTypeContext;
  class BlockContext;
  class StatementContext;
  class VariableDeclarationContext;
  class AssignmentContext;
  class RetStmtContext;
  class IfStmtContext;
  class WhileStmtContext;
  class PrimaryExpressionContext;
  class PostfixExpressionContext;
  class ExpressionContext;
  class ArgumentListContext;
  class LiteralContext;
  class IdentifierContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<LinkerstatementContext *> linkerstatement();
    LinkerstatementContext* linkerstatement(size_t i);
    std::vector<FunctionDefinitionContext *> functionDefinition();
    FunctionDefinitionContext* functionDefinition(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ProgramContext* program();

  class  LinkerstatementContext : public antlr4::ParserRuleContext {
  public:
    LinkerstatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    LinkerstatementContext() = default;
    void copyFrom(LinkerstatementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ExternStatementContext : public LinkerstatementContext {
  public:
    ExternStatementContext(LinkerstatementContext *ctx);

    IdentifierContext *identifier();
    TypeContext *type();
    ParameterList_typeonlyContext *parameterList_typeonly();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  ImportStatementContext : public LinkerstatementContext {
  public:
    ImportStatementContext(LinkerstatementContext *ctx);

    IdentifierContext *identifier();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  LinkerstatementContext* linkerstatement();

  class  FunctionDefinitionContext : public antlr4::ParserRuleContext {
  public:
    FunctionDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    TypeContext *type();
    BlockContext *block();
    ParameterListContext *parameterList();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FunctionDefinitionContext* functionDefinition();

  class  ParameterListContext : public antlr4::ParserRuleContext {
  public:
    ParameterListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ParameterContext *> parameter();
    ParameterContext* parameter(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ParameterListContext* parameterList();

  class  ParameterContext : public antlr4::ParserRuleContext {
  public:
    ParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    TypeContext *type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ParameterContext* parameter();

  class  ParameterList_typeonlyContext : public antlr4::ParserRuleContext {
  public:
    ParameterList_typeonlyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Parameter_typeonlyContext *> parameter_typeonly();
    Parameter_typeonlyContext* parameter_typeonly(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ParameterList_typeonlyContext* parameterList_typeonly();

  class  Parameter_typeonlyContext : public antlr4::ParserRuleContext {
  public:
    Parameter_typeonlyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Parameter_typeonlyContext* parameter_typeonly();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PrimitiveTypeContext *primitiveType();
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TypeContext* type();

  class  PrimitiveTypeContext : public antlr4::ParserRuleContext {
  public:
    PrimitiveTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    PrimitiveTypeContext() = default;
    void copyFrom(PrimitiveTypeContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Float32TypeContext : public PrimitiveTypeContext {
  public:
    Float32TypeContext(PrimitiveTypeContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  VoidTypeContext : public PrimitiveTypeContext {
  public:
    VoidTypeContext(PrimitiveTypeContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  BoolTypeContext : public PrimitiveTypeContext {
  public:
    BoolTypeContext(PrimitiveTypeContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Float64TypeContext : public PrimitiveTypeContext {
  public:
    Float64TypeContext(PrimitiveTypeContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Int64TypeContext : public PrimitiveTypeContext {
  public:
    Int64TypeContext(PrimitiveTypeContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  StringTypeContext : public PrimitiveTypeContext {
  public:
    StringTypeContext(PrimitiveTypeContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Int32TypeContext : public PrimitiveTypeContext {
  public:
    Int32TypeContext(PrimitiveTypeContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  PrimitiveTypeContext* primitiveType();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BlockContext* block();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StatementContext() = default;
    void copyFrom(StatementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  IfStatementContext : public StatementContext {
  public:
    IfStatementContext(StatementContext *ctx);

    IfStmtContext *ifStmt();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  AssignmentStatementContext : public StatementContext {
  public:
    AssignmentStatementContext(StatementContext *ctx);

    AssignmentContext *assignment();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  ExprStatementContext : public StatementContext {
  public:
    ExprStatementContext(StatementContext *ctx);

    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  ReturnStatementContext : public StatementContext {
  public:
    ReturnStatementContext(StatementContext *ctx);

    RetStmtContext *retStmt();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  BlockStatementContext : public StatementContext {
  public:
    BlockStatementContext(StatementContext *ctx);

    BlockContext *block();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  WhileStatementContext : public StatementContext {
  public:
    WhileStatementContext(StatementContext *ctx);

    WhileStmtContext *whileStmt();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  VarDeclStatementContext : public StatementContext {
  public:
    VarDeclStatementContext(StatementContext *ctx);

    VariableDeclarationContext *variableDeclaration();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  StatementContext* statement();

  class  VariableDeclarationContext : public antlr4::ParserRuleContext {
  public:
    VariableDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    VariableDeclarationContext() = default;
    void copyFrom(VariableDeclarationContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  VarDeclWithoutInitContext : public VariableDeclarationContext {
  public:
    VarDeclWithoutInitContext(VariableDeclarationContext *ctx);

    IdentifierContext *identifier();
    TypeContext *type();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  VarDeclWithInitContext : public VariableDeclarationContext {
  public:
    VarDeclWithInitContext(VariableDeclarationContext *ctx);

    IdentifierContext *identifier();
    ExpressionContext *expression();
    TypeContext *type();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  VariableDeclarationContext* variableDeclaration();

  class  AssignmentContext : public antlr4::ParserRuleContext {
  public:
    AssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    AssignmentContext() = default;
    void copyFrom(AssignmentContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SimpleAssignmentContext : public AssignmentContext {
  public:
    SimpleAssignmentContext(AssignmentContext *ctx);

    IdentifierContext *identifier();
    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  CompoundAssignmentContext : public AssignmentContext {
  public:
    CompoundAssignmentContext(AssignmentContext *ctx);

    antlr4::Token *op = nullptr;
    IdentifierContext *identifier();
    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  AssignmentContext* assignment();

  class  RetStmtContext : public antlr4::ParserRuleContext {
  public:
    RetStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RetStmtContext* retStmt();

  class  IfStmtContext : public antlr4::ParserRuleContext {
  public:
    IfStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IfStmtContext* ifStmt();

  class  WhileStmtContext : public antlr4::ParserRuleContext {
  public:
    WhileStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    BlockContext *block();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  WhileStmtContext* whileStmt();

  class  PrimaryExpressionContext : public antlr4::ParserRuleContext {
  public:
    PrimaryExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    PrimaryExpressionContext() = default;
    void copyFrom(PrimaryExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  IdentifierExprContext : public PrimaryExpressionContext {
  public:
    IdentifierExprContext(PrimaryExpressionContext *ctx);

    IdentifierContext *identifier();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  LiteralExprContext : public PrimaryExpressionContext {
  public:
    LiteralExprContext(PrimaryExpressionContext *ctx);

    LiteralContext *literal();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  ParenExprContext : public PrimaryExpressionContext {
  public:
    ParenExprContext(PrimaryExpressionContext *ctx);

    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  PrimaryExpressionContext* primaryExpression();

  class  PostfixExpressionContext : public antlr4::ParserRuleContext {
  public:
    PostfixExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    PostfixExpressionContext() = default;
    void copyFrom(PostfixExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SubscriptExprContext : public PostfixExpressionContext {
  public:
    SubscriptExprContext(PostfixExpressionContext *ctx);

    PostfixExpressionContext *postfixExpression();
    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  PrimaryPostfixContext : public PostfixExpressionContext {
  public:
    PrimaryPostfixContext(PostfixExpressionContext *ctx);

    PrimaryExpressionContext *primaryExpression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  CallExprContext : public PostfixExpressionContext {
  public:
    CallExprContext(PostfixExpressionContext *ctx);

    PostfixExpressionContext *postfixExpression();
    ArgumentListContext *argumentList();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  MemberAccessExprContext : public PostfixExpressionContext {
  public:
    MemberAccessExprContext(PostfixExpressionContext *ctx);

    PostfixExpressionContext *postfixExpression();
    IdentifierContext *identifier();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  PostfixExpressionContext* postfixExpression();
  PostfixExpressionContext* postfixExpression(int precedence);
  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpressionContext() = default;
    void copyFrom(ExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  PostfixExprContext : public ExpressionContext {
  public:
    PostfixExprContext(ExpressionContext *ctx);

    PostfixExpressionContext *postfixExpression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  MultiplicativeExprContext : public ExpressionContext {
  public:
    MultiplicativeExprContext(ExpressionContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  LogicalOrExprContext : public ExpressionContext {
  public:
    LogicalOrExprContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  EqualityExprContext : public ExpressionContext {
  public:
    EqualityExprContext(ExpressionContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  AdditiveExprContext : public ExpressionContext {
  public:
    AdditiveExprContext(ExpressionContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  RelationalExprContext : public ExpressionContext {
  public:
    RelationalExprContext(ExpressionContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  UnaryExprContext : public ExpressionContext {
  public:
    UnaryExprContext(ExpressionContext *ctx);

    antlr4::Token *op = nullptr;
    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  LogicalAndExprContext : public ExpressionContext {
  public:
    LogicalAndExprContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  ArgumentListContext : public antlr4::ParserRuleContext {
  public:
    ArgumentListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ArgumentListContext* argumentList();

  class  LiteralContext : public antlr4::ParserRuleContext {
  public:
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    LiteralContext() = default;
    void copyFrom(LiteralContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  StringLiteralContext : public LiteralContext {
  public:
    StringLiteralContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *StringLiteral();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  BoolLiteralContext : public LiteralContext {
  public:
    BoolLiteralContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *BooleanLiteral();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  FloatLiteralContext : public LiteralContext {
  public:
    FloatLiteralContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *FloatLiteral();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  IntLiteralContext : public LiteralContext {
  public:
    IntLiteralContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *IntegerLiteral();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  LiteralContext* literal();

  class  IdentifierContext : public antlr4::ParserRuleContext {
  public:
    IdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IdentifierContext* identifier();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool postfixExpressionSempred(PostfixExpressionContext *_localctx, size_t predicateIndex);
  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

