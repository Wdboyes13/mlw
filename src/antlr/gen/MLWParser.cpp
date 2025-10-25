
// Generated from MLW.g4 by ANTLR 4.13.2


#include "MLWListener.h"

#include "MLWParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct MLWParserStaticData final {
  MLWParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MLWParserStaticData(const MLWParserStaticData&) = delete;
  MLWParserStaticData(MLWParserStaticData&&) = delete;
  MLWParserStaticData& operator=(const MLWParserStaticData&) = delete;
  MLWParserStaticData& operator=(MLWParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag mlwParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<MLWParserStaticData> mlwParserStaticData = nullptr;

void mlwParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (mlwParserStaticData != nullptr) {
    return;
  }
#else
  assert(mlwParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<MLWParserStaticData>(
    std::vector<std::string>{
      "program", "linkerstatement", "functionDefinition", "parameterList", 
      "parameter", "parameterList_typeonly", "parameter_typeonly", "type", 
      "primitiveType", "block", "statement", "variableDeclaration", "assignment", 
      "retStmt", "ifStmt", "whileStmt", "primaryExpression", "postfixExpression", 
      "expression", "argumentList", "literal", "identifier"
    },
    std::vector<std::string>{
      "", "'!'", "'import'", "'extern'", "'('", "')'", "'->'", "'fn'", "','", 
      "':'", "'i32'", "'i64'", "'f32'", "'f64'", "'str'", "'bool'", "'void'", 
      "'{'", "'}'", "';'", "'var'", "'='", "'+='", "'-='", "'*='", "'/='", 
      "'return'", "'if'", "'else'", "'while'", "'['", "']'", "'.'", "'-'", 
      "'~'", "'*'", "'/'", "'%'", "'+'", "'<'", "'>'", "'<='", "'>='", "'=='", 
      "'!='", "'&&'", "'||'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "IntegerLiteral", 
      "FloatLiteral", "StringLiteral", "BooleanLiteral", "Identifier", "WS", 
      "LINE_COMMENT", "BLOCK_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,54,262,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,1,0,5,0,46,8,0,10,0,12,0,49,9,0,1,0,4,0,52,8,0,11,0,12,0,53,1,0,1,
  	0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,66,8,1,1,1,1,1,1,1,1,1,3,1,72,8,
  	1,1,2,1,2,1,2,1,2,3,2,78,8,2,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,5,3,88,8,
  	3,10,3,12,3,91,9,3,1,4,1,4,1,4,1,4,1,5,1,5,1,5,5,5,100,8,5,10,5,12,5,
  	103,9,5,1,6,1,6,1,7,1,7,3,7,109,8,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,3,8,118,
  	8,8,1,9,1,9,5,9,122,8,9,10,9,12,9,125,9,9,1,9,1,9,1,10,1,10,1,10,1,10,
  	1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,3,10,144,8,10,
  	1,11,1,11,1,11,1,11,3,11,150,8,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,3,11,160,8,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,3,12,170,8,
  	12,1,13,1,13,3,13,174,8,13,1,14,1,14,1,14,1,14,1,14,3,14,181,8,14,1,15,
  	1,15,1,15,1,15,1,16,1,16,1,16,1,16,1,16,1,16,3,16,193,8,16,1,17,1,17,
  	1,17,1,17,1,17,1,17,3,17,201,8,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,
  	1,17,1,17,5,17,212,8,17,10,17,12,17,215,9,17,1,18,1,18,1,18,1,18,3,18,
  	221,8,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,
  	1,18,1,18,1,18,1,18,1,18,1,18,5,18,241,8,18,10,18,12,18,244,9,18,1,19,
  	1,19,1,19,5,19,249,8,19,10,19,12,19,252,9,19,1,20,1,20,1,20,1,20,3,20,
  	258,8,20,1,21,1,21,1,21,0,2,34,36,22,0,2,4,6,8,10,12,14,16,18,20,22,24,
  	26,28,30,32,34,36,38,40,42,0,6,1,0,22,25,2,0,1,1,33,34,1,0,35,37,2,0,
  	33,33,38,38,1,0,39,42,1,0,43,44,282,0,47,1,0,0,0,2,71,1,0,0,0,4,73,1,
  	0,0,0,6,84,1,0,0,0,8,92,1,0,0,0,10,96,1,0,0,0,12,104,1,0,0,0,14,108,1,
  	0,0,0,16,117,1,0,0,0,18,119,1,0,0,0,20,143,1,0,0,0,22,159,1,0,0,0,24,
  	169,1,0,0,0,26,171,1,0,0,0,28,175,1,0,0,0,30,182,1,0,0,0,32,192,1,0,0,
  	0,34,194,1,0,0,0,36,220,1,0,0,0,38,245,1,0,0,0,40,257,1,0,0,0,42,259,
  	1,0,0,0,44,46,3,2,1,0,45,44,1,0,0,0,46,49,1,0,0,0,47,45,1,0,0,0,47,48,
  	1,0,0,0,48,51,1,0,0,0,49,47,1,0,0,0,50,52,3,4,2,0,51,50,1,0,0,0,52,53,
  	1,0,0,0,53,51,1,0,0,0,53,54,1,0,0,0,54,55,1,0,0,0,55,56,5,0,0,1,56,1,
  	1,0,0,0,57,58,5,1,0,0,58,59,5,2,0,0,59,72,3,42,21,0,60,61,5,1,0,0,61,
  	62,5,3,0,0,62,63,3,42,21,0,63,65,5,4,0,0,64,66,3,10,5,0,65,64,1,0,0,0,
  	65,66,1,0,0,0,66,67,1,0,0,0,67,68,5,5,0,0,68,69,5,6,0,0,69,70,3,14,7,
  	0,70,72,1,0,0,0,71,57,1,0,0,0,71,60,1,0,0,0,72,3,1,0,0,0,73,74,5,7,0,
  	0,74,75,3,42,21,0,75,77,5,4,0,0,76,78,3,6,3,0,77,76,1,0,0,0,77,78,1,0,
  	0,0,78,79,1,0,0,0,79,80,5,5,0,0,80,81,5,6,0,0,81,82,3,14,7,0,82,83,3,
  	18,9,0,83,5,1,0,0,0,84,89,3,8,4,0,85,86,5,8,0,0,86,88,3,8,4,0,87,85,1,
  	0,0,0,88,91,1,0,0,0,89,87,1,0,0,0,89,90,1,0,0,0,90,7,1,0,0,0,91,89,1,
  	0,0,0,92,93,3,42,21,0,93,94,5,9,0,0,94,95,3,14,7,0,95,9,1,0,0,0,96,101,
  	3,12,6,0,97,98,5,8,0,0,98,100,3,12,6,0,99,97,1,0,0,0,100,103,1,0,0,0,
  	101,99,1,0,0,0,101,102,1,0,0,0,102,11,1,0,0,0,103,101,1,0,0,0,104,105,
  	3,14,7,0,105,13,1,0,0,0,106,109,3,16,8,0,107,109,3,42,21,0,108,106,1,
  	0,0,0,108,107,1,0,0,0,109,15,1,0,0,0,110,118,5,10,0,0,111,118,5,11,0,
  	0,112,118,5,12,0,0,113,118,5,13,0,0,114,118,5,14,0,0,115,118,5,15,0,0,
  	116,118,5,16,0,0,117,110,1,0,0,0,117,111,1,0,0,0,117,112,1,0,0,0,117,
  	113,1,0,0,0,117,114,1,0,0,0,117,115,1,0,0,0,117,116,1,0,0,0,118,17,1,
  	0,0,0,119,123,5,17,0,0,120,122,3,20,10,0,121,120,1,0,0,0,122,125,1,0,
  	0,0,123,121,1,0,0,0,123,124,1,0,0,0,124,126,1,0,0,0,125,123,1,0,0,0,126,
  	127,5,18,0,0,127,19,1,0,0,0,128,129,3,22,11,0,129,130,5,19,0,0,130,144,
  	1,0,0,0,131,132,3,24,12,0,132,133,5,19,0,0,133,144,1,0,0,0,134,135,3,
  	36,18,0,135,136,5,19,0,0,136,144,1,0,0,0,137,138,3,26,13,0,138,139,5,
  	19,0,0,139,144,1,0,0,0,140,144,3,28,14,0,141,144,3,30,15,0,142,144,3,
  	18,9,0,143,128,1,0,0,0,143,131,1,0,0,0,143,134,1,0,0,0,143,137,1,0,0,
  	0,143,140,1,0,0,0,143,141,1,0,0,0,143,142,1,0,0,0,144,21,1,0,0,0,145,
  	146,5,20,0,0,146,149,3,42,21,0,147,148,5,9,0,0,148,150,3,14,7,0,149,147,
  	1,0,0,0,149,150,1,0,0,0,150,151,1,0,0,0,151,152,5,21,0,0,152,153,3,36,
  	18,0,153,160,1,0,0,0,154,155,5,20,0,0,155,156,3,42,21,0,156,157,5,9,0,
  	0,157,158,3,14,7,0,158,160,1,0,0,0,159,145,1,0,0,0,159,154,1,0,0,0,160,
  	23,1,0,0,0,161,162,3,42,21,0,162,163,5,21,0,0,163,164,3,36,18,0,164,170,
  	1,0,0,0,165,166,3,42,21,0,166,167,7,0,0,0,167,168,3,36,18,0,168,170,1,
  	0,0,0,169,161,1,0,0,0,169,165,1,0,0,0,170,25,1,0,0,0,171,173,5,26,0,0,
  	172,174,3,36,18,0,173,172,1,0,0,0,173,174,1,0,0,0,174,27,1,0,0,0,175,
  	176,5,27,0,0,176,177,3,36,18,0,177,180,3,18,9,0,178,179,5,28,0,0,179,
  	181,3,18,9,0,180,178,1,0,0,0,180,181,1,0,0,0,181,29,1,0,0,0,182,183,5,
  	29,0,0,183,184,3,36,18,0,184,185,3,18,9,0,185,31,1,0,0,0,186,193,3,40,
  	20,0,187,193,3,42,21,0,188,189,5,4,0,0,189,190,3,36,18,0,190,191,5,5,
  	0,0,191,193,1,0,0,0,192,186,1,0,0,0,192,187,1,0,0,0,192,188,1,0,0,0,193,
  	33,1,0,0,0,194,195,6,17,-1,0,195,196,3,32,16,0,196,213,1,0,0,0,197,198,
  	10,3,0,0,198,200,5,4,0,0,199,201,3,38,19,0,200,199,1,0,0,0,200,201,1,
  	0,0,0,201,202,1,0,0,0,202,212,5,5,0,0,203,204,10,2,0,0,204,205,5,30,0,
  	0,205,206,3,36,18,0,206,207,5,31,0,0,207,212,1,0,0,0,208,209,10,1,0,0,
  	209,210,5,32,0,0,210,212,3,42,21,0,211,197,1,0,0,0,211,203,1,0,0,0,211,
  	208,1,0,0,0,212,215,1,0,0,0,213,211,1,0,0,0,213,214,1,0,0,0,214,35,1,
  	0,0,0,215,213,1,0,0,0,216,217,6,18,-1,0,217,221,3,34,17,0,218,219,7,1,
  	0,0,219,221,3,36,18,7,220,216,1,0,0,0,220,218,1,0,0,0,221,242,1,0,0,0,
  	222,223,10,6,0,0,223,224,7,2,0,0,224,241,3,36,18,7,225,226,10,5,0,0,226,
  	227,7,3,0,0,227,241,3,36,18,6,228,229,10,4,0,0,229,230,7,4,0,0,230,241,
  	3,36,18,5,231,232,10,3,0,0,232,233,7,5,0,0,233,241,3,36,18,4,234,235,
  	10,2,0,0,235,236,5,45,0,0,236,241,3,36,18,3,237,238,10,1,0,0,238,239,
  	5,46,0,0,239,241,3,36,18,2,240,222,1,0,0,0,240,225,1,0,0,0,240,228,1,
  	0,0,0,240,231,1,0,0,0,240,234,1,0,0,0,240,237,1,0,0,0,241,244,1,0,0,0,
  	242,240,1,0,0,0,242,243,1,0,0,0,243,37,1,0,0,0,244,242,1,0,0,0,245,250,
  	3,36,18,0,246,247,5,8,0,0,247,249,3,36,18,0,248,246,1,0,0,0,249,252,1,
  	0,0,0,250,248,1,0,0,0,250,251,1,0,0,0,251,39,1,0,0,0,252,250,1,0,0,0,
  	253,258,5,47,0,0,254,258,5,48,0,0,255,258,5,49,0,0,256,258,5,50,0,0,257,
  	253,1,0,0,0,257,254,1,0,0,0,257,255,1,0,0,0,257,256,1,0,0,0,258,41,1,
  	0,0,0,259,260,5,51,0,0,260,43,1,0,0,0,25,47,53,65,71,77,89,101,108,117,
  	123,143,149,159,169,173,180,192,200,211,213,220,240,242,250,257
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  mlwParserStaticData = std::move(staticData);
}

}

MLWParser::MLWParser(TokenStream *input) : MLWParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

MLWParser::MLWParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  MLWParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *mlwParserStaticData->atn, mlwParserStaticData->decisionToDFA, mlwParserStaticData->sharedContextCache, options);
}

