// Generated from /Users/william/coding/1/mlang/src/antlr/MLW.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link MLWParser}.
 */
public interface MLWListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link MLWParser#program}.
	 * @param ctx the parse tree
	 */
	void enterProgram(MLWParser.ProgramContext ctx);
	/**
	 * Exit a parse tree produced by {@link MLWParser#program}.
	 * @param ctx the parse tree
	 */
	void exitProgram(MLWParser.ProgramContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ImportStatement}
	 * labeled alternative in {@link MLWParser#linkerstatement}.
	 * @param ctx the parse tree
	 */
	void enterImportStatement(MLWParser.ImportStatementContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ImportStatement}
	 * labeled alternative in {@link MLWParser#linkerstatement}.
	 * @param ctx the parse tree
	 */
	void exitImportStatement(MLWParser.ImportStatementContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ExternStatement}
	 * labeled alternative in {@link MLWParser#linkerstatement}.
	 * @param ctx the parse tree
	 */
	void enterExternStatement(MLWParser.ExternStatementContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ExternStatement}
	 * labeled alternative in {@link MLWParser#linkerstatement}.
	 * @param ctx the parse tree
	 */
	void exitExternStatement(MLWParser.ExternStatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link MLWParser#functionDefinition}.
	 * @param ctx the parse tree
	 */
	void enterFunctionDefinition(MLWParser.FunctionDefinitionContext ctx);
	/**
	 * Exit a parse tree produced by {@link MLWParser#functionDefinition}.
	 * @param ctx the parse tree
	 */
	void exitFunctionDefinition(MLWParser.FunctionDefinitionContext ctx);
	/**
	 * Enter a parse tree produced by {@link MLWParser#parameterList}.
	 * @param ctx the parse tree
	 */
	void enterParameterList(MLWParser.ParameterListContext ctx);
	/**
	 * Exit a parse tree produced by {@link MLWParser#parameterList}.
	 * @param ctx the parse tree
	 */
	void exitParameterList(MLWParser.ParameterListContext ctx);
	/**
	 * Enter a parse tree produced by {@link MLWParser#parameter}.
	 * @param ctx the parse tree
	 */
	void enterParameter(MLWParser.ParameterContext ctx);
	/**
	 * Exit a parse tree produced by {@link MLWParser#parameter}.
	 * @param ctx the parse tree
	 */
	void exitParameter(MLWParser.ParameterContext ctx);
	/**
	 * Enter a parse tree produced by {@link MLWParser#parameterList_typeonly}.
	 * @param ctx the parse tree
	 */
	void enterParameterList_typeonly(MLWParser.ParameterList_typeonlyContext ctx);
	/**
	 * Exit a parse tree produced by {@link MLWParser#parameterList_typeonly}.
	 * @param ctx the parse tree
	 */
	void exitParameterList_typeonly(MLWParser.ParameterList_typeonlyContext ctx);
	/**
	 * Enter a parse tree produced by {@link MLWParser#parameter_typeonly}.
	 * @param ctx the parse tree
	 */
	void enterParameter_typeonly(MLWParser.Parameter_typeonlyContext ctx);
	/**
	 * Exit a parse tree produced by {@link MLWParser#parameter_typeonly}.
	 * @param ctx the parse tree
	 */
	void exitParameter_typeonly(MLWParser.Parameter_typeonlyContext ctx);
	/**
	 * Enter a parse tree produced by {@link MLWParser#type}.
	 * @param ctx the parse tree
	 */
	void enterType(MLWParser.TypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link MLWParser#type}.
	 * @param ctx the parse tree
	 */
	void exitType(MLWParser.TypeContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Int32Type}
	 * labeled alternative in {@link MLWParser#primitiveType}.
	 * @param ctx the parse tree
	 */
	void enterInt32Type(MLWParser.Int32TypeContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Int32Type}
	 * labeled alternative in {@link MLWParser#primitiveType}.
	 * @param ctx the parse tree
	 */
	void exitInt32Type(MLWParser.Int32TypeContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Int64Type}
	 * labeled alternative in {@link MLWParser#primitiveType}.
	 * @param ctx the parse tree
	 */
	void enterInt64Type(MLWParser.Int64TypeContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Int64Type}
	 * labeled alternative in {@link MLWParser#primitiveType}.
	 * @param ctx the parse tree
	 */
	void exitInt64Type(MLWParser.Int64TypeContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Float32Type}
	 * labeled alternative in {@link MLWParser#primitiveType}.
	 * @param ctx the parse tree
	 */
	void enterFloat32Type(MLWParser.Float32TypeContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Float32Type}
	 * labeled alternative in {@link MLWParser#primitiveType}.
	 * @param ctx the parse tree
	 */
	void exitFloat32Type(MLWParser.Float32TypeContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Float64Type}
	 * labeled alternative in {@link MLWParser#primitiveType}.
	 * @param ctx the parse tree
	 */
	void enterFloat64Type(MLWParser.Float64TypeContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Float64Type}
	 * labeled alternative in {@link MLWParser#primitiveType}.
	 * @param ctx the parse tree
	 */
	void exitFloat64Type(MLWParser.Float64TypeContext ctx);
	/**
	 * Enter a parse tree produced by the {@code StringType}
	 * labeled alternative in {@link MLWParser#primitiveType}.
	 * @param ctx the parse tree
	 */
	void enterStringType(MLWParser.StringTypeContext ctx);
	/**
	 * Exit a parse tree produced by the {@code StringType}
	 * labeled alternative in {@link MLWParser#primitiveType}.
	 * @param ctx the parse tree
	 */
	void exitStringType(MLWParser.StringTypeContext ctx);
	/**
	 * Enter a parse tree produced by the {@code BoolType}
	 * labeled alternative in {@link MLWParser#primitiveType}.
	 * @param ctx the parse tree
	 */
	void enterBoolType(MLWParser.BoolTypeContext ctx);
	/**
	 * Exit a parse tree produced by the {@code BoolType}
	 * labeled alternative in {@link MLWParser#primitiveType}.
	 * @param ctx the parse tree
	 */
	void exitBoolType(MLWParser.BoolTypeContext ctx);
	/**
	 * Enter a parse tree produced by the {@code VoidType}
	 * labeled alternative in {@link MLWParser#primitiveType}.
	 * @param ctx the parse tree
	 */
	void enterVoidType(MLWParser.VoidTypeContext ctx);
	/**
	 * Exit a parse tree produced by the {@code VoidType}
	 * labeled alternative in {@link MLWParser#primitiveType}.
	 * @param ctx the parse tree
	 */
	void exitVoidType(MLWParser.VoidTypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link MLWParser#block}.
	 * @param ctx the parse tree
	 */
	void enterBlock(MLWParser.BlockContext ctx);
	/**
	 * Exit a parse tree produced by {@link MLWParser#block}.
	 * @param ctx the parse tree
	 */
	void exitBlock(MLWParser.BlockContext ctx);
	/**
	 * Enter a parse tree produced by the {@code VarDeclStatement}
	 * labeled alternative in {@link MLWParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterVarDeclStatement(MLWParser.VarDeclStatementContext ctx);
	/**
	 * Exit a parse tree produced by the {@code VarDeclStatement}
	 * labeled alternative in {@link MLWParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitVarDeclStatement(MLWParser.VarDeclStatementContext ctx);
	/**
	 * Enter a parse tree produced by the {@code AssignmentStatement}
	 * labeled alternative in {@link MLWParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterAssignmentStatement(MLWParser.AssignmentStatementContext ctx);
	/**
	 * Exit a parse tree produced by the {@code AssignmentStatement}
	 * labeled alternative in {@link MLWParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitAssignmentStatement(MLWParser.AssignmentStatementContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ExprStatement}
	 * labeled alternative in {@link MLWParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterExprStatement(MLWParser.ExprStatementContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ExprStatement}
	 * labeled alternative in {@link MLWParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitExprStatement(MLWParser.ExprStatementContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ReturnStatement}
	 * labeled alternative in {@link MLWParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterReturnStatement(MLWParser.ReturnStatementContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ReturnStatement}
	 * labeled alternative in {@link MLWParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitReturnStatement(MLWParser.ReturnStatementContext ctx);
	/**
	 * Enter a parse tree produced by the {@code IfStatement}
	 * labeled alternative in {@link MLWParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterIfStatement(MLWParser.IfStatementContext ctx);
	/**
	 * Exit a parse tree produced by the {@code IfStatement}
	 * labeled alternative in {@link MLWParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitIfStatement(MLWParser.IfStatementContext ctx);
	/**
	 * Enter a parse tree produced by the {@code WhileStatement}
	 * labeled alternative in {@link MLWParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterWhileStatement(MLWParser.WhileStatementContext ctx);
	/**
	 * Exit a parse tree produced by the {@code WhileStatement}
	 * labeled alternative in {@link MLWParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitWhileStatement(MLWParser.WhileStatementContext ctx);
	/**
	 * Enter a parse tree produced by the {@code BlockStatement}
	 * labeled alternative in {@link MLWParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterBlockStatement(MLWParser.BlockStatementContext ctx);
	/**
	 * Exit a parse tree produced by the {@code BlockStatement}
	 * labeled alternative in {@link MLWParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitBlockStatement(MLWParser.BlockStatementContext ctx);
	/**
	 * Enter a parse tree produced by the {@code VarDeclWithInit}
	 * labeled alternative in {@link MLWParser#variableDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterVarDeclWithInit(MLWParser.VarDeclWithInitContext ctx);
	/**
	 * Exit a parse tree produced by the {@code VarDeclWithInit}
	 * labeled alternative in {@link MLWParser#variableDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitVarDeclWithInit(MLWParser.VarDeclWithInitContext ctx);
	/**
	 * Enter a parse tree produced by the {@code VarDeclWithoutInit}
	 * labeled alternative in {@link MLWParser#variableDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterVarDeclWithoutInit(MLWParser.VarDeclWithoutInitContext ctx);
	/**
	 * Exit a parse tree produced by the {@code VarDeclWithoutInit}
	 * labeled alternative in {@link MLWParser#variableDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitVarDeclWithoutInit(MLWParser.VarDeclWithoutInitContext ctx);
	/**
	 * Enter a parse tree produced by the {@code SimpleAssignment}
	 * labeled alternative in {@link MLWParser#assignment}.
	 * @param ctx the parse tree
	 */
	void enterSimpleAssignment(MLWParser.SimpleAssignmentContext ctx);
	/**
	 * Exit a parse tree produced by the {@code SimpleAssignment}
	 * labeled alternative in {@link MLWParser#assignment}.
	 * @param ctx the parse tree
	 */
	void exitSimpleAssignment(MLWParser.SimpleAssignmentContext ctx);
	/**
	 * Enter a parse tree produced by the {@code CompoundAssignment}
	 * labeled alternative in {@link MLWParser#assignment}.
	 * @param ctx the parse tree
	 */
	void enterCompoundAssignment(MLWParser.CompoundAssignmentContext ctx);
	/**
	 * Exit a parse tree produced by the {@code CompoundAssignment}
	 * labeled alternative in {@link MLWParser#assignment}.
	 * @param ctx the parse tree
	 */
	void exitCompoundAssignment(MLWParser.CompoundAssignmentContext ctx);
	/**
	 * Enter a parse tree produced by {@link MLWParser#retStmt}.
	 * @param ctx the parse tree
	 */
	void enterRetStmt(MLWParser.RetStmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link MLWParser#retStmt}.
	 * @param ctx the parse tree
	 */
	void exitRetStmt(MLWParser.RetStmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link MLWParser#ifStmt}.
	 * @param ctx the parse tree
	 */
	void enterIfStmt(MLWParser.IfStmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link MLWParser#ifStmt}.
	 * @param ctx the parse tree
	 */
	void exitIfStmt(MLWParser.IfStmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link MLWParser#whileStmt}.
	 * @param ctx the parse tree
	 */
	void enterWhileStmt(MLWParser.WhileStmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link MLWParser#whileStmt}.
	 * @param ctx the parse tree
	 */
	void exitWhileStmt(MLWParser.WhileStmtContext ctx);
	/**
	 * Enter a parse tree produced by the {@code SubscriptExpr}
	 * labeled alternative in {@link MLWParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterSubscriptExpr(MLWParser.SubscriptExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code SubscriptExpr}
	 * labeled alternative in {@link MLWParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitSubscriptExpr(MLWParser.SubscriptExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code RelationalExpr}
	 * labeled alternative in {@link MLWParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterRelationalExpr(MLWParser.RelationalExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code RelationalExpr}
	 * labeled alternative in {@link MLWParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitRelationalExpr(MLWParser.RelationalExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code UnaryExpr}
	 * labeled alternative in {@link MLWParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterUnaryExpr(MLWParser.UnaryExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code UnaryExpr}
	 * labeled alternative in {@link MLWParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitUnaryExpr(MLWParser.UnaryExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code LogicalAndExpr}
	 * labeled alternative in {@link MLWParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterLogicalAndExpr(MLWParser.LogicalAndExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code LogicalAndExpr}
	 * labeled alternative in {@link MLWParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitLogicalAndExpr(MLWParser.LogicalAndExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code MultiplicativeExpr}
	 * labeled alternative in {@link MLWParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterMultiplicativeExpr(MLWParser.MultiplicativeExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code MultiplicativeExpr}
	 * labeled alternative in {@link MLWParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitMultiplicativeExpr(MLWParser.MultiplicativeExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code LogicalOrExpr}
	 * labeled alternative in {@link MLWParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterLogicalOrExpr(MLWParser.LogicalOrExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code LogicalOrExpr}
	 * labeled alternative in {@link MLWParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitLogicalOrExpr(MLWParser.LogicalOrExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code EqualityExpr}
	 * labeled alternative in {@link MLWParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterEqualityExpr(MLWParser.EqualityExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code EqualityExpr}
	 * labeled alternative in {@link MLWParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitEqualityExpr(MLWParser.EqualityExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code AdditiveExpr}
	 * labeled alternative in {@link MLWParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterAdditiveExpr(MLWParser.AdditiveExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code AdditiveExpr}
	 * labeled alternative in {@link MLWParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitAdditiveExpr(MLWParser.AdditiveExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code IdentifierExpr}
	 * labeled alternative in {@link MLWParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterIdentifierExpr(MLWParser.IdentifierExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code IdentifierExpr}
	 * labeled alternative in {@link MLWParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitIdentifierExpr(MLWParser.IdentifierExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code LiteralExpr}
	 * labeled alternative in {@link MLWParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterLiteralExpr(MLWParser.LiteralExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code LiteralExpr}
	 * labeled alternative in {@link MLWParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitLiteralExpr(MLWParser.LiteralExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code CallExpr}
	 * labeled alternative in {@link MLWParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterCallExpr(MLWParser.CallExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code CallExpr}
	 * labeled alternative in {@link MLWParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitCallExpr(MLWParser.CallExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ParenExpr}
	 * labeled alternative in {@link MLWParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterParenExpr(MLWParser.ParenExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ParenExpr}
	 * labeled alternative in {@link MLWParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitParenExpr(MLWParser.ParenExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code MemberAccessExpr}
	 * labeled alternative in {@link MLWParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterMemberAccessExpr(MLWParser.MemberAccessExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code MemberAccessExpr}
	 * labeled alternative in {@link MLWParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitMemberAccessExpr(MLWParser.MemberAccessExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link MLWParser#argumentList}.
	 * @param ctx the parse tree
	 */
	void enterArgumentList(MLWParser.ArgumentListContext ctx);
	/**
	 * Exit a parse tree produced by {@link MLWParser#argumentList}.
	 * @param ctx the parse tree
	 */
	void exitArgumentList(MLWParser.ArgumentListContext ctx);
	/**
	 * Enter a parse tree produced by the {@code IntLiteral}
	 * labeled alternative in {@link MLWParser#literal}.
	 * @param ctx the parse tree
	 */
	void enterIntLiteral(MLWParser.IntLiteralContext ctx);
	/**
	 * Exit a parse tree produced by the {@code IntLiteral}
	 * labeled alternative in {@link MLWParser#literal}.
	 * @param ctx the parse tree
	 */
	void exitIntLiteral(MLWParser.IntLiteralContext ctx);
	/**
	 * Enter a parse tree produced by the {@code FloatLiteral}
	 * labeled alternative in {@link MLWParser#literal}.
	 * @param ctx the parse tree
	 */
	void enterFloatLiteral(MLWParser.FloatLiteralContext ctx);
	/**
	 * Exit a parse tree produced by the {@code FloatLiteral}
	 * labeled alternative in {@link MLWParser#literal}.
	 * @param ctx the parse tree
	 */
	void exitFloatLiteral(MLWParser.FloatLiteralContext ctx);
	/**
	 * Enter a parse tree produced by the {@code StringLiteral}
	 * labeled alternative in {@link MLWParser#literal}.
	 * @param ctx the parse tree
	 */
	void enterStringLiteral(MLWParser.StringLiteralContext ctx);
	/**
	 * Exit a parse tree produced by the {@code StringLiteral}
	 * labeled alternative in {@link MLWParser#literal}.
	 * @param ctx the parse tree
	 */
	void exitStringLiteral(MLWParser.StringLiteralContext ctx);
	/**
	 * Enter a parse tree produced by the {@code BoolLiteral}
	 * labeled alternative in {@link MLWParser#literal}.
	 * @param ctx the parse tree
	 */
	void enterBoolLiteral(MLWParser.BoolLiteralContext ctx);
	/**
	 * Exit a parse tree produced by the {@code BoolLiteral}
	 * labeled alternative in {@link MLWParser#literal}.
	 * @param ctx the parse tree
	 */
	void exitBoolLiteral(MLWParser.BoolLiteralContext ctx);
	/**
	 * Enter a parse tree produced by {@link MLWParser#identifier}.
	 * @param ctx the parse tree
	 */
	void enterIdentifier(MLWParser.IdentifierContext ctx);
	/**
	 * Exit a parse tree produced by {@link MLWParser#identifier}.
	 * @param ctx the parse tree
	 */
	void exitIdentifier(MLWParser.IdentifierContext ctx);
}