grammar MLW;

/* Copyright (c) 2025 Wdboyes13
   SPDX-License-Identifier: Wdboyes13 
   This code is part of the MLW Project 
   MLW Grammar Definition (MLW.g4) */

program: linkerstatement* functionDefinition+ EOF;

linkerstatement:
      '!' 'import' identifier #ImportStatement
    | '!' 'extern' identifier '(' parameterList_typeonly? ')' '->' type #ExternStatement
    ;

functionDefinition:
    'fn' identifier '(' parameterList? ')' '->' type block;

parameterList: parameter (',' parameter)*;
parameter: identifier ':' type;

parameterList_typeonly: parameter_typeonly (',' parameter_typeonly)*;
parameter_typeonly: type;

type:
    primitiveType
  | identifier  // User-defined types
  ;

primitiveType:
    'i32'       #Int32Type
  | 'i64'       #Int64Type
  | 'f32'       #Float32Type
  | 'f64'       #Float64Type
  | 'str'       #StringType
  | 'bool'      #BoolType
  | 'void'      #VoidType
  ;

block: '{' statement* '}';

statement:
    variableDeclaration ';'                         #VarDeclStatement
  | assignment ';'                                  #AssignmentStatement
  | expression ';'                                  #ExprStatement
  | retStmt ';'                                     #ReturnStatement
  | ifStmt                                          #IfStatement
  | whileStmt                                       #WhileStatement
  | block                                           #BlockStatement
  ;

variableDeclaration:
    'var' identifier (':' type)? '=' expression     #VarDeclWithInit
  | 'var' identifier ':' type                       #VarDeclWithoutInit
  ;

assignment:
    identifier '=' expression                       #SimpleAssignment
  | identifier op=('+=' | '-=' | '*=' | '/=') expression #CompoundAssignment
  ;

retStmt: 'return' expression?;

ifStmt:
    'if' expression block ('else' block)?;

whileStmt:
    'while' expression block;

primaryExpression:
    literal                                       #LiteralExpr
  | identifier                                    #IdentifierExpr
  | '(' expression ')'                           #ParenExpr
  ;

postfixExpression:
    primaryExpression                             #PrimaryPostfix
  | postfixExpression '(' argumentList? ')'       #CallExpr
  | postfixExpression '[' expression ']'          #SubscriptExpr
  | postfixExpression '.' identifier              #MemberAccessExpr
  ;

expression:
    postfixExpression                             #PostfixExpr
  | op=('-' | '!' | '~') expression              #UnaryExpr
  | expression op=('*' | '/' | '%') expression   #MultiplicativeExpr
  | expression op=('+' | '-') expression         #AdditiveExpr
  | expression op=('<' | '>' | '<=' | '>=') expression #RelationalExpr
  | expression op=('==' | '!=') expression       #EqualityExpr
  | expression '&&' expression                   #LogicalAndExpr
  | expression '||' expression                   #LogicalOrExpr
  ;

argumentList: expression (',' expression)*;

literal:
    IntegerLiteral     #IntLiteral
  | FloatLiteral       #FloatLiteral
  | StringLiteral      #StringLiteral
  | BooleanLiteral     #BoolLiteral
  ;

identifier: Identifier;

// Lexer rules
IntegerLiteral: [0-9]+;
FloatLiteral: [0-9]+ '.' [0-9]* | '.' [0-9]+;
StringLiteral: '"' (~["\\\r\n] | EscapeSequence)* '"';
BooleanLiteral: 'true' | 'false';

Identifier: [a-zA-Z_][a-zA-Z_0-9]*;

// Escape sequences
fragment EscapeSequence: 
    '\\' [btnfr"'\\]    // \b, \t, \n, \f, \r, \", \', \\
  | '\\u' HexDigit HexDigit HexDigit HexDigit
  | '\\' [0-3]? [0-7] [0-7]?
  ;

fragment HexDigit: [0-9a-fA-F];

// Whitespace and comments
WS: [ \t\r\n]+ -> skip;
LINE_COMMENT: '//' ~[\r\n]* -> skip;
BLOCK_COMMENT: '/*' .*? '*/' -> skip;