MLWParser::~MLWParser() {
  delete _interpreter;
}

const atn::ATN& MLWParser::getATN() const {
  return *mlwParserStaticData->atn;
}

std::string MLWParser::getGrammarFileName() const {
  return "MLW.g4";
}

const std::vector<std::string>& MLWParser::getRuleNames() const {
  return mlwParserStaticData->ruleNames;
}

const dfa::Vocabulary& MLWParser::getVocabulary() const {
  return mlwParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView MLWParser::getSerializedATN() const {
  return mlwParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

MLWParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MLWParser::ProgramContext::EOF() {
  return getToken(MLWParser::EOF, 0);
}

std::vector<MLWParser::LinkerstatementContext *> MLWParser::ProgramContext::linkerstatement() {
  return getRuleContexts<MLWParser::LinkerstatementContext>();
}

MLWParser::LinkerstatementContext* MLWParser::ProgramContext::linkerstatement(size_t i) {
  return getRuleContext<MLWParser::LinkerstatementContext>(i);
}

std::vector<MLWParser::FunctionDefinitionContext *> MLWParser::ProgramContext::functionDefinition() {
  return getRuleContexts<MLWParser::FunctionDefinitionContext>();
}

MLWParser::FunctionDefinitionContext* MLWParser::ProgramContext::functionDefinition(size_t i) {
  return getRuleContext<MLWParser::FunctionDefinitionContext>(i);
}


size_t MLWParser::ProgramContext::getRuleIndex() const {
  return MLWParser::RuleProgram;
}

void MLWParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void MLWParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}

MLWParser::ProgramContext* MLWParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, MLWParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(47);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MLWParser::T__0) {
      setState(44);
      linkerstatement();
      setState(49);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(51); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(50);
      functionDefinition();
      setState(53); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == MLWParser::T__6);
    setState(55);
    match(MLWParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LinkerstatementContext ------------------------------------------------------------------

MLWParser::LinkerstatementContext::LinkerstatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MLWParser::LinkerstatementContext::getRuleIndex() const {
  return MLWParser::RuleLinkerstatement;
}

void MLWParser::LinkerstatementContext::copyFrom(LinkerstatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExternStatementContext ------------------------------------------------------------------

MLWParser::IdentifierContext* MLWParser::ExternStatementContext::identifier() {
  return getRuleContext<MLWParser::IdentifierContext>(0);
}

MLWParser::TypeContext* MLWParser::ExternStatementContext::type() {
  return getRuleContext<MLWParser::TypeContext>(0);
}

MLWParser::ParameterList_typeonlyContext* MLWParser::ExternStatementContext::parameterList_typeonly() {
  return getRuleContext<MLWParser::ParameterList_typeonlyContext>(0);
}

MLWParser::ExternStatementContext::ExternStatementContext(LinkerstatementContext *ctx) { copyFrom(ctx); }

void MLWParser::ExternStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExternStatement(this);
}
void MLWParser::ExternStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExternStatement(this);
}
//----------------- ImportStatementContext ------------------------------------------------------------------

