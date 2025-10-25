// Generated from /Users/william/coding/1/mlang/src/antlr/MLW.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class MLWParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, T__12=13, T__13=14, T__14=15, T__15=16, T__16=17, 
		T__17=18, T__18=19, T__19=20, T__20=21, T__21=22, T__22=23, T__23=24, 
		T__24=25, T__25=26, T__26=27, T__27=28, T__28=29, T__29=30, T__30=31, 
		T__31=32, T__32=33, T__33=34, T__34=35, T__35=36, T__36=37, T__37=38, 
		T__38=39, T__39=40, T__40=41, T__41=42, T__42=43, T__43=44, T__44=45, 
		T__45=46, IntegerLiteral=47, FloatLiteral=48, StringLiteral=49, BooleanLiteral=50, 
		Identifier=51, WS=52, LINE_COMMENT=53, BLOCK_COMMENT=54;
	public static final int
		RULE_program = 0, RULE_linkerstatement = 1, RULE_functionDefinition = 2, 
		RULE_parameterList = 3, RULE_parameter = 4, RULE_parameterList_typeonly = 5, 
		RULE_parameter_typeonly = 6, RULE_type = 7, RULE_primitiveType = 8, RULE_block = 9, 
		RULE_statement = 10, RULE_variableDeclaration = 11, RULE_assignment = 12, 
		RULE_retStmt = 13, RULE_ifStmt = 14, RULE_whileStmt = 15, RULE_expression = 16, 
		RULE_argumentList = 17, RULE_literal = 18, RULE_identifier = 19;
	private static String[] makeRuleNames() {
		return new String[] {
			"program", "linkerstatement", "functionDefinition", "parameterList", 
			"parameter", "parameterList_typeonly", "parameter_typeonly", "type", 
			"primitiveType", "block", "statement", "variableDeclaration", "assignment", 
			"retStmt", "ifStmt", "whileStmt", "expression", "argumentList", "literal", 
			"identifier"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'!'", "'import'", "'extern'", "'('", "')'", "'->'", "'fn'", "','", 
			"':'", "'i32'", "'i64'", "'f32'", "'f64'", "'str'", "'bool'", "'void'", 
			"'{'", "'}'", "';'", "'var'", "'='", "'+='", "'-='", "'*='", "'/='", 
			"'return'", "'if'", "'else'", "'while'", "'['", "']'", "'.'", "'-'", 
			"'~'", "'*'", "'/'", "'%'", "'+'", "'<'", "'>'", "'<='", "'>='", "'=='", 
			"'!='", "'&&'", "'||'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, "IntegerLiteral", 
			"FloatLiteral", "StringLiteral", "BooleanLiteral", "Identifier", "WS", 
			"LINE_COMMENT", "BLOCK_COMMENT"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "MLW.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public MLWParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ProgramContext extends ParserRuleContext {
		public TerminalNode EOF() { return getToken(MLWParser.EOF, 0); }
		public List<LinkerstatementContext> linkerstatement() {
			return getRuleContexts(LinkerstatementContext.class);
		}
		public LinkerstatementContext linkerstatement(int i) {
			return getRuleContext(LinkerstatementContext.class,i);
		}
		public List<FunctionDefinitionContext> functionDefinition() {
			return getRuleContexts(FunctionDefinitionContext.class);
		}
		public FunctionDefinitionContext functionDefinition(int i) {
			return getRuleContext(FunctionDefinitionContext.class,i);
		}
		public ProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_program; }
	}

	public final ProgramContext program() throws RecognitionException {
		ProgramContext _localctx = new ProgramContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_program);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(43);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__0) {
				{
				{
				setState(40);
				linkerstatement();
				}
				}
				setState(45);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(47); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(46);
				functionDefinition();
				}
				}
				setState(49); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==T__6 );
			setState(51);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class LinkerstatementContext extends ParserRuleContext {
		public LinkerstatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_linkerstatement; }
	 
		public LinkerstatementContext() { }
		public void copyFrom(LinkerstatementContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExternStatementContext extends LinkerstatementContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public ParameterList_typeonlyContext parameterList_typeonly() {
			return getRuleContext(ParameterList_typeonlyContext.class,0);
		}
		public ExternStatementContext(LinkerstatementContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ImportStatementContext extends LinkerstatementContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public ImportStatementContext(LinkerstatementContext ctx) { copyFrom(ctx); }
	}

	public final LinkerstatementContext linkerstatement() throws RecognitionException {
		LinkerstatementContext _localctx = new LinkerstatementContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_linkerstatement);
		int _la;
		try {
			setState(67);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
			case 1:
				_localctx = new ImportStatementContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(53);
				match(T__0);
				setState(54);
				match(T__1);
				setState(55);
				identifier();
				}
				break;
			case 2:
				_localctx = new ExternStatementContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(56);
				match(T__0);
				setState(57);
				match(T__2);
				setState(58);
				identifier();
				setState(59);
				match(T__3);
				setState(61);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 2251799813815296L) != 0)) {
					{
					setState(60);
					parameterList_typeonly();
					}
				}

				setState(63);
				match(T__4);
				setState(64);
				match(T__5);
				setState(65);
				type();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FunctionDefinitionContext extends ParserRuleContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public ParameterListContext parameterList() {
			return getRuleContext(ParameterListContext.class,0);
		}
		public FunctionDefinitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_functionDefinition; }
	}

	public final FunctionDefinitionContext functionDefinition() throws RecognitionException {
		FunctionDefinitionContext _localctx = new FunctionDefinitionContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_functionDefinition);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(69);
			match(T__6);
			setState(70);
			identifier();
			setState(71);
			match(T__3);
			setState(73);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==Identifier) {
				{
				setState(72);
				parameterList();
				}
			}

			setState(75);
			match(T__4);
			setState(76);
			match(T__5);
			setState(77);
			type();
			setState(78);
			block();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ParameterListContext extends ParserRuleContext {
		public List<ParameterContext> parameter() {
			return getRuleContexts(ParameterContext.class);
		}
		public ParameterContext parameter(int i) {
			return getRuleContext(ParameterContext.class,i);
		}
		public ParameterListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameterList; }
	}

	public final ParameterListContext parameterList() throws RecognitionException {
		ParameterListContext _localctx = new ParameterListContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_parameterList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(80);
			parameter();
			setState(85);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__7) {
				{
				{
				setState(81);
				match(T__7);
				setState(82);
				parameter();
				}
				}
				setState(87);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ParameterContext extends ParserRuleContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public ParameterContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameter; }
	}

	public final ParameterContext parameter() throws RecognitionException {
		ParameterContext _localctx = new ParameterContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_parameter);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(88);
			identifier();
			setState(89);
			match(T__8);
			setState(90);
			type();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ParameterList_typeonlyContext extends ParserRuleContext {
		public List<Parameter_typeonlyContext> parameter_typeonly() {
			return getRuleContexts(Parameter_typeonlyContext.class);
		}
		public Parameter_typeonlyContext parameter_typeonly(int i) {
			return getRuleContext(Parameter_typeonlyContext.class,i);
		}
		public ParameterList_typeonlyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameterList_typeonly; }
	}

	public final ParameterList_typeonlyContext parameterList_typeonly() throws RecognitionException {
		ParameterList_typeonlyContext _localctx = new ParameterList_typeonlyContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_parameterList_typeonly);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(92);
			parameter_typeonly();
			setState(97);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__7) {
				{
				{
				setState(93);
				match(T__7);
				setState(94);
				parameter_typeonly();
				}
				}
				setState(99);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Parameter_typeonlyContext extends ParserRuleContext {
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public Parameter_typeonlyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameter_typeonly; }
	}

	public final Parameter_typeonlyContext parameter_typeonly() throws RecognitionException {
		Parameter_typeonlyContext _localctx = new Parameter_typeonlyContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_parameter_typeonly);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(100);
			type();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class TypeContext extends ParserRuleContext {
		public PrimitiveTypeContext primitiveType() {
			return getRuleContext(PrimitiveTypeContext.class,0);
		}
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type; }
	}

	public final TypeContext type() throws RecognitionException {
		TypeContext _localctx = new TypeContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_type);
		try {
			setState(104);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__9:
			case T__10:
			case T__11:
			case T__12:
			case T__13:
			case T__14:
			case T__15:
				enterOuterAlt(_localctx, 1);
				{
				setState(102);
				primitiveType();
				}
				break;
			case Identifier:
				enterOuterAlt(_localctx, 2);
				{
				setState(103);
				identifier();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class PrimitiveTypeContext extends ParserRuleContext {
		public PrimitiveTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_primitiveType; }
	 
		public PrimitiveTypeContext() { }
		public void copyFrom(PrimitiveTypeContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Float32TypeContext extends PrimitiveTypeContext {
		public Float32TypeContext(PrimitiveTypeContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class VoidTypeContext extends PrimitiveTypeContext {
		public VoidTypeContext(PrimitiveTypeContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class BoolTypeContext extends PrimitiveTypeContext {
		public BoolTypeContext(PrimitiveTypeContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Float64TypeContext extends PrimitiveTypeContext {
		public Float64TypeContext(PrimitiveTypeContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Int64TypeContext extends PrimitiveTypeContext {
		public Int64TypeContext(PrimitiveTypeContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class StringTypeContext extends PrimitiveTypeContext {
		public StringTypeContext(PrimitiveTypeContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Int32TypeContext extends PrimitiveTypeContext {
		public Int32TypeContext(PrimitiveTypeContext ctx) { copyFrom(ctx); }
	}

	public final PrimitiveTypeContext primitiveType() throws RecognitionException {
		PrimitiveTypeContext _localctx = new PrimitiveTypeContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_primitiveType);
		try {
			setState(113);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__9:
				_localctx = new Int32TypeContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(106);
				match(T__9);
				}
				break;
			case T__10:
				_localctx = new Int64TypeContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(107);
				match(T__10);
				}
				break;
			case T__11:
				_localctx = new Float32TypeContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(108);
				match(T__11);
				}
				break;
			case T__12:
				_localctx = new Float64TypeContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(109);
				match(T__12);
				}
				break;
			case T__13:
				_localctx = new StringTypeContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(110);
				match(T__13);
				}
				break;
			case T__14:
				_localctx = new BoolTypeContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(111);
				match(T__14);
				}
				break;
			case T__15:
				_localctx = new VoidTypeContext(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(112);
				match(T__15);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class BlockContext extends ParserRuleContext {
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public BlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_block; }
	}

	public final BlockContext block() throws RecognitionException {
		BlockContext _localctx = new BlockContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_block);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(115);
			match(T__16);
			setState(119);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & 4362888648196114L) != 0)) {
				{
				{
				setState(116);
				statement();
				}
				}
				setState(121);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(122);
			match(T__17);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StatementContext extends ParserRuleContext {
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
	 
		public StatementContext() { }
		public void copyFrom(StatementContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class IfStatementContext extends StatementContext {
		public IfStmtContext ifStmt() {
			return getRuleContext(IfStmtContext.class,0);
		}
		public IfStatementContext(StatementContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class AssignmentStatementContext extends StatementContext {
		public AssignmentContext assignment() {
			return getRuleContext(AssignmentContext.class,0);
		}
		public AssignmentStatementContext(StatementContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprStatementContext extends StatementContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public ExprStatementContext(StatementContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ReturnStatementContext extends StatementContext {
		public RetStmtContext retStmt() {
			return getRuleContext(RetStmtContext.class,0);
		}
		public ReturnStatementContext(StatementContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class BlockStatementContext extends StatementContext {
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public BlockStatementContext(StatementContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class WhileStatementContext extends StatementContext {
		public WhileStmtContext whileStmt() {
			return getRuleContext(WhileStmtContext.class,0);
		}
		public WhileStatementContext(StatementContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class VarDeclStatementContext extends StatementContext {
		public VariableDeclarationContext variableDeclaration() {
			return getRuleContext(VariableDeclarationContext.class,0);
		}
		public VarDeclStatementContext(StatementContext ctx) { copyFrom(ctx); }
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_statement);
		try {
			setState(139);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,10,_ctx) ) {
			case 1:
				_localctx = new VarDeclStatementContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(124);
				variableDeclaration();
				setState(125);
				match(T__18);
				}
				break;
			case 2:
				_localctx = new AssignmentStatementContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(127);
				assignment();
				setState(128);
				match(T__18);
				}
				break;
			case 3:
				_localctx = new ExprStatementContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(130);
				expression(0);
				setState(131);
				match(T__18);
				}
				break;
			case 4:
				_localctx = new ReturnStatementContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(133);
				retStmt();
				setState(134);
				match(T__18);
				}
				break;
			case 5:
				_localctx = new IfStatementContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(136);
				ifStmt();
				}
				break;
			case 6:
				_localctx = new WhileStatementContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(137);
				whileStmt();
				}
				break;
			case 7:
				_localctx = new BlockStatementContext(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(138);
				block();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class VariableDeclarationContext extends ParserRuleContext {
		public VariableDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variableDeclaration; }
	 
		public VariableDeclarationContext() { }
		public void copyFrom(VariableDeclarationContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class VarDeclWithoutInitContext extends VariableDeclarationContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public VarDeclWithoutInitContext(VariableDeclarationContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class VarDeclWithInitContext extends VariableDeclarationContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public VarDeclWithInitContext(VariableDeclarationContext ctx) { copyFrom(ctx); }
	}

	public final VariableDeclarationContext variableDeclaration() throws RecognitionException {
		VariableDeclarationContext _localctx = new VariableDeclarationContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_variableDeclaration);
		int _la;
		try {
			setState(155);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,12,_ctx) ) {
			case 1:
				_localctx = new VarDeclWithInitContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(141);
				match(T__19);
				setState(142);
				identifier();
				setState(145);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==T__8) {
					{
					setState(143);
					match(T__8);
					setState(144);
					type();
					}
				}

				setState(147);
				match(T__20);
				setState(148);
				expression(0);
				}
				break;
			case 2:
				_localctx = new VarDeclWithoutInitContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(150);
				match(T__19);
				setState(151);
				identifier();
				setState(152);
				match(T__8);
				setState(153);
				type();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class AssignmentContext extends ParserRuleContext {
		public AssignmentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_assignment; }
	 
		public AssignmentContext() { }
		public void copyFrom(AssignmentContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class SimpleAssignmentContext extends AssignmentContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public SimpleAssignmentContext(AssignmentContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class CompoundAssignmentContext extends AssignmentContext {
		public Token op;
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public CompoundAssignmentContext(AssignmentContext ctx) { copyFrom(ctx); }
	}

	public final AssignmentContext assignment() throws RecognitionException {
		AssignmentContext _localctx = new AssignmentContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_assignment);
		int _la;
		try {
			setState(165);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
			case 1:
				_localctx = new SimpleAssignmentContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(157);
				identifier();
				setState(158);
				match(T__20);
				setState(159);
				expression(0);
				}
				break;
			case 2:
				_localctx = new CompoundAssignmentContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(161);
				identifier();
				setState(162);
				((CompoundAssignmentContext)_localctx).op = _input.LT(1);
				_la = _input.LA(1);
				if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 62914560L) != 0)) ) {
					((CompoundAssignmentContext)_localctx).op = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(163);
				expression(0);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class RetStmtContext extends ParserRuleContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public RetStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_retStmt; }
	}

	public final RetStmtContext retStmt() throws RecognitionException {
		RetStmtContext _localctx = new RetStmtContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_retStmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(167);
			match(T__25);
			setState(169);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 4362887908818962L) != 0)) {
				{
				setState(168);
				expression(0);
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class IfStmtContext extends ParserRuleContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public List<BlockContext> block() {
			return getRuleContexts(BlockContext.class);
		}
		public BlockContext block(int i) {
			return getRuleContext(BlockContext.class,i);
		}
		public IfStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ifStmt; }
	}

	public final IfStmtContext ifStmt() throws RecognitionException {
		IfStmtContext _localctx = new IfStmtContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_ifStmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(171);
			match(T__26);
			setState(172);
			expression(0);
			setState(173);
			block();
			setState(176);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==T__27) {
				{
				setState(174);
				match(T__27);
				setState(175);
				block();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class WhileStmtContext extends ParserRuleContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public WhileStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_whileStmt; }
	}

	public final WhileStmtContext whileStmt() throws RecognitionException {
		WhileStmtContext _localctx = new WhileStmtContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_whileStmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(178);
			match(T__28);
			setState(179);
			expression(0);
			setState(180);
			block();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionContext extends ParserRuleContext {
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
	 
		public ExpressionContext() { }
		public void copyFrom(ExpressionContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class SubscriptExprContext extends ExpressionContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public SubscriptExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class RelationalExprContext extends ExpressionContext {
		public Token op;
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public RelationalExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class UnaryExprContext extends ExpressionContext {
		public Token op;
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public UnaryExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class LogicalAndExprContext extends ExpressionContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public LogicalAndExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class MultiplicativeExprContext extends ExpressionContext {
		public Token op;
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public MultiplicativeExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class LogicalOrExprContext extends ExpressionContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public LogicalOrExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class EqualityExprContext extends ExpressionContext {
		public Token op;
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public EqualityExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class AdditiveExprContext extends ExpressionContext {
		public Token op;
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public AdditiveExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class IdentifierExprContext extends ExpressionContext {
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public IdentifierExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class LiteralExprContext extends ExpressionContext {
		public LiteralContext literal() {
			return getRuleContext(LiteralContext.class,0);
		}
		public LiteralExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class CallExprContext extends ExpressionContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public ArgumentListContext argumentList() {
			return getRuleContext(ArgumentListContext.class,0);
		}
		public CallExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ParenExprContext extends ExpressionContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public ParenExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class MemberAccessExprContext extends ExpressionContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public MemberAccessExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}

	public final ExpressionContext expression() throws RecognitionException {
		return expression(0);
	}

	private ExpressionContext expression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExpressionContext _localctx = new ExpressionContext(_ctx, _parentState);
		ExpressionContext _prevctx = _localctx;
		int _startState = 32;
		enterRecursionRule(_localctx, 32, RULE_expression, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(191);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case IntegerLiteral:
			case FloatLiteral:
			case StringLiteral:
			case BooleanLiteral:
				{
				_localctx = new LiteralExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(183);
				literal();
				}
				break;
			case Identifier:
				{
				_localctx = new IdentifierExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(184);
				identifier();
				}
				break;
			case T__0:
			case T__32:
			case T__33:
				{
				_localctx = new UnaryExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(185);
				((UnaryExprContext)_localctx).op = _input.LT(1);
				_la = _input.LA(1);
				if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 25769803778L) != 0)) ) {
					((UnaryExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(186);
				expression(8);
				}
				break;
			case T__3:
				{
				_localctx = new ParenExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(187);
				match(T__3);
				setState(188);
				expression(0);
				setState(189);
				match(T__4);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(227);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,19,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(225);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,18,_ctx) ) {
					case 1:
						{
						_localctx = new MultiplicativeExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(193);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(194);
						((MultiplicativeExprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 240518168576L) != 0)) ) {
							((MultiplicativeExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(195);
						expression(8);
						}
						break;
					case 2:
						{
						_localctx = new AdditiveExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(196);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(197);
						((AdditiveExprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==T__32 || _la==T__37) ) {
							((AdditiveExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(198);
						expression(7);
						}
						break;
					case 3:
						{
						_localctx = new RelationalExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(199);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(200);
						((RelationalExprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 8246337208320L) != 0)) ) {
							((RelationalExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(201);
						expression(6);
						}
						break;
					case 4:
						{
						_localctx = new EqualityExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(202);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(203);
						((EqualityExprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==T__42 || _la==T__43) ) {
							((EqualityExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(204);
						expression(5);
						}
						break;
					case 5:
						{
						_localctx = new LogicalAndExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(205);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(206);
						match(T__44);
						setState(207);
						expression(4);
						}
						break;
					case 6:
						{
						_localctx = new LogicalOrExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(208);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(209);
						match(T__45);
						setState(210);
						expression(3);
						}
						break;
					case 7:
						{
						_localctx = new CallExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(211);
						if (!(precpred(_ctx, 11))) throw new FailedPredicateException(this, "precpred(_ctx, 11)");
						setState(212);
						match(T__3);
						setState(214);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 4362887908818962L) != 0)) {
							{
							setState(213);
							argumentList();
							}
						}

						setState(216);
						match(T__4);
						}
						break;
					case 8:
						{
						_localctx = new SubscriptExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(217);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(218);
						match(T__29);
						setState(219);
						expression(0);
						setState(220);
						match(T__30);
						}
						break;
					case 9:
						{
						_localctx = new MemberAccessExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(222);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(223);
						match(T__31);
						setState(224);
						identifier();
						}
						break;
					}
					} 
				}
				setState(229);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,19,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ArgumentListContext extends ParserRuleContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public ArgumentListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_argumentList; }
	}

	public final ArgumentListContext argumentList() throws RecognitionException {
		ArgumentListContext _localctx = new ArgumentListContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_argumentList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(230);
			expression(0);
			setState(235);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__7) {
				{
				{
				setState(231);
				match(T__7);
				setState(232);
				expression(0);
				}
				}
				setState(237);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class LiteralContext extends ParserRuleContext {
		public LiteralContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_literal; }
	 
		public LiteralContext() { }
		public void copyFrom(LiteralContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class StringLiteralContext extends LiteralContext {
		public TerminalNode StringLiteral() { return getToken(MLWParser.StringLiteral, 0); }
		public StringLiteralContext(LiteralContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class BoolLiteralContext extends LiteralContext {
		public TerminalNode BooleanLiteral() { return getToken(MLWParser.BooleanLiteral, 0); }
		public BoolLiteralContext(LiteralContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class FloatLiteralContext extends LiteralContext {
		public TerminalNode FloatLiteral() { return getToken(MLWParser.FloatLiteral, 0); }
		public FloatLiteralContext(LiteralContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class IntLiteralContext extends LiteralContext {
		public TerminalNode IntegerLiteral() { return getToken(MLWParser.IntegerLiteral, 0); }
		public IntLiteralContext(LiteralContext ctx) { copyFrom(ctx); }
	}

	public final LiteralContext literal() throws RecognitionException {
		LiteralContext _localctx = new LiteralContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_literal);
		try {
			setState(242);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case IntegerLiteral:
				_localctx = new IntLiteralContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(238);
				match(IntegerLiteral);
				}
				break;
			case FloatLiteral:
				_localctx = new FloatLiteralContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(239);
				match(FloatLiteral);
				}
				break;
			case StringLiteral:
				_localctx = new StringLiteralContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(240);
				match(StringLiteral);
				}
				break;
			case BooleanLiteral:
				_localctx = new BoolLiteralContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(241);
				match(BooleanLiteral);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class IdentifierContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(MLWParser.Identifier, 0); }
		public IdentifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_identifier; }
	}

	public final IdentifierContext identifier() throws RecognitionException {
		IdentifierContext _localctx = new IdentifierContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_identifier);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(244);
			match(Identifier);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 16:
			return expression_sempred((ExpressionContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expression_sempred(ExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 7);
		case 1:
			return precpred(_ctx, 6);
		case 2:
			return precpred(_ctx, 5);
		case 3:
			return precpred(_ctx, 4);
		case 4:
			return precpred(_ctx, 3);
		case 5:
			return precpred(_ctx, 2);
		case 6:
			return precpred(_ctx, 11);
		case 7:
			return precpred(_ctx, 10);
		case 8:
			return precpred(_ctx, 9);
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u00016\u00f7\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0002"+
		"\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002\u000f\u0007\u000f"+
		"\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0002\u0012\u0007\u0012"+
		"\u0002\u0013\u0007\u0013\u0001\u0000\u0005\u0000*\b\u0000\n\u0000\f\u0000"+
		"-\t\u0000\u0001\u0000\u0004\u00000\b\u0000\u000b\u0000\f\u00001\u0001"+
		"\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0003\u0001>\b\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0003\u0001D\b\u0001\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0003\u0002J\b\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0003\u0001"+
		"\u0003\u0001\u0003\u0005\u0003T\b\u0003\n\u0003\f\u0003W\t\u0003\u0001"+
		"\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0005\u0001\u0005\u0001"+
		"\u0005\u0005\u0005`\b\u0005\n\u0005\f\u0005c\t\u0005\u0001\u0006\u0001"+
		"\u0006\u0001\u0007\u0001\u0007\u0003\u0007i\b\u0007\u0001\b\u0001\b\u0001"+
		"\b\u0001\b\u0001\b\u0001\b\u0001\b\u0003\br\b\b\u0001\t\u0001\t\u0005"+
		"\tv\b\t\n\t\f\ty\t\t\u0001\t\u0001\t\u0001\n\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0003\n\u008c\b\n\u0001\u000b\u0001\u000b\u0001\u000b\u0001"+
		"\u000b\u0003\u000b\u0092\b\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001"+
		"\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0003\u000b\u009c"+
		"\b\u000b\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0003\f\u00a6\b\f\u0001\r\u0001\r\u0003\r\u00aa\b\r\u0001\u000e\u0001"+
		"\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0003\u000e\u00b1\b\u000e\u0001"+
		"\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u0010\u0001\u0010\u0001"+
		"\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001"+
		"\u0010\u0003\u0010\u00c0\b\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001"+
		"\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001"+
		"\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001"+
		"\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0003"+
		"\u0010\u00d7\b\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001"+
		"\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0005\u0010\u00e2"+
		"\b\u0010\n\u0010\f\u0010\u00e5\t\u0010\u0001\u0011\u0001\u0011\u0001\u0011"+
		"\u0005\u0011\u00ea\b\u0011\n\u0011\f\u0011\u00ed\t\u0011\u0001\u0012\u0001"+
		"\u0012\u0001\u0012\u0001\u0012\u0003\u0012\u00f3\b\u0012\u0001\u0013\u0001"+
		"\u0013\u0001\u0013\u0000\u0001 \u0014\u0000\u0002\u0004\u0006\b\n\f\u000e"+
		"\u0010\u0012\u0014\u0016\u0018\u001a\u001c\u001e \"$&\u0000\u0006\u0001"+
		"\u0000\u0016\u0019\u0002\u0000\u0001\u0001!\"\u0001\u0000#%\u0002\u0000"+
		"!!&&\u0001\u0000\'*\u0001\u0000+,\u010d\u0000+\u0001\u0000\u0000\u0000"+
		"\u0002C\u0001\u0000\u0000\u0000\u0004E\u0001\u0000\u0000\u0000\u0006P"+
		"\u0001\u0000\u0000\u0000\bX\u0001\u0000\u0000\u0000\n\\\u0001\u0000\u0000"+
		"\u0000\fd\u0001\u0000\u0000\u0000\u000eh\u0001\u0000\u0000\u0000\u0010"+
		"q\u0001\u0000\u0000\u0000\u0012s\u0001\u0000\u0000\u0000\u0014\u008b\u0001"+
		"\u0000\u0000\u0000\u0016\u009b\u0001\u0000\u0000\u0000\u0018\u00a5\u0001"+
		"\u0000\u0000\u0000\u001a\u00a7\u0001\u0000\u0000\u0000\u001c\u00ab\u0001"+
		"\u0000\u0000\u0000\u001e\u00b2\u0001\u0000\u0000\u0000 \u00bf\u0001\u0000"+
		"\u0000\u0000\"\u00e6\u0001\u0000\u0000\u0000$\u00f2\u0001\u0000\u0000"+
		"\u0000&\u00f4\u0001\u0000\u0000\u0000(*\u0003\u0002\u0001\u0000)(\u0001"+
		"\u0000\u0000\u0000*-\u0001\u0000\u0000\u0000+)\u0001\u0000\u0000\u0000"+
		"+,\u0001\u0000\u0000\u0000,/\u0001\u0000\u0000\u0000-+\u0001\u0000\u0000"+
		"\u0000.0\u0003\u0004\u0002\u0000/.\u0001\u0000\u0000\u000001\u0001\u0000"+
		"\u0000\u00001/\u0001\u0000\u0000\u000012\u0001\u0000\u0000\u000023\u0001"+
		"\u0000\u0000\u000034\u0005\u0000\u0000\u00014\u0001\u0001\u0000\u0000"+
		"\u000056\u0005\u0001\u0000\u000067\u0005\u0002\u0000\u00007D\u0003&\u0013"+
		"\u000089\u0005\u0001\u0000\u00009:\u0005\u0003\u0000\u0000:;\u0003&\u0013"+
		"\u0000;=\u0005\u0004\u0000\u0000<>\u0003\n\u0005\u0000=<\u0001\u0000\u0000"+
		"\u0000=>\u0001\u0000\u0000\u0000>?\u0001\u0000\u0000\u0000?@\u0005\u0005"+
		"\u0000\u0000@A\u0005\u0006\u0000\u0000AB\u0003\u000e\u0007\u0000BD\u0001"+
		"\u0000\u0000\u0000C5\u0001\u0000\u0000\u0000C8\u0001\u0000\u0000\u0000"+
		"D\u0003\u0001\u0000\u0000\u0000EF\u0005\u0007\u0000\u0000FG\u0003&\u0013"+
		"\u0000GI\u0005\u0004\u0000\u0000HJ\u0003\u0006\u0003\u0000IH\u0001\u0000"+
		"\u0000\u0000IJ\u0001\u0000\u0000\u0000JK\u0001\u0000\u0000\u0000KL\u0005"+
		"\u0005\u0000\u0000LM\u0005\u0006\u0000\u0000MN\u0003\u000e\u0007\u0000"+
		"NO\u0003\u0012\t\u0000O\u0005\u0001\u0000\u0000\u0000PU\u0003\b\u0004"+
		"\u0000QR\u0005\b\u0000\u0000RT\u0003\b\u0004\u0000SQ\u0001\u0000\u0000"+
		"\u0000TW\u0001\u0000\u0000\u0000US\u0001\u0000\u0000\u0000UV\u0001\u0000"+
		"\u0000\u0000V\u0007\u0001\u0000\u0000\u0000WU\u0001\u0000\u0000\u0000"+
		"XY\u0003&\u0013\u0000YZ\u0005\t\u0000\u0000Z[\u0003\u000e\u0007\u0000"+
		"[\t\u0001\u0000\u0000\u0000\\a\u0003\f\u0006\u0000]^\u0005\b\u0000\u0000"+
		"^`\u0003\f\u0006\u0000_]\u0001\u0000\u0000\u0000`c\u0001\u0000\u0000\u0000"+
		"a_\u0001\u0000\u0000\u0000ab\u0001\u0000\u0000\u0000b\u000b\u0001\u0000"+
		"\u0000\u0000ca\u0001\u0000\u0000\u0000de\u0003\u000e\u0007\u0000e\r\u0001"+
		"\u0000\u0000\u0000fi\u0003\u0010\b\u0000gi\u0003&\u0013\u0000hf\u0001"+
		"\u0000\u0000\u0000hg\u0001\u0000\u0000\u0000i\u000f\u0001\u0000\u0000"+
		"\u0000jr\u0005\n\u0000\u0000kr\u0005\u000b\u0000\u0000lr\u0005\f\u0000"+
		"\u0000mr\u0005\r\u0000\u0000nr\u0005\u000e\u0000\u0000or\u0005\u000f\u0000"+
		"\u0000pr\u0005\u0010\u0000\u0000qj\u0001\u0000\u0000\u0000qk\u0001\u0000"+
		"\u0000\u0000ql\u0001\u0000\u0000\u0000qm\u0001\u0000\u0000\u0000qn\u0001"+
		"\u0000\u0000\u0000qo\u0001\u0000\u0000\u0000qp\u0001\u0000\u0000\u0000"+
		"r\u0011\u0001\u0000\u0000\u0000sw\u0005\u0011\u0000\u0000tv\u0003\u0014"+
		"\n\u0000ut\u0001\u0000\u0000\u0000vy\u0001\u0000\u0000\u0000wu\u0001\u0000"+
		"\u0000\u0000wx\u0001\u0000\u0000\u0000xz\u0001\u0000\u0000\u0000yw\u0001"+
		"\u0000\u0000\u0000z{\u0005\u0012\u0000\u0000{\u0013\u0001\u0000\u0000"+
		"\u0000|}\u0003\u0016\u000b\u0000}~\u0005\u0013\u0000\u0000~\u008c\u0001"+
		"\u0000\u0000\u0000\u007f\u0080\u0003\u0018\f\u0000\u0080\u0081\u0005\u0013"+
		"\u0000\u0000\u0081\u008c\u0001\u0000\u0000\u0000\u0082\u0083\u0003 \u0010"+
		"\u0000\u0083\u0084\u0005\u0013\u0000\u0000\u0084\u008c\u0001\u0000\u0000"+
		"\u0000\u0085\u0086\u0003\u001a\r\u0000\u0086\u0087\u0005\u0013\u0000\u0000"+
		"\u0087\u008c\u0001\u0000\u0000\u0000\u0088\u008c\u0003\u001c\u000e\u0000"+
		"\u0089\u008c\u0003\u001e\u000f\u0000\u008a\u008c\u0003\u0012\t\u0000\u008b"+
		"|\u0001\u0000\u0000\u0000\u008b\u007f\u0001\u0000\u0000\u0000\u008b\u0082"+
		"\u0001\u0000\u0000\u0000\u008b\u0085\u0001\u0000\u0000\u0000\u008b\u0088"+
		"\u0001\u0000\u0000\u0000\u008b\u0089\u0001\u0000\u0000\u0000\u008b\u008a"+
		"\u0001\u0000\u0000\u0000\u008c\u0015\u0001\u0000\u0000\u0000\u008d\u008e"+
		"\u0005\u0014\u0000\u0000\u008e\u0091\u0003&\u0013\u0000\u008f\u0090\u0005"+
		"\t\u0000\u0000\u0090\u0092\u0003\u000e\u0007\u0000\u0091\u008f\u0001\u0000"+
		"\u0000\u0000\u0091\u0092\u0001\u0000\u0000\u0000\u0092\u0093\u0001\u0000"+
		"\u0000\u0000\u0093\u0094\u0005\u0015\u0000\u0000\u0094\u0095\u0003 \u0010"+
		"\u0000\u0095\u009c\u0001\u0000\u0000\u0000\u0096\u0097\u0005\u0014\u0000"+
		"\u0000\u0097\u0098\u0003&\u0013\u0000\u0098\u0099\u0005\t\u0000\u0000"+
		"\u0099\u009a\u0003\u000e\u0007\u0000\u009a\u009c\u0001\u0000\u0000\u0000"+
		"\u009b\u008d\u0001\u0000\u0000\u0000\u009b\u0096\u0001\u0000\u0000\u0000"+
		"\u009c\u0017\u0001\u0000\u0000\u0000\u009d\u009e\u0003&\u0013\u0000\u009e"+
		"\u009f\u0005\u0015\u0000\u0000\u009f\u00a0\u0003 \u0010\u0000\u00a0\u00a6"+
		"\u0001\u0000\u0000\u0000\u00a1\u00a2\u0003&\u0013\u0000\u00a2\u00a3\u0007"+
		"\u0000\u0000\u0000\u00a3\u00a4\u0003 \u0010\u0000\u00a4\u00a6\u0001\u0000"+
		"\u0000\u0000\u00a5\u009d\u0001\u0000\u0000\u0000\u00a5\u00a1\u0001\u0000"+
		"\u0000\u0000\u00a6\u0019\u0001\u0000\u0000\u0000\u00a7\u00a9\u0005\u001a"+
		"\u0000\u0000\u00a8\u00aa\u0003 \u0010\u0000\u00a9\u00a8\u0001\u0000\u0000"+
		"\u0000\u00a9\u00aa\u0001\u0000\u0000\u0000\u00aa\u001b\u0001\u0000\u0000"+
		"\u0000\u00ab\u00ac\u0005\u001b\u0000\u0000\u00ac\u00ad\u0003 \u0010\u0000"+
		"\u00ad\u00b0\u0003\u0012\t\u0000\u00ae\u00af\u0005\u001c\u0000\u0000\u00af"+
		"\u00b1\u0003\u0012\t\u0000\u00b0\u00ae\u0001\u0000\u0000\u0000\u00b0\u00b1"+
		"\u0001\u0000\u0000\u0000\u00b1\u001d\u0001\u0000\u0000\u0000\u00b2\u00b3"+
		"\u0005\u001d\u0000\u0000\u00b3\u00b4\u0003 \u0010\u0000\u00b4\u00b5\u0003"+
		"\u0012\t\u0000\u00b5\u001f\u0001\u0000\u0000\u0000\u00b6\u00b7\u0006\u0010"+
		"\uffff\uffff\u0000\u00b7\u00c0\u0003$\u0012\u0000\u00b8\u00c0\u0003&\u0013"+
		"\u0000\u00b9\u00ba\u0007\u0001\u0000\u0000\u00ba\u00c0\u0003 \u0010\b"+
		"\u00bb\u00bc\u0005\u0004\u0000\u0000\u00bc\u00bd\u0003 \u0010\u0000\u00bd"+
		"\u00be\u0005\u0005\u0000\u0000\u00be\u00c0\u0001\u0000\u0000\u0000\u00bf"+
		"\u00b6\u0001\u0000\u0000\u0000\u00bf\u00b8\u0001\u0000\u0000\u0000\u00bf"+
		"\u00b9\u0001\u0000\u0000\u0000\u00bf\u00bb\u0001\u0000\u0000\u0000\u00c0"+
		"\u00e3\u0001\u0000\u0000\u0000\u00c1\u00c2\n\u0007\u0000\u0000\u00c2\u00c3"+
		"\u0007\u0002\u0000\u0000\u00c3\u00e2\u0003 \u0010\b\u00c4\u00c5\n\u0006"+
		"\u0000\u0000\u00c5\u00c6\u0007\u0003\u0000\u0000\u00c6\u00e2\u0003 \u0010"+
		"\u0007\u00c7\u00c8\n\u0005\u0000\u0000\u00c8\u00c9\u0007\u0004\u0000\u0000"+
		"\u00c9\u00e2\u0003 \u0010\u0006\u00ca\u00cb\n\u0004\u0000\u0000\u00cb"+
		"\u00cc\u0007\u0005\u0000\u0000\u00cc\u00e2\u0003 \u0010\u0005\u00cd\u00ce"+
		"\n\u0003\u0000\u0000\u00ce\u00cf\u0005-\u0000\u0000\u00cf\u00e2\u0003"+
		" \u0010\u0004\u00d0\u00d1\n\u0002\u0000\u0000\u00d1\u00d2\u0005.\u0000"+
		"\u0000\u00d2\u00e2\u0003 \u0010\u0003\u00d3\u00d4\n\u000b\u0000\u0000"+
		"\u00d4\u00d6\u0005\u0004\u0000\u0000\u00d5\u00d7\u0003\"\u0011\u0000\u00d6"+
		"\u00d5\u0001\u0000\u0000\u0000\u00d6\u00d7\u0001\u0000\u0000\u0000\u00d7"+
		"\u00d8\u0001\u0000\u0000\u0000\u00d8\u00e2\u0005\u0005\u0000\u0000\u00d9"+
		"\u00da\n\n\u0000\u0000\u00da\u00db\u0005\u001e\u0000\u0000\u00db\u00dc"+
		"\u0003 \u0010\u0000\u00dc\u00dd\u0005\u001f\u0000\u0000\u00dd\u00e2\u0001"+
		"\u0000\u0000\u0000\u00de\u00df\n\t\u0000\u0000\u00df\u00e0\u0005 \u0000"+
		"\u0000\u00e0\u00e2\u0003&\u0013\u0000\u00e1\u00c1\u0001\u0000\u0000\u0000"+
		"\u00e1\u00c4\u0001\u0000\u0000\u0000\u00e1\u00c7\u0001\u0000\u0000\u0000"+
		"\u00e1\u00ca\u0001\u0000\u0000\u0000\u00e1\u00cd\u0001\u0000\u0000\u0000"+
		"\u00e1\u00d0\u0001\u0000\u0000\u0000\u00e1\u00d3\u0001\u0000\u0000\u0000"+
		"\u00e1\u00d9\u0001\u0000\u0000\u0000\u00e1\u00de\u0001\u0000\u0000\u0000"+
		"\u00e2\u00e5\u0001\u0000\u0000\u0000\u00e3\u00e1\u0001\u0000\u0000\u0000"+
		"\u00e3\u00e4\u0001\u0000\u0000\u0000\u00e4!\u0001\u0000\u0000\u0000\u00e5"+
		"\u00e3\u0001\u0000\u0000\u0000\u00e6\u00eb\u0003 \u0010\u0000\u00e7\u00e8"+
		"\u0005\b\u0000\u0000\u00e8\u00ea\u0003 \u0010\u0000\u00e9\u00e7\u0001"+
		"\u0000\u0000\u0000\u00ea\u00ed\u0001\u0000\u0000\u0000\u00eb\u00e9\u0001"+
		"\u0000\u0000\u0000\u00eb\u00ec\u0001\u0000\u0000\u0000\u00ec#\u0001\u0000"+
		"\u0000\u0000\u00ed\u00eb\u0001\u0000\u0000\u0000\u00ee\u00f3\u0005/\u0000"+
		"\u0000\u00ef\u00f3\u00050\u0000\u0000\u00f0\u00f3\u00051\u0000\u0000\u00f1"+
		"\u00f3\u00052\u0000\u0000\u00f2\u00ee\u0001\u0000\u0000\u0000\u00f2\u00ef"+
		"\u0001\u0000\u0000\u0000\u00f2\u00f0\u0001\u0000\u0000\u0000\u00f2\u00f1"+
		"\u0001\u0000\u0000\u0000\u00f3%\u0001\u0000\u0000\u0000\u00f4\u00f5\u0005"+
		"3\u0000\u0000\u00f5\'\u0001\u0000\u0000\u0000\u0016+1=CIUahqw\u008b\u0091"+
		"\u009b\u00a5\u00a9\u00b0\u00bf\u00d6\u00e1\u00e3\u00eb\u00f2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}