
// Generated from MLW.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "MLWListener.h"


/**
 * This class provides an empty implementation of MLWListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  MLWBaseListener : public MLWListener {
public:

  virtual void enterProgram(MLWParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(MLWParser::ProgramContext * /*ctx*/) override { }

  virtual void enterImportStatement(MLWParser::ImportStatementContext * /*ctx*/) override { }
  virtual void exitImportStatement(MLWParser::ImportStatementContext * /*ctx*/) override { }

  virtual void enterExternStatement(MLWParser::ExternStatementContext * /*ctx*/) override { }
  virtual void exitExternStatement(MLWParser::ExternStatementContext * /*ctx*/) override { }

  virtual void enterFunctionDefinition(MLWParser::FunctionDefinitionContext * /*ctx*/) override { }
  virtual void exitFunctionDefinition(MLWParser::FunctionDefinitionContext * /*ctx*/) override { }

  virtual void enterParameterList(MLWParser::ParameterListContext * /*ctx*/) override { }
  virtual void exitParameterList(MLWParser::ParameterListContext * /*ctx*/) override { }

  virtual void enterParameter(MLWParser::ParameterContext * /*ctx*/) override { }
  virtual void exitParameter(MLWParser::ParameterContext * /*ctx*/) override { }

  virtual void enterParameterList_typeonly(MLWParser::ParameterList_typeonlyContext * /*ctx*/) override { }
  virtual void exitParameterList_typeonly(MLWParser::ParameterList_typeonlyContext * /*ctx*/) override { }

  virtual void enterParameter_typeonly(MLWParser::Parameter_typeonlyContext * /*ctx*/) override { }
  virtual void exitParameter_typeonly(MLWParser::Parameter_typeonlyContext * /*ctx*/) override { }

  virtual void enterType(MLWParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(MLWParser::TypeContext * /*ctx*/) override { }

  virtual void enterInt32Type(MLWParser::Int32TypeContext * /*ctx*/) override { }
  virtual void exitInt32Type(MLWParser::Int32TypeContext * /*ctx*/) override { }

  virtual void enterInt64Type(MLWParser::Int64TypeContext * /*ctx*/) override { }
  virtual void exitInt64Type(MLWParser::Int64TypeContext * /*ctx*/) override { }

  virtual void enterFloat32Type(MLWParser::Float32TypeContext * /*ctx*/) override { }
  virtual void exitFloat32Type(MLWParser::Float32TypeContext * /*ctx*/) override { }

  virtual void enterFloat64Type(MLWParser::Float64TypeContext * /*ctx*/) override { }
  virtual void exitFloat64Type(MLWParser::Float64TypeContext * /*ctx*/) override { }

  virtual void enterStringType(MLWParser::StringTypeContext * /*ctx*/) override { }
  virtual void exitStringType(MLWParser::StringTypeContext * /*ctx*/) override { }

  virtual void enterBoolType(MLWParser::BoolTypeContext * /*ctx*/) override { }
  virtual void exitBoolType(MLWParser::BoolTypeContext * /*ctx*/) override { }

  virtual void enterVoidType(MLWParser::VoidTypeContext * /*ctx*/) override { }
  virtual void exitVoidType(MLWParser::VoidTypeContext * /*ctx*/) override { }

  virtual void enterBlock(MLWParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(MLWParser::BlockContext * /*ctx*/) override { }

  virtual void enterVarDeclStatement(MLWParser::VarDeclStatementContext * /*ctx*/) override { }
  virtual void exitVarDeclStatement(MLWParser::VarDeclStatementContext * /*ctx*/) override { }

  virtual void enterAssignmentStatement(MLWParser::AssignmentStatementContext * /*ctx*/) override { }
  virtual void exitAssignmentStatement(MLWParser::AssignmentStatementContext * /*ctx*/) override { }

  virtual void enterExprStatement(MLWParser::ExprStatementContext * /*ctx*/) override { }
  virtual void exitExprStatement(MLWParser::ExprStatementContext * /*ctx*/) override { }

  virtual void enterReturnStatement(MLWParser::ReturnStatementContext * /*ctx*/) override { }
  virtual void exitReturnStatement(MLWParser::ReturnStatementContext * /*ctx*/) override { }

  virtual void enterIfStatement(MLWParser::IfStatementContext * /*ctx*/) override { }
  virtual void exitIfStatement(MLWParser::IfStatementContext * /*ctx*/) override { }

  virtual void enterWhileStatement(MLWParser::WhileStatementContext * /*ctx*/) override { }
  virtual void exitWhileStatement(MLWParser::WhileStatementContext * /*ctx*/) override { }

  virtual void enterBlockStatement(MLWParser::BlockStatementContext * /*ctx*/) override { }
  virtual void exitBlockStatement(MLWParser::BlockStatementContext * /*ctx*/) override { }

  virtual void enterVarDeclWithInit(MLWParser::VarDeclWithInitContext * /*ctx*/) override { }
  virtual void exitVarDeclWithInit(MLWParser::VarDeclWithInitContext * /*ctx*/) override { }

  virtual void enterVarDeclWithoutInit(MLWParser::VarDeclWithoutInitContext * /*ctx*/) override { }
  virtual void exitVarDeclWithoutInit(MLWParser::VarDeclWithoutInitContext * /*ctx*/) override { }

  virtual void enterSimpleAssignment(MLWParser::SimpleAssignmentContext * /*ctx*/) override { }
  virtual void exitSimpleAssignment(MLWParser::SimpleAssignmentContext * /*ctx*/) override { }

  virtual void enterCompoundAssignment(MLWParser::CompoundAssignmentContext * /*ctx*/) override { }
  virtual void exitCompoundAssignment(MLWParser::CompoundAssignmentContext * /*ctx*/) override { }

  virtual void enterRetStmt(MLWParser::RetStmtContext * /*ctx*/) override { }
  virtual void exitRetStmt(MLWParser::RetStmtContext * /*ctx*/) override { }

  virtual void enterIfStmt(MLWParser::IfStmtContext * /*ctx*/) override { }
  virtual void exitIfStmt(MLWParser::IfStmtContext * /*ctx*/) override { }

  virtual void enterWhileStmt(MLWParser::WhileStmtContext * /*ctx*/) override { }
  virtual void exitWhileStmt(MLWParser::WhileStmtContext * /*ctx*/) override { }

  virtual void enterLiteralExpr(MLWParser::LiteralExprContext * /*ctx*/) override { }
  virtual void exitLiteralExpr(MLWParser::LiteralExprContext * /*ctx*/) override { }

  virtual void enterIdentifierExpr(MLWParser::IdentifierExprContext * /*ctx*/) override { }
  virtual void exitIdentifierExpr(MLWParser::IdentifierExprContext * /*ctx*/) override { }

  virtual void enterParenExpr(MLWParser::ParenExprContext * /*ctx*/) override { }
  virtual void exitParenExpr(MLWParser::ParenExprContext * /*ctx*/) override { }

  virtual void enterSubscriptExpr(MLWParser::SubscriptExprContext * /*ctx*/) override { }
  virtual void exitSubscriptExpr(MLWParser::SubscriptExprContext * /*ctx*/) override { }

  virtual void enterPrimaryPostfix(MLWParser::PrimaryPostfixContext * /*ctx*/) override { }
  virtual void exitPrimaryPostfix(MLWParser::PrimaryPostfixContext * /*ctx*/) override { }

  virtual void enterCallExpr(MLWParser::CallExprContext * /*ctx*/) override { }
  virtual void exitCallExpr(MLWParser::CallExprContext * /*ctx*/) override { }

  virtual void enterMemberAccessExpr(MLWParser::MemberAccessExprContext * /*ctx*/) override { }
  virtual void exitMemberAccessExpr(MLWParser::MemberAccessExprContext * /*ctx*/) override { }

  virtual void enterPostfixExpr(MLWParser::PostfixExprContext * /*ctx*/) override { }
  virtual void exitPostfixExpr(MLWParser::PostfixExprContext * /*ctx*/) override { }

  virtual void enterMultiplicativeExpr(MLWParser::MultiplicativeExprContext * /*ctx*/) override { }
  virtual void exitMultiplicativeExpr(MLWParser::MultiplicativeExprContext * /*ctx*/) override { }

  virtual void enterLogicalOrExpr(MLWParser::LogicalOrExprContext * /*ctx*/) override { }
  virtual void exitLogicalOrExpr(MLWParser::LogicalOrExprContext * /*ctx*/) override { }

  virtual void enterEqualityExpr(MLWParser::EqualityExprContext * /*ctx*/) override { }
  virtual void exitEqualityExpr(MLWParser::EqualityExprContext * /*ctx*/) override { }

  virtual void enterAdditiveExpr(MLWParser::AdditiveExprContext * /*ctx*/) override { }
  virtual void exitAdditiveExpr(MLWParser::AdditiveExprContext * /*ctx*/) override { }

  virtual void enterRelationalExpr(MLWParser::RelationalExprContext * /*ctx*/) override { }
  virtual void exitRelationalExpr(MLWParser::RelationalExprContext * /*ctx*/) override { }

  virtual void enterUnaryExpr(MLWParser::UnaryExprContext * /*ctx*/) override { }
  virtual void exitUnaryExpr(MLWParser::UnaryExprContext * /*ctx*/) override { }

  virtual void enterLogicalAndExpr(MLWParser::LogicalAndExprContext * /*ctx*/) override { }
  virtual void exitLogicalAndExpr(MLWParser::LogicalAndExprContext * /*ctx*/) override { }

  virtual void enterArgumentList(MLWParser::ArgumentListContext * /*ctx*/) override { }
  virtual void exitArgumentList(MLWParser::ArgumentListContext * /*ctx*/) override { }

  virtual void enterIntLiteral(MLWParser::IntLiteralContext * /*ctx*/) override { }
  virtual void exitIntLiteral(MLWParser::IntLiteralContext * /*ctx*/) override { }

  virtual void enterFloatLiteral(MLWParser::FloatLiteralContext * /*ctx*/) override { }
  virtual void exitFloatLiteral(MLWParser::FloatLiteralContext * /*ctx*/) override { }

  virtual void enterStringLiteral(MLWParser::StringLiteralContext * /*ctx*/) override { }
  virtual void exitStringLiteral(MLWParser::StringLiteralContext * /*ctx*/) override { }

  virtual void enterBoolLiteral(MLWParser::BoolLiteralContext * /*ctx*/) override { }
  virtual void exitBoolLiteral(MLWParser::BoolLiteralContext * /*ctx*/) override { }

  virtual void enterIdentifier(MLWParser::IdentifierContext * /*ctx*/) override { }
  virtual void exitIdentifier(MLWParser::IdentifierContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