MLWParser::IdentifierContext* MLWParser::ImportStatementContext::identifier() {
  return getRuleContext<MLWParser::IdentifierContext>(0);
}

MLWParser::ImportStatementContext::ImportStatementContext(LinkerstatementContext *ctx) { copyFrom(ctx); }

void MLWParser::ImportStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportStatement(this);
}
void MLWParser::ImportStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportStatement(this);
}
MLWParser::LinkerstatementContext* MLWParser::linkerstatement() {
  LinkerstatementContext *_localctx = _tracker.createInstance<LinkerstatementContext>(_ctx, getState());
  enterRule(_localctx, 2, MLWParser::RuleLinkerstatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(71);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<MLWParser::ImportStatementContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(57);
      match(MLWParser::T__0);
      setState(58);
      match(MLWParser::T__1);
      setState(59);
      identifier();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<MLWParser::ExternStatementContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(60);
      match(MLWParser::T__0);
      setState(61);
      match(MLWParser::T__2);
      setState(62);
      identifier();
      setState(63);
      match(MLWParser::T__3);
      setState(65);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2251799813815296) != 0)) {
        setState(64);
        parameterList_typeonly();
      }
      setState(67);
      match(MLWParser::T__4);
      setState(68);
      match(MLWParser::T__5);
      setState(69);
      type();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDefinitionContext ------------------------------------------------------------------

MLWParser::FunctionDefinitionContext::FunctionDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MLWParser::IdentifierContext* MLWParser::FunctionDefinitionContext::identifier() {
  return getRuleContext<MLWParser::IdentifierContext>(0);
}

MLWParser::TypeContext* MLWParser::FunctionDefinitionContext::type() {
  return getRuleContext<MLWParser::TypeContext>(0);
}

MLWParser::BlockContext* MLWParser::FunctionDefinitionContext::block() {
  return getRuleContext<MLWParser::BlockContext>(0);
}

MLWParser::ParameterListContext* MLWParser::FunctionDefinitionContext::parameterList() {
  return getRuleContext<MLWParser::ParameterListContext>(0);
}


size_t MLWParser::FunctionDefinitionContext::getRuleIndex() const {
  return MLWParser::RuleFunctionDefinition;
}

void MLWParser::FunctionDefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDefinition(this);
}

void MLWParser::FunctionDefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDefinition(this);
}

MLWParser::FunctionDefinitionContext* MLWParser::functionDefinition() {
  FunctionDefinitionContext *_localctx = _tracker.createInstance<FunctionDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 4, MLWParser::RuleFunctionDefinition);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(73);
    match(MLWParser::T__6);
    setState(74);
    identifier();
    setState(75);
    match(MLWParser::T__3);
    setState(77);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MLWParser::Identifier) {
      setState(76);
      parameterList();
    }
    setState(79);
    match(MLWParser::T__4);
    setState(80);
    match(MLWParser::T__5);
    setState(81);
    type();
    setState(82);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterListContext ------------------------------------------------------------------

MLWParser::ParameterListContext::ParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MLWParser::ParameterContext *> MLWParser::ParameterListContext::parameter() {
  return getRuleContexts<MLWParser::ParameterContext>();
}

MLWParser::ParameterContext* MLWParser::ParameterListContext::parameter(size_t i) {
  return getRuleContext<MLWParser::ParameterContext>(i);
}


size_t MLWParser::ParameterListContext::getRuleIndex() const {
  return MLWParser::RuleParameterList;
}

void MLWParser::ParameterListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterList(this);
}

void MLWParser::ParameterListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterList(this);
}

MLWParser::ParameterListContext* MLWParser::parameterList() {
  ParameterListContext *_localctx = _tracker.createInstance<ParameterListContext>(_ctx, getState());
  enterRule(_localctx, 6, MLWParser::RuleParameterList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(84);
    parameter();
    setState(89);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MLWParser::T__7) {
      setState(85);
      match(MLWParser::T__7);
      setState(86);
      parameter();
      setState(91);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterContext ------------------------------------------------------------------

MLWParser::ParameterContext::ParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MLWParser::IdentifierContext* MLWParser::ParameterContext::identifier() {
  return getRuleContext<MLWParser::IdentifierContext>(0);
}

MLWParser::TypeContext* MLWParser::ParameterContext::type() {
  return getRuleContext<MLWParser::TypeContext>(0);
}


size_t MLWParser::ParameterContext::getRuleIndex() const {
  return MLWParser::RuleParameter;
}

void MLWParser::ParameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter(this);
}

void MLWParser::ParameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter(this);
}

MLWParser::ParameterContext* MLWParser::parameter() {
  ParameterContext *_localctx = _tracker.createInstance<ParameterContext>(_ctx, getState());
  enterRule(_localctx, 8, MLWParser::RuleParameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(92);
    identifier();
    setState(93);
    match(MLWParser::T__8);
    setState(94);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterList_typeonlyContext ------------------------------------------------------------------

MLWParser::ParameterList_typeonlyContext::ParameterList_typeonlyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MLWParser::Parameter_typeonlyContext *> MLWParser::ParameterList_typeonlyContext::parameter_typeonly() {
  return getRuleContexts<MLWParser::Parameter_typeonlyContext>();
}

MLWParser::Parameter_typeonlyContext* MLWParser::ParameterList_typeonlyContext::parameter_typeonly(size_t i) {
  return getRuleContext<MLWParser::Parameter_typeonlyContext>(i);
}


size_t MLWParser::ParameterList_typeonlyContext::getRuleIndex() const {
  return MLWParser::RuleParameterList_typeonly;
}

void MLWParser::ParameterList_typeonlyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterList_typeonly(this);
}

void MLWParser::ParameterList_typeonlyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterList_typeonly(this);
}

