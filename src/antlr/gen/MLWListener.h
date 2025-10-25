
// Generated from MLW.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "MLWParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by MLWParser.
 */
class  MLWListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(MLWParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(MLWParser::ProgramContext *ctx) = 0;

  virtual void enterImportStatement(MLWParser::ImportStatementContext *ctx) = 0;
  virtual void exitImportStatement(MLWParser::ImportStatementContext *ctx) = 0;

  virtual void enterExternStatement(MLWParser::ExternStatementContext *ctx) = 0;
  virtual void exitExternStatement(MLWParser::ExternStatementContext *ctx) = 0;

  virtual void enterFunctionDefinition(MLWParser::FunctionDefinitionContext *ctx) = 0;
  virtual void exitFunctionDefinition(MLWParser::FunctionDefinitionContext *ctx) = 0;

  virtual void enterParameterList(MLWParser::ParameterListContext *ctx) = 0;
  virtual void exitParameterList(MLWParser::ParameterListContext *ctx) = 0;

  virtual void enterParameter(MLWParser::ParameterContext *ctx) = 0;
  virtual void exitParameter(MLWParser::ParameterContext *ctx) = 0;

  virtual void enterParameterList_typeonly(MLWParser::ParameterList_typeonlyContext *ctx) = 0;
  virtual void exitParameterList_typeonly(MLWParser::ParameterList_typeonlyContext *ctx) = 0;

  virtual void enterParameter_typeonly(MLWParser::Parameter_typeonlyContext *ctx) = 0;
  virtual void exitParameter_typeonly(MLWParser::Parameter_typeonlyContext *ctx) = 0;

  virtual void enterType(MLWParser::TypeContext *ctx) = 0;
  virtual void exitType(MLWParser::TypeContext *ctx) = 0;

  virtual void enterInt32Type(MLWParser::Int32TypeContext *ctx) = 0;
  virtual void exitInt32Type(MLWParser::Int32TypeContext *ctx) = 0;

  virtual void enterInt64Type(MLWParser::Int64TypeContext *ctx) = 0;
  virtual void exitInt64Type(MLWParser::Int64TypeContext *ctx) = 0;

  virtual void enterFloat32Type(MLWParser::Float32TypeContext *ctx) = 0;
  virtual void exitFloat32Type(MLWParser::Float32TypeContext *ctx) = 0;

  virtual void enterFloat64Type(MLWParser::Float64TypeContext *ctx) = 0;
  virtual void exitFloat64Type(MLWParser::Float64TypeContext *ctx) = 0;

  virtual void enterStringType(MLWParser::StringTypeContext *ctx) = 0;
  virtual void exitStringType(MLWParser::StringTypeContext *ctx) = 0;

  virtual void enterBoolType(MLWParser::BoolTypeContext *ctx) = 0;
  virtual void exitBoolType(MLWParser::BoolTypeContext *ctx) = 0;

  virtual void enterVoidType(MLWParser::VoidTypeContext *ctx) = 0;
  virtual void exitVoidType(MLWParser::VoidTypeContext *ctx) = 0;

  virtual void enterBlock(MLWParser::BlockContext *ctx) = 0;
  virtual void exitBlock(MLWParser::BlockContext *ctx) = 0;

  virtual void enterVarDeclStatement(MLWParser::VarDeclStatementContext *ctx) = 0;
  virtual void exitVarDeclStatement(MLWParser::VarDeclStatementContext *ctx) = 0;

  virtual void enterAssignmentStatement(MLWParser::AssignmentStatementContext *ctx) = 0;
  virtual void exitAssignmentStatement(MLWParser::AssignmentStatementContext *ctx) = 0;

  virtual void enterExprStatement(MLWParser::ExprStatementContext *ctx) = 0;
  virtual void exitExprStatement(MLWParser::ExprStatementContext *ctx) = 0;

  virtual void enterReturnStatement(MLWParser::ReturnStatementContext *ctx) = 0;
  virtual void exitReturnStatement(MLWParser::ReturnStatementContext *ctx) = 0;

  virtual void enterIfStatement(MLWParser::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(MLWParser::IfStatementContext *ctx) = 0;

  virtual void enterWhileStatement(MLWParser::WhileStatementContext *ctx) = 0;
  virtual void exitWhileStatement(MLWParser::WhileStatementContext *ctx) = 0;

  virtual void enterBlockStatement(MLWParser::BlockStatementContext *ctx) = 0;
  virtual void exitBlockStatement(MLWParser::BlockStatementContext *ctx) = 0;

  virtual void enterVarDeclWithInit(MLWParser::VarDeclWithInitContext *ctx) = 0;
  virtual void exitVarDeclWithInit(MLWParser::VarDeclWithInitContext *ctx) = 0;

  virtual void enterVarDeclWithoutInit(MLWParser::VarDeclWithoutInitContext *ctx) = 0;
  virtual void exitVarDeclWithoutInit(MLWParser::VarDeclWithoutInitContext *ctx) = 0;

  virtual void enterSimpleAssignment(MLWParser::SimpleAssignmentContext *ctx) = 0;
  virtual void exitSimpleAssignment(MLWParser::SimpleAssignmentContext *ctx) = 0;

  virtual void enterCompoundAssignment(MLWParser::CompoundAssignmentContext *ctx) = 0;
  virtual void exitCompoundAssignment(MLWParser::CompoundAssignmentContext *ctx) = 0;

  virtual void enterRetStmt(MLWParser::RetStmtContext *ctx) = 0;
  virtual void exitRetStmt(MLWParser::RetStmtContext *ctx) = 0;

  virtual void enterIfStmt(MLWParser::IfStmtContext *ctx) = 0;
  virtual void exitIfStmt(MLWParser::IfStmtContext *ctx) = 0;

  virtual void enterWhileStmt(MLWParser::WhileStmtContext *ctx) = 0;
  virtual void exitWhileStmt(MLWParser::WhileStmtContext *ctx) = 0;

  virtual void enterLiteralExpr(MLWParser::LiteralExprContext *ctx) = 0;
  virtual void exitLiteralExpr(MLWParser::LiteralExprContext *ctx) = 0;

  virtual void enterIdentifierExpr(MLWParser::IdentifierExprContext *ctx) = 0;
  virtual void exitIdentifierExpr(MLWParser::IdentifierExprContext *ctx) = 0;

  virtual void enterParenExpr(MLWParser::ParenExprContext *ctx) = 0;
  virtual void exitParenExpr(MLWParser::ParenExprContext *ctx) = 0;

  virtual void enterSubscriptExpr(MLWParser::SubscriptExprContext *ctx) = 0;
  virtual void exitSubscriptExpr(MLWParser::SubscriptExprContext *ctx) = 0;

  virtual void enterPrimaryPostfix(MLWParser::PrimaryPostfixContext *ctx) = 0;
  virtual void exitPrimaryPostfix(MLWParser::PrimaryPostfixContext *ctx) = 0;

  virtual void enterCallExpr(MLWParser::CallExprContext *ctx) = 0;
  virtual void exitCallExpr(MLWParser::CallExprContext *ctx) = 0;

  virtual void enterMemberAccessExpr(MLWParser::MemberAccessExprContext *ctx) = 0;
  virtual void exitMemberAccessExpr(MLWParser::MemberAccessExprContext *ctx) = 0;

  virtual void enterPostfixExpr(MLWParser::PostfixExprContext *ctx) = 0;
  virtual void exitPostfixExpr(MLWParser::PostfixExprContext *ctx) = 0;

  virtual void enterMultiplicativeExpr(MLWParser::MultiplicativeExprContext *ctx) = 0;
  virtual void exitMultiplicativeExpr(MLWParser::MultiplicativeExprContext *ctx) = 0;

  virtual void enterLogicalOrExpr(MLWParser::LogicalOrExprContext *ctx) = 0;
  virtual void exitLogicalOrExpr(MLWParser::LogicalOrExprContext *ctx) = 0;

  virtual void enterEqualityExpr(MLWParser::EqualityExprContext *ctx) = 0;
  virtual void exitEqualityExpr(MLWParser::EqualityExprContext *ctx) = 0;

  virtual void enterAdditiveExpr(MLWParser::AdditiveExprContext *ctx) = 0;
  virtual void exitAdditiveExpr(MLWParser::AdditiveExprContext *ctx) = 0;

  virtual void enterRelationalExpr(MLWParser::RelationalExprContext *ctx) = 0;
  virtual void exitRelationalExpr(MLWParser::RelationalExprContext *ctx) = 0;

  virtual void enterUnaryExpr(MLWParser::UnaryExprContext *ctx) = 0;
  virtual void exitUnaryExpr(MLWParser::UnaryExprContext *ctx) = 0;

  virtual void enterLogicalAndExpr(MLWParser::LogicalAndExprContext *ctx) = 0;
  virtual void exitLogicalAndExpr(MLWParser::LogicalAndExprContext *ctx) = 0;

  virtual void enterArgumentList(MLWParser::ArgumentListContext *ctx) = 0;
  virtual void exitArgumentList(MLWParser::ArgumentListContext *ctx) = 0;

  virtual void enterIntLiteral(MLWParser::IntLiteralContext *ctx) = 0;
  virtual void exitIntLiteral(MLWParser::IntLiteralContext *ctx) = 0;

  virtual void enterFloatLiteral(MLWParser::FloatLiteralContext *ctx) = 0;
  virtual void exitFloatLiteral(MLWParser::FloatLiteralContext *ctx) = 0;

  virtual void enterStringLiteral(MLWParser::StringLiteralContext *ctx) = 0;
  virtual void exitStringLiteral(MLWParser::StringLiteralContext *ctx) = 0;

  virtual void enterBoolLiteral(MLWParser::BoolLiteralContext *ctx) = 0;
  virtual void exitBoolLiteral(MLWParser::BoolLiteralContext *ctx) = 0;

  virtual void enterIdentifier(MLWParser::IdentifierContext *ctx) = 0;
  virtual void exitIdentifier(MLWParser::IdentifierContext *ctx) = 0;


};