MLWParser::ParameterList_typeonlyContext* MLWParser::parameterList_typeonly() {
  ParameterList_typeonlyContext *_localctx = _tracker.createInstance<ParameterList_typeonlyContext>(_ctx, getState());
  enterRule(_localctx, 10, MLWParser::RuleParameterList_typeonly);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(96);
    parameter_typeonly();
    setState(101);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MLWParser::T__7) {
      setState(97);
      match(MLWParser::T__7);
      setState(98);
      parameter_typeonly();
      setState(103);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parameter_typeonlyContext ------------------------------------------------------------------

MLWParser::Parameter_typeonlyContext::Parameter_typeonlyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MLWParser::TypeContext* MLWParser::Parameter_typeonlyContext::type() {
  return getRuleContext<MLWParser::TypeContext>(0);
}


size_t MLWParser::Parameter_typeonlyContext::getRuleIndex() const {
  return MLWParser::RuleParameter_typeonly;
}

void MLWParser::Parameter_typeonlyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter_typeonly(this);
}

void MLWParser::Parameter_typeonlyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter_typeonly(this);
}

MLWParser::Parameter_typeonlyContext* MLWParser::parameter_typeonly() {
  Parameter_typeonlyContext *_localctx = _tracker.createInstance<Parameter_typeonlyContext>(_ctx, getState());
  enterRule(_localctx, 12, MLWParser::RuleParameter_typeonly);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(104);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

MLWParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MLWParser::PrimitiveTypeContext* MLWParser::TypeContext::primitiveType() {
  return getRuleContext<MLWParser::PrimitiveTypeContext>(0);
}

MLWParser::IdentifierContext* MLWParser::TypeContext::identifier() {
  return getRuleContext<MLWParser::IdentifierContext>(0);
}


size_t MLWParser::TypeContext::getRuleIndex() const {
  return MLWParser::RuleType;
}

void MLWParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void MLWParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}

MLWParser::TypeContext* MLWParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 14, MLWParser::RuleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(108);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MLWParser::T__9:
      case MLWParser::T__10:
      case MLWParser::T__11:
      case MLWParser::T__12:
      case MLWParser::T__13:
      case MLWParser::T__14:
      case MLWParser::T__15: {
        enterOuterAlt(_localctx, 1);
        setState(106);
        primitiveType();
        break;
      }

      case MLWParser::Identifier: {
        enterOuterAlt(_localctx, 2);
        setState(107);
        identifier();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimitiveTypeContext ------------------------------------------------------------------

MLWParser::PrimitiveTypeContext::PrimitiveTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MLWParser::PrimitiveTypeContext::getRuleIndex() const {
  return MLWParser::RulePrimitiveType;
}

void MLWParser::PrimitiveTypeContext::copyFrom(PrimitiveTypeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Float32TypeContext ------------------------------------------------------------------

MLWParser::Float32TypeContext::Float32TypeContext(PrimitiveTypeContext *ctx) { copyFrom(ctx); }

void MLWParser::Float32TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFloat32Type(this);
}
void MLWParser::Float32TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFloat32Type(this);
}
//----------------- VoidTypeContext ------------------------------------------------------------------

MLWParser::VoidTypeContext::VoidTypeContext(PrimitiveTypeContext *ctx) { copyFrom(ctx); }

void MLWParser::VoidTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVoidType(this);
}
void MLWParser::VoidTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVoidType(this);
}
//----------------- BoolTypeContext ------------------------------------------------------------------

MLWParser::BoolTypeContext::BoolTypeContext(PrimitiveTypeContext *ctx) { copyFrom(ctx); }

void MLWParser::BoolTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolType(this);
}
void MLWParser::BoolTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolType(this);
}
//----------------- Float64TypeContext ------------------------------------------------------------------

MLWParser::Float64TypeContext::Float64TypeContext(PrimitiveTypeContext *ctx) { copyFrom(ctx); }

void MLWParser::Float64TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFloat64Type(this);
}
void MLWParser::Float64TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFloat64Type(this);
}
//----------------- Int64TypeContext ------------------------------------------------------------------

MLWParser::Int64TypeContext::Int64TypeContext(PrimitiveTypeContext *ctx) { copyFrom(ctx); }

void MLWParser::Int64TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInt64Type(this);
}
void MLWParser::Int64TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInt64Type(this);
}
//----------------- StringTypeContext ------------------------------------------------------------------

MLWParser::StringTypeContext::StringTypeContext(PrimitiveTypeContext *ctx) { copyFrom(ctx); }

void MLWParser::StringTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStringType(this);
}
void MLWParser::StringTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStringType(this);
}
//----------------- Int32TypeContext ------------------------------------------------------------------

MLWParser::Int32TypeContext::Int32TypeContext(PrimitiveTypeContext *ctx) { copyFrom(ctx); }

void MLWParser::Int32TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInt32Type(this);
}
void MLWParser::Int32TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInt32Type(this);
}
MLWParser::PrimitiveTypeContext* MLWParser::primitiveType() {
  PrimitiveTypeContext *_localctx = _tracker.createInstance<PrimitiveTypeContext>(_ctx, getState());
  enterRule(_localctx, 16, MLWParser::RulePrimitiveType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(117);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MLWParser::T__9: {
        _localctx = _tracker.createInstance<MLWParser::Int32TypeContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(110);
        match(MLWParser::T__9);
        break;
      }

      case MLWParser::T__10: {
        _localctx = _tracker.createInstance<MLWParser::Int64TypeContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(111);
        match(MLWParser::T__10);
        break;
      }

      case MLWParser::T__11: {
        _localctx = _tracker.createInstance<MLWParser::Float32TypeContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(112);
        match(MLWParser::T__11);
        break;
      }

      case MLWParser::T__12: {
        _localctx = _tracker.createInstance<MLWParser::Float64TypeContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(113);
        match(MLWParser::T__12);
        break;
      }

      case MLWParser::T__13: {
        _localctx = _tracker.createInstance<MLWParser::StringTypeContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(114);
        match(MLWParser::T__13);
        break;
      }

      case MLWParser::T__14: {
        _localctx = _tracker.createInstance<MLWParser::BoolTypeContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(115);
        match(MLWParser::T__14);
        break;
      }

      case MLWParser::T__15: {
        _localctx = _tracker.createInstance<MLWParser::VoidTypeContext>(_localctx);
        enterOuterAlt(_localctx, 7);
        setState(116);
        match(MLWParser::T__15);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

MLWParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MLWParser::StatementContext *> MLWParser::BlockContext::statement() {
  return getRuleContexts<MLWParser::StatementContext>();
}

MLWParser::StatementContext* MLWParser::BlockContext::statement(size_t i) {
  return getRuleContext<MLWParser::StatementContext>(i);
}


size_t MLWParser::BlockContext::getRuleIndex() const {
  return MLWParser::RuleBlock;
}

void MLWParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void MLWParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}

MLWParser::BlockContext* MLWParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 18, MLWParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(119);
    match(MLWParser::T__16);
    setState(123);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4362888648196114) != 0)) {
      setState(120);
      statement();
      setState(125);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(126);
    match(MLWParser::T__17);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

MLWParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MLWParser::StatementContext::getRuleIndex() const {
  return MLWParser::RuleStatement;
}

void MLWParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- IfStatementContext ------------------------------------------------------------------

MLWParser::IfStmtContext* MLWParser::IfStatementContext::ifStmt() {
  return getRuleContext<MLWParser::IfStmtContext>(0);
}

MLWParser::IfStatementContext::IfStatementContext(StatementContext *ctx) { copyFrom(ctx); }

void MLWParser::IfStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStatement(this);
}
void MLWParser::IfStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStatement(this);
}
//----------------- AssignmentStatementContext ------------------------------------------------------------------

MLWParser::AssignmentContext* MLWParser::AssignmentStatementContext::assignment() {
  return getRuleContext<MLWParser::AssignmentContext>(0);
}

MLWParser::AssignmentStatementContext::AssignmentStatementContext(StatementContext *ctx) { copyFrom(ctx); }

void MLWParser::AssignmentStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentStatement(this);
}
void MLWParser::AssignmentStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentStatement(this);
}
//----------------- ExprStatementContext ------------------------------------------------------------------

MLWParser::ExpressionContext* MLWParser::ExprStatementContext::expression() {
  return getRuleContext<MLWParser::ExpressionContext>(0);
}

MLWParser::ExprStatementContext::ExprStatementContext(StatementContext *ctx) { copyFrom(ctx); }

void MLWParser::ExprStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprStatement(this);
}
void MLWParser::ExprStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprStatement(this);
}
//----------------- ReturnStatementContext ------------------------------------------------------------------

MLWParser::RetStmtContext* MLWParser::ReturnStatementContext::retStmt() {
  return getRuleContext<MLWParser::RetStmtContext>(0);
}

MLWParser::ReturnStatementContext::ReturnStatementContext(StatementContext *ctx) { copyFrom(ctx); }

void MLWParser::ReturnStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStatement(this);
}
void MLWParser::ReturnStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStatement(this);
}
//----------------- BlockStatementContext ------------------------------------------------------------------

MLWParser::BlockContext* MLWParser::BlockStatementContext::block() {
  return getRuleContext<MLWParser::BlockContext>(0);
}

MLWParser::BlockStatementContext::BlockStatementContext(StatementContext *ctx) { copyFrom(ctx); }

void MLWParser::BlockStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockStatement(this);
}
void MLWParser::BlockStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockStatement(this);
}
//----------------- WhileStatementContext ------------------------------------------------------------------

MLWParser::WhileStmtContext* MLWParser::WhileStatementContext::whileStmt() {
  return getRuleContext<MLWParser::WhileStmtContext>(0);
}

MLWParser::WhileStatementContext::WhileStatementContext(StatementContext *ctx) { copyFrom(ctx); }

void MLWParser::WhileStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileStatement(this);
}
void MLWParser::WhileStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileStatement(this);
}
//----------------- VarDeclStatementContext ------------------------------------------------------------------

MLWParser::VariableDeclarationContext* MLWParser::VarDeclStatementContext::variableDeclaration() {
  return getRuleContext<MLWParser::VariableDeclarationContext>(0);
}

MLWParser::VarDeclStatementContext::VarDeclStatementContext(StatementContext *ctx) { copyFrom(ctx); }

void MLWParser::VarDeclStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDeclStatement(this);
}
void MLWParser::VarDeclStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDeclStatement(this);
}
MLWParser::StatementContext* MLWParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 20, MLWParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(143);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<MLWParser::VarDeclStatementContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(128);
      variableDeclaration();
      setState(129);
      match(MLWParser::T__18);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<MLWParser::AssignmentStatementContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(131);
      assignment();
      setState(132);
      match(MLWParser::T__18);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<MLWParser::ExprStatementContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(134);
      expression(0);
      setState(135);
      match(MLWParser::T__18);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<MLWParser::ReturnStatementContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(137);
      retStmt();
      setState(138);
      match(MLWParser::T__18);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<MLWParser::IfStatementContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(140);
      ifStmt();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<MLWParser::WhileStatementContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(141);
      whileStmt();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<MLWParser::BlockStatementContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(142);
      block();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationContext ------------------------------------------------------------------

MLWParser::VariableDeclarationContext::VariableDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MLWParser::VariableDeclarationContext::getRuleIndex() const {
  return MLWParser::RuleVariableDeclaration;
}

void MLWParser::VariableDeclarationContext::copyFrom(VariableDeclarationContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- VarDeclWithoutInitContext ------------------------------------------------------------------

MLWParser::IdentifierContext* MLWParser::VarDeclWithoutInitContext::identifier() {
  return getRuleContext<MLWParser::IdentifierContext>(0);
}

MLWParser::TypeContext* MLWParser::VarDeclWithoutInitContext::type() {
  return getRuleContext<MLWParser::TypeContext>(0);
}

MLWParser::VarDeclWithoutInitContext::VarDeclWithoutInitContext(VariableDeclarationContext *ctx) { copyFrom(ctx); }

void MLWParser::VarDeclWithoutInitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDeclWithoutInit(this);
}
void MLWParser::VarDeclWithoutInitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDeclWithoutInit(this);
}
//----------------- VarDeclWithInitContext ------------------------------------------------------------------

MLWParser::IdentifierContext* MLWParser::VarDeclWithInitContext::identifier() {
  return getRuleContext<MLWParser::IdentifierContext>(0);
}

MLWParser::ExpressionContext* MLWParser::VarDeclWithInitContext::expression() {
  return getRuleContext<MLWParser::ExpressionContext>(0);
}

MLWParser::TypeContext* MLWParser::VarDeclWithInitContext::type() {
  return getRuleContext<MLWParser::TypeContext>(0);
}

MLWParser::VarDeclWithInitContext::VarDeclWithInitContext(VariableDeclarationContext *ctx) { copyFrom(ctx); }

void MLWParser::VarDeclWithInitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDeclWithInit(this);
}
void MLWParser::VarDeclWithInitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDeclWithInit(this);
}
MLWParser::VariableDeclarationContext* MLWParser::variableDeclaration() {
  VariableDeclarationContext *_localctx = _tracker.createInstance<VariableDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 22, MLWParser::RuleVariableDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(159);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<MLWParser::VarDeclWithInitContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(145);
      match(MLWParser::T__19);
      setState(146);
      identifier();
      setState(149);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MLWParser::T__8) {
        setState(147);
        match(MLWParser::T__8);
        setState(148);
        type();
      }
      setState(151);
      match(MLWParser::T__20);
      setState(152);
      expression(0);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<MLWParser::VarDeclWithoutInitContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(154);
      match(MLWParser::T__19);
      setState(155);
      identifier();
      setState(156);
      match(MLWParser::T__8);
      setState(157);
      type();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

MLWParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MLWParser::AssignmentContext::getRuleIndex() const {
  return MLWParser::RuleAssignment;
}

void MLWParser::AssignmentContext::copyFrom(AssignmentContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SimpleAssignmentContext ------------------------------------------------------------------

MLWParser::IdentifierContext* MLWParser::SimpleAssignmentContext::identifier() {
  return getRuleContext<MLWParser::IdentifierContext>(0);
}

MLWParser::ExpressionContext* MLWParser::SimpleAssignmentContext::expression() {
  return getRuleContext<MLWParser::ExpressionContext>(0);
}

MLWParser::SimpleAssignmentContext::SimpleAssignmentContext(AssignmentContext *ctx) { copyFrom(ctx); }

void MLWParser::SimpleAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimpleAssignment(this);
}
void MLWParser::SimpleAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimpleAssignment(this);
}
//----------------- CompoundAssignmentContext ------------------------------------------------------------------

MLWParser::IdentifierContext* MLWParser::CompoundAssignmentContext::identifier() {
  return getRuleContext<MLWParser::IdentifierContext>(0);
}

MLWParser::ExpressionContext* MLWParser::CompoundAssignmentContext::expression() {
  return getRuleContext<MLWParser::ExpressionContext>(0);
}

MLWParser::CompoundAssignmentContext::CompoundAssignmentContext(AssignmentContext *ctx) { copyFrom(ctx); }

void MLWParser::CompoundAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompoundAssignment(this);
}
void MLWParser::CompoundAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompoundAssignment(this);
}
MLWParser::AssignmentContext* MLWParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 24, MLWParser::RuleAssignment);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(169);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<MLWParser::SimpleAssignmentContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(161);
      identifier();
      setState(162);
      match(MLWParser::T__20);
      setState(163);
      expression(0);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<MLWParser::CompoundAssignmentContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(165);
      identifier();
      setState(166);
      antlrcpp::downCast<CompoundAssignmentContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 62914560) != 0))) {
        antlrcpp::downCast<CompoundAssignmentContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(167);
      expression(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RetStmtContext ------------------------------------------------------------------

MLWParser::RetStmtContext::RetStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MLWParser::ExpressionContext* MLWParser::RetStmtContext::expression() {
  return getRuleContext<MLWParser::ExpressionContext>(0);
}


size_t MLWParser::RetStmtContext::getRuleIndex() const {
  return MLWParser::RuleRetStmt;
}

void MLWParser::RetStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRetStmt(this);
}

void MLWParser::RetStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRetStmt(this);
}

MLWParser::RetStmtContext* MLWParser::retStmt() {
  RetStmtContext *_localctx = _tracker.createInstance<RetStmtContext>(_ctx, getState());
  enterRule(_localctx, 26, MLWParser::RuleRetStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(171);
    match(MLWParser::T__25);
    setState(173);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4362887908818962) != 0)) {
      setState(172);
      expression(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStmtContext ------------------------------------------------------------------

MLWParser::IfStmtContext::IfStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MLWParser::ExpressionContext* MLWParser::IfStmtContext::expression() {
  return getRuleContext<MLWParser::ExpressionContext>(0);
}

std::vector<MLWParser::BlockContext *> MLWParser::IfStmtContext::block() {
  return getRuleContexts<MLWParser::BlockContext>();
}

MLWParser::BlockContext* MLWParser::IfStmtContext::block(size_t i) {
  return getRuleContext<MLWParser::BlockContext>(i);
}


size_t MLWParser::IfStmtContext::getRuleIndex() const {
  return MLWParser::RuleIfStmt;
}

void MLWParser::IfStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStmt(this);
}

void MLWParser::IfStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStmt(this);
}

MLWParser::IfStmtContext* MLWParser::ifStmt() {
  IfStmtContext *_localctx = _tracker.createInstance<IfStmtContext>(_ctx, getState());
  enterRule(_localctx, 28, MLWParser::RuleIfStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(175);
    match(MLWParser::T__26);
    setState(176);
    expression(0);
    setState(177);
    block();
    setState(180);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MLWParser::T__27) {
      setState(178);
      match(MLWParser::T__27);
      setState(179);
      block();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStmtContext ------------------------------------------------------------------

MLWParser::WhileStmtContext::WhileStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MLWParser::ExpressionContext* MLWParser::WhileStmtContext::expression() {
  return getRuleContext<MLWParser::ExpressionContext>(0);
}

MLWParser::BlockContext* MLWParser::WhileStmtContext::block() {
  return getRuleContext<MLWParser::BlockContext>(0);
}


size_t MLWParser::WhileStmtContext::getRuleIndex() const {
  return MLWParser::RuleWhileStmt;
}

void MLWParser::WhileStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileStmt(this);
}

void MLWParser::WhileStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileStmt(this);
}

MLWParser::WhileStmtContext* MLWParser::whileStmt() {
  WhileStmtContext *_localctx = _tracker.createInstance<WhileStmtContext>(_ctx, getState());
  enterRule(_localctx, 30, MLWParser::RuleWhileStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(182);
    match(MLWParser::T__28);
    setState(183);
    expression(0);
    setState(184);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimaryExpressionContext ------------------------------------------------------------------

MLWParser::PrimaryExpressionContext::PrimaryExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MLWParser::PrimaryExpressionContext::getRuleIndex() const {
  return MLWParser::RulePrimaryExpression;
}

void MLWParser::PrimaryExpressionContext::copyFrom(PrimaryExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- IdentifierExprContext ------------------------------------------------------------------

MLWParser::IdentifierContext* MLWParser::IdentifierExprContext::identifier() {
  return getRuleContext<MLWParser::IdentifierContext>(0);
}

MLWParser::IdentifierExprContext::IdentifierExprContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }

void MLWParser::IdentifierExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifierExpr(this);
}
void MLWParser::IdentifierExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifierExpr(this);
}
//----------------- LiteralExprContext ------------------------------------------------------------------

MLWParser::LiteralContext* MLWParser::LiteralExprContext::literal() {
  return getRuleContext<MLWParser::LiteralContext>(0);
}

MLWParser::LiteralExprContext::LiteralExprContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }

void MLWParser::LiteralExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteralExpr(this);
}
void MLWParser::LiteralExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteralExpr(this);
}
//----------------- ParenExprContext ------------------------------------------------------------------

MLWParser::ExpressionContext* MLWParser::ParenExprContext::expression() {
  return getRuleContext<MLWParser::ExpressionContext>(0);
}

MLWParser::ParenExprContext::ParenExprContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }

void MLWParser::ParenExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParenExpr(this);
}
void MLWParser::ParenExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParenExpr(this);
}
MLWParser::PrimaryExpressionContext* MLWParser::primaryExpression() {
  PrimaryExpressionContext *_localctx = _tracker.createInstance<PrimaryExpressionContext>(_ctx, getState());
  enterRule(_localctx, 32, MLWParser::RulePrimaryExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(192);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MLWParser::IntegerLiteral:
      case MLWParser::FloatLiteral:
      case MLWParser::StringLiteral:
      case MLWParser::BooleanLiteral: {
        _localctx = _tracker.createInstance<MLWParser::LiteralExprContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(186);
        literal();
        break;
      }

      case MLWParser::Identifier: {
        _localctx = _tracker.createInstance<MLWParser::IdentifierExprContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(187);
        identifier();
        break;
      }

      case MLWParser::T__3: {
        _localctx = _tracker.createInstance<MLWParser::ParenExprContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(188);
        match(MLWParser::T__3);
        setState(189);
        expression(0);
        setState(190);
        match(MLWParser::T__4);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PostfixExpressionContext ------------------------------------------------------------------

MLWParser::PostfixExpressionContext::PostfixExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MLWParser::PostfixExpressionContext::getRuleIndex() const {
  return MLWParser::RulePostfixExpression;
}

void MLWParser::PostfixExpressionContext::copyFrom(PostfixExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SubscriptExprContext ------------------------------------------------------------------

MLWParser::PostfixExpressionContext* MLWParser::SubscriptExprContext::postfixExpression() {
  return getRuleContext<MLWParser::PostfixExpressionContext>(0);
}

MLWParser::ExpressionContext* MLWParser::SubscriptExprContext::expression() {
  return getRuleContext<MLWParser::ExpressionContext>(0);
}

MLWParser::SubscriptExprContext::SubscriptExprContext(PostfixExpressionContext *ctx) { copyFrom(ctx); }

void MLWParser::SubscriptExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubscriptExpr(this);
}
void MLWParser::SubscriptExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubscriptExpr(this);
}
//----------------- PrimaryPostfixContext ------------------------------------------------------------------

MLWParser::PrimaryExpressionContext* MLWParser::PrimaryPostfixContext::primaryExpression() {
  return getRuleContext<MLWParser::PrimaryExpressionContext>(0);
}

MLWParser::PrimaryPostfixContext::PrimaryPostfixContext(PostfixExpressionContext *ctx) { copyFrom(ctx); }

void MLWParser::PrimaryPostfixContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryPostfix(this);
}
void MLWParser::PrimaryPostfixContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryPostfix(this);
}
//----------------- CallExprContext ------------------------------------------------------------------

MLWParser::PostfixExpressionContext* MLWParser::CallExprContext::postfixExpression() {
  return getRuleContext<MLWParser::PostfixExpressionContext>(0);
}

MLWParser::ArgumentListContext* MLWParser::CallExprContext::argumentList() {
  return getRuleContext<MLWParser::ArgumentListContext>(0);
}

MLWParser::CallExprContext::CallExprContext(PostfixExpressionContext *ctx) { copyFrom(ctx); }

void MLWParser::CallExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCallExpr(this);
}
void MLWParser::CallExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCallExpr(this);
}
//----------------- MemberAccessExprContext ------------------------------------------------------------------

MLWParser::PostfixExpressionContext* MLWParser::MemberAccessExprContext::postfixExpression() {
  return getRuleContext<MLWParser::PostfixExpressionContext>(0);
}

MLWParser::IdentifierContext* MLWParser::MemberAccessExprContext::identifier() {
  return getRuleContext<MLWParser::IdentifierContext>(0);
}

MLWParser::MemberAccessExprContext::MemberAccessExprContext(PostfixExpressionContext *ctx) { copyFrom(ctx); }

void MLWParser::MemberAccessExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMemberAccessExpr(this);
}
void MLWParser::MemberAccessExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMemberAccessExpr(this);
}

MLWParser::PostfixExpressionContext* MLWParser::postfixExpression() {
   return postfixExpression(0);
}

MLWParser::PostfixExpressionContext* MLWParser::postfixExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MLWParser::PostfixExpressionContext *_localctx = _tracker.createInstance<PostfixExpressionContext>(_ctx, parentState);
  MLWParser::PostfixExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, MLWParser::RulePostfixExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<PrimaryPostfixContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(195);
    primaryExpression();
    _ctx->stop = _input->LT(-1);
    setState(213);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(211);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<CallExprContext>(_tracker.createInstance<PostfixExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RulePostfixExpression);
          setState(197);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(198);
          match(MLWParser::T__3);
          setState(200);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 4362887908818962) != 0)) {
            setState(199);
            argumentList();
          }
          setState(202);
          match(MLWParser::T__4);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<SubscriptExprContext>(_tracker.createInstance<PostfixExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RulePostfixExpression);
          setState(203);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(204);
          match(MLWParser::T__29);
          setState(205);
          expression(0);
          setState(206);
          match(MLWParser::T__30);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<MemberAccessExprContext>(_tracker.createInstance<PostfixExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RulePostfixExpression);
          setState(208);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(209);
          match(MLWParser::T__31);
          setState(210);
          identifier();
          break;
        }

        default:
          break;
        } 
      }
      setState(215);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

MLWParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MLWParser::ExpressionContext::getRuleIndex() const {
  return MLWParser::RuleExpression;
}

void MLWParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- PostfixExprContext ------------------------------------------------------------------

MLWParser::PostfixExpressionContext* MLWParser::PostfixExprContext::postfixExpression() {
  return getRuleContext<MLWParser::PostfixExpressionContext>(0);
}

MLWParser::PostfixExprContext::PostfixExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void MLWParser::PostfixExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPostfixExpr(this);
}
void MLWParser::PostfixExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPostfixExpr(this);
}
//----------------- MultiplicativeExprContext ------------------------------------------------------------------

std::vector<MLWParser::ExpressionContext *> MLWParser::MultiplicativeExprContext::expression() {
  return getRuleContexts<MLWParser::ExpressionContext>();
}

MLWParser::ExpressionContext* MLWParser::MultiplicativeExprContext::expression(size_t i) {
  return getRuleContext<MLWParser::ExpressionContext>(i);
}

MLWParser::MultiplicativeExprContext::MultiplicativeExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void MLWParser::MultiplicativeExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiplicativeExpr(this);
}
void MLWParser::MultiplicativeExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiplicativeExpr(this);
}
//----------------- LogicalOrExprContext ------------------------------------------------------------------

std::vector<MLWParser::ExpressionContext *> MLWParser::LogicalOrExprContext::expression() {
  return getRuleContexts<MLWParser::ExpressionContext>();
}

MLWParser::ExpressionContext* MLWParser::LogicalOrExprContext::expression(size_t i) {
  return getRuleContext<MLWParser::ExpressionContext>(i);
}

MLWParser::LogicalOrExprContext::LogicalOrExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void MLWParser::LogicalOrExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalOrExpr(this);
}
void MLWParser::LogicalOrExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalOrExpr(this);
}
//----------------- EqualityExprContext ------------------------------------------------------------------

std::vector<MLWParser::ExpressionContext *> MLWParser::EqualityExprContext::expression() {
  return getRuleContexts<MLWParser::ExpressionContext>();
}

MLWParser::ExpressionContext* MLWParser::EqualityExprContext::expression(size_t i) {
  return getRuleContext<MLWParser::ExpressionContext>(i);
}

MLWParser::EqualityExprContext::EqualityExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void MLWParser::EqualityExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqualityExpr(this);
}
void MLWParser::EqualityExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqualityExpr(this);
}
//----------------- AdditiveExprContext ------------------------------------------------------------------

std::vector<MLWParser::ExpressionContext *> MLWParser::AdditiveExprContext::expression() {
  return getRuleContexts<MLWParser::ExpressionContext>();
}

MLWParser::ExpressionContext* MLWParser::AdditiveExprContext::expression(size_t i) {
  return getRuleContext<MLWParser::ExpressionContext>(i);
}

MLWParser::AdditiveExprContext::AdditiveExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void MLWParser::AdditiveExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdditiveExpr(this);
}
void MLWParser::AdditiveExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdditiveExpr(this);
}
//----------------- RelationalExprContext ------------------------------------------------------------------

std::vector<MLWParser::ExpressionContext *> MLWParser::RelationalExprContext::expression() {
  return getRuleContexts<MLWParser::ExpressionContext>();
}

MLWParser::ExpressionContext* MLWParser::RelationalExprContext::expression(size_t i) {
  return getRuleContext<MLWParser::ExpressionContext>(i);
}

MLWParser::RelationalExprContext::RelationalExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void MLWParser::RelationalExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationalExpr(this);
}
void MLWParser::RelationalExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationalExpr(this);
}
//----------------- UnaryExprContext ------------------------------------------------------------------

MLWParser::ExpressionContext* MLWParser::UnaryExprContext::expression() {
  return getRuleContext<MLWParser::ExpressionContext>(0);
}

MLWParser::UnaryExprContext::UnaryExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void MLWParser::UnaryExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryExpr(this);
}
void MLWParser::UnaryExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryExpr(this);
}
//----------------- LogicalAndExprContext ------------------------------------------------------------------

std::vector<MLWParser::ExpressionContext *> MLWParser::LogicalAndExprContext::expression() {
  return getRuleContexts<MLWParser::ExpressionContext>();
}

MLWParser::ExpressionContext* MLWParser::LogicalAndExprContext::expression(size_t i) {
  return getRuleContext<MLWParser::ExpressionContext>(i);
}

MLWParser::LogicalAndExprContext::LogicalAndExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void MLWParser::LogicalAndExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalAndExpr(this);
}
void MLWParser::LogicalAndExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalAndExpr(this);
}

MLWParser::ExpressionContext* MLWParser::expression() {
   return expression(0);
}

MLWParser::ExpressionContext* MLWParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MLWParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  MLWParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 36;
  enterRecursionRule(_localctx, 36, MLWParser::RuleExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(220);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MLWParser::T__3:
      case MLWParser::IntegerLiteral:
      case MLWParser::FloatLiteral:
      case MLWParser::StringLiteral:
      case MLWParser::BooleanLiteral:
      case MLWParser::Identifier: {
        _localctx = _tracker.createInstance<PostfixExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(217);
        postfixExpression(0);
        break;
      }

      case MLWParser::T__0:
      case MLWParser::T__32:
      case MLWParser::T__33: {
        _localctx = _tracker.createInstance<UnaryExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(218);
        antlrcpp::downCast<UnaryExprContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 25769803778) != 0))) {
          antlrcpp::downCast<UnaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(219);
        expression(7);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(242);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(240);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultiplicativeExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(222);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(223);
          antlrcpp::downCast<MultiplicativeExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 240518168576) != 0))) {
            antlrcpp::downCast<MultiplicativeExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(224);
          expression(7);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AdditiveExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(225);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(226);
          antlrcpp::downCast<AdditiveExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MLWParser::T__32

          || _la == MLWParser::T__37)) {
            antlrcpp::downCast<AdditiveExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(227);
          expression(6);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<RelationalExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(228);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(229);
          antlrcpp::downCast<RelationalExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 8246337208320) != 0))) {
            antlrcpp::downCast<RelationalExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(230);
          expression(5);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<EqualityExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(231);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(232);
          antlrcpp::downCast<EqualityExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MLWParser::T__42

          || _la == MLWParser::T__43)) {
            antlrcpp::downCast<EqualityExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(233);
          expression(4);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<LogicalAndExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(234);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(235);
          match(MLWParser::T__44);
          setState(236);
          expression(3);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<LogicalOrExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(237);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(238);
          match(MLWParser::T__45);
          setState(239);
          expression(2);
          break;
        }

        default:
          break;
        } 
      }
      setState(244);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ArgumentListContext ------------------------------------------------------------------

MLWParser::ArgumentListContext::ArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MLWParser::ExpressionContext *> MLWParser::ArgumentListContext::expression() {
  return getRuleContexts<MLWParser::ExpressionContext>();
}

MLWParser::ExpressionContext* MLWParser::ArgumentListContext::expression(size_t i) {
  return getRuleContext<MLWParser::ExpressionContext>(i);
}


size_t MLWParser::ArgumentListContext::getRuleIndex() const {
  return MLWParser::RuleArgumentList;
}

void MLWParser::ArgumentListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgumentList(this);
}

void MLWParser::ArgumentListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgumentList(this);
}

MLWParser::ArgumentListContext* MLWParser::argumentList() {
  ArgumentListContext *_localctx = _tracker.createInstance<ArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 38, MLWParser::RuleArgumentList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(245);
    expression(0);
    setState(250);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MLWParser::T__7) {
      setState(246);
      match(MLWParser::T__7);
      setState(247);
      expression(0);
      setState(252);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

MLWParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MLWParser::LiteralContext::getRuleIndex() const {
  return MLWParser::RuleLiteral;
}

void MLWParser::LiteralContext::copyFrom(LiteralContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- StringLiteralContext ------------------------------------------------------------------

tree::TerminalNode* MLWParser::StringLiteralContext::StringLiteral() {
  return getToken(MLWParser::StringLiteral, 0);
}

MLWParser::StringLiteralContext::StringLiteralContext(LiteralContext *ctx) { copyFrom(ctx); }

void MLWParser::StringLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStringLiteral(this);
}
void MLWParser::StringLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStringLiteral(this);
}
//----------------- BoolLiteralContext ------------------------------------------------------------------

tree::TerminalNode* MLWParser::BoolLiteralContext::BooleanLiteral() {
  return getToken(MLWParser::BooleanLiteral, 0);
}

MLWParser::BoolLiteralContext::BoolLiteralContext(LiteralContext *ctx) { copyFrom(ctx); }

void MLWParser::BoolLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolLiteral(this);
}
void MLWParser::BoolLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolLiteral(this);
}
//----------------- FloatLiteralContext ------------------------------------------------------------------

tree::TerminalNode* MLWParser::FloatLiteralContext::FloatLiteral() {
  return getToken(MLWParser::FloatLiteral, 0);
}

MLWParser::FloatLiteralContext::FloatLiteralContext(LiteralContext *ctx) { copyFrom(ctx); }

void MLWParser::FloatLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFloatLiteral(this);
}
void MLWParser::FloatLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFloatLiteral(this);
}
//----------------- IntLiteralContext ------------------------------------------------------------------

tree::TerminalNode* MLWParser::IntLiteralContext::IntegerLiteral() {
  return getToken(MLWParser::IntegerLiteral, 0);
}

MLWParser::IntLiteralContext::IntLiteralContext(LiteralContext *ctx) { copyFrom(ctx); }

void MLWParser::IntLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntLiteral(this);
}
void MLWParser::IntLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntLiteral(this);
}
MLWParser::LiteralContext* MLWParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 40, MLWParser::RuleLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(257);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MLWParser::IntegerLiteral: {
        _localctx = _tracker.createInstance<MLWParser::IntLiteralContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(253);
        match(MLWParser::IntegerLiteral);
        break;
      }

      case MLWParser::FloatLiteral: {
        _localctx = _tracker.createInstance<MLWParser::FloatLiteralContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(254);
        match(MLWParser::FloatLiteral);
        break;
      }

      case MLWParser::StringLiteral: {
        _localctx = _tracker.createInstance<MLWParser::StringLiteralContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(255);
        match(MLWParser::StringLiteral);
        break;
      }

      case MLWParser::BooleanLiteral: {
        _localctx = _tracker.createInstance<MLWParser::BoolLiteralContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(256);
        match(MLWParser::BooleanLiteral);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierContext ------------------------------------------------------------------

MLWParser::IdentifierContext::IdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MLWParser::IdentifierContext::Identifier() {
  return getToken(MLWParser::Identifier, 0);
}


size_t MLWParser::IdentifierContext::getRuleIndex() const {
  return MLWParser::RuleIdentifier;
}

void MLWParser::IdentifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifier(this);
}

void MLWParser::IdentifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MLWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifier(this);
}

MLWParser::IdentifierContext* MLWParser::identifier() {
  IdentifierContext *_localctx = _tracker.createInstance<IdentifierContext>(_ctx, getState());
  enterRule(_localctx, 42, MLWParser::RuleIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(259);
    match(MLWParser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool MLWParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 17: return postfixExpressionSempred(antlrcpp::downCast<PostfixExpressionContext *>(context), predicateIndex);
    case 18: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool MLWParser::postfixExpressionSempred(PostfixExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 3);
    case 1: return precpred(_ctx, 2);
    case 2: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool MLWParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 6);
    case 4: return precpred(_ctx, 5);
    case 5: return precpred(_ctx, 4);
    case 6: return precpred(_ctx, 3);
    case 7: return precpred(_ctx, 2);
    case 8: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

void MLWParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  mlwParserInitialize();
#else
  ::antlr4::internal::call_once(mlwParserOnceFlag, mlwParserInitialize);
#endif
}
