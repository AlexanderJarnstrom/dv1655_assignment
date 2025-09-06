/* Skeleton and definitions for generating a LALR(1) parser in C++ */
%skeleton "lalr1.cc"
%require "3.2"
%defines
%define parse.error verbose
%define api.value.type variant
%define api.token.constructor

/* Required code included before the parser definition begins */
%code requires{
  #include <string>
  #include "node.h"
  #include "node_execute.h"
  #define USE_LEX_ONLY false //change this macro to true if you want to isolate the lexer from the parser.
}


/* Code included in the parser implementation file */
%code{
  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;

  Node* root;
  extern int yylineno;
}

/* Token definitions for the grammar */
/* Tokens represent the smallest units of the language, like operators and parentheses */
%token <std::string> BOOLEAN LENGTH SEP LP RP LB RB LS RS VOID STRING NEW INT PUBLIC CLASS STATIC MAIN RETURN THIS DELI
%token <std::string> WHILE IF ELSE PRINT
%token <int> NUMBER
%token <bool> BOOL
%token <std::string> ID;
%token END 0 "end of file"

/* Operator precedence and associativity rules */
/* Used to resolve ambiguities in parsing expressions See https://www.gnu.org/software/bison/manual/bison.html#Precedence-Decl */ 

%left <std::string> ADD_OP SUB_OP MULT_OP
%left <std::string> EQ_OP LT_OP GT_OP NOT_OP
%left <std::string> AND_OP OR_OP ASSIGN_OP ATTR_OP

/* Specify types for non-terminals in the grammar */
/* The type specifies the data type of the values associated with these non-terminals */
%type <Node *> root main_class id statement type operator
%type <Node *> class_declaration var_declaration method_declaration class_content expression_operators
%type <Node *> class_declaration_list var_declaration_list method_declaration_list statement_list
%type <Node *> method_arguments method_content method_head method_body expression_lst expression

/* Grammar rules section */
/* This section defines the production rules for the language being parsed */
%%
root
  : main_class class_declaration_list END { 
      root = new SyRoot("root", "", yylineno); 
      root->children.push_back($1);
      root->children.push_back($2);
  }
  ;

main_class
  : PUBLIC CLASS id LB PUBLIC STATIC VOID MAIN LP STRING LS RS id RP LB statement_list RB RB {
    $$ = new SyMainClass("main_class", "", yylineno);
    $$->children.push_back($3);
    $$->children.push_back($13);
    $$->children.push_back($16);
  }
  ;

class_declaration_list
  : class_declaration
  | class_declaration_list class_declaration_list {
    $$ = new Node("class_decl_lst", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($2);
  }
  ;

class_declaration
  : CLASS id LB class_content RB {
    $$ = new SyClass("class_decl", "", yylineno);
    $$->children.push_back($2);
    $$->children.push_back($4);
  }
  ;

class_content
  : var_declaration_list 
  | method_declaration_list
  | class_content class_content {
    $$ = new Node("class_content", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($2);
  }
  ;

var_declaration_list
  : var_declaration
  | var_declaration var_declaration_list {
    $$ = new Node("var_decl_lst", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($2);
  }
  ;

var_declaration
  : type id DELI {
    $$ = new SyVariable("var_decl", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($2);
  }
  ;

method_declaration_list
  : method_declaration
  | method_declaration_list method_declaration_list {
    $$ = new Node("method_decl_lst", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($2);
  }
  ;

method_declaration
  : method_head LP RP method_body {
    $$ = new SyMethod("method_decl", "declaration", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($4);
  }
  | method_head LP method_arguments RP method_body {
    $$ = new SyMethod("method_decl", "declaration", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
    $$->children.push_back($5);
  } 
  ;

method_head
  : PUBLIC type id {
    $$ = new Node("method_decl", "head", yylineno);
    $$->children.push_back($2);
    $$->children.push_back($3);
  }
  ;
  
method_body
  : LB RETURN expression_operators DELI RB {
    $$ = new Node("method_decl", "body", yylineno);
    $$->children.push_back($3);
  }
  | LB method_content RETURN expression_operators DELI RB {
    $$ = new Node("method_decl", "body", yylineno);
    $$->children.push_back($2);
    $$->children.push_back($4);
  }
  ;

method_arguments
  : type id {
    $$ = new SyVariable("method_arg", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($2);
  }
  | method_arguments SEP method_arguments {
    $$ = new Node("method_arg_lst", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  ;

method_content
  : var_declaration
  | statement
  | method_content method_content {
    $$ = new Node("method_content", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($2);
  }
  ;

type
  : INT LS RS { $$ = new Node("type", "int_arr", yylineno); }
  | BOOLEAN { $$ = new Node("type", "boolean", yylineno); }
  | INT { $$ = new Node("type", "int", yylineno); }
  | id { 
    $$ = new Node("type", "id", yylineno); 
    $$->children.push_back($1);
  }
  ;

statement_list
  : statement
  | statement_list statement_list {
    $$ = new Node("statement_lst", "", yylineno); 
    $$->children.push_back($1);
    $$->children.push_back($2);
  }
  ;

statement
  : LB statement_list RB {
    $$ = new Node("statement", "block", yylineno); 
    $$->children.push_back($2);
  }
  | IF LP expression_operators RP statement {
    $$ = new SyIf("statement", "if", yylineno);
    $$->children.push_back($3);
    $$->children.push_back($5);
  }
  | IF LP expression_operators RP statement ELSE statement {
    $$ = new SyIfElse("statement", "if-else", yylineno);
    $$->children.push_back($3);
    $$->children.push_back($5);
    $$->children.push_back($7);
  }
  | WHILE LP expression_operators RP statement {
    $$ = new SyWhile("statement", "while", yylineno);
    $$->children.push_back($3);
    $$->children.push_back($5);
  } 
  | PRINT LP expression_operators RP DELI {
    $$ = new SyPrint("statement", "print", yylineno);
    $$->children.push_back($3);
  }
  | id ASSIGN_OP expression_operators DELI {
    $$ = new SyAssign("statement", "assign", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  | id LS expression_operators RS ASSIGN_OP expression_operators DELI {
    $$ = new SyAssignArr("statement", "assign_arr", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
    $$->children.push_back($6);
  }
  ;

expression_lst
  : expression_lst SEP expression_lst {
    $$ = new SyExpressionList("expression_lst", "sep", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  | expression_operators
  ;

expression_operators
  : expression_operators operator expression_operators {
    $$ = new SyOperator("expression", "operator", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($2);
    $$->children.push_back($3);
  }
  | expression
  ;



expression
  : expression LS expression_operators RS {
    $$ = new SyArrayPull("expression", "arr", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  | expression ATTR_OP LENGTH {
    $$ = new SyLength("expression", "length", yylineno);
    $$->children.push_back($1);
  }
  | expression ATTR_OP id LP expression_lst RP {
    $$ = new SyAttribute("expression", "attr_exp", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
    $$->children.push_back($5);
  }
  | expression ATTR_OP id LP RP {
    $$ = new SyAttribute("expression", "attr", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  | LP expression_operators RP {
    $$ = new SyParenthesis("expression", "brackets", yylineno);
    $$->children.push_back($2);
  }
  | NUMBER { $$ = new SyNumber("number", std::to_string($1),  yylineno); }
  | BOOL {
    std::string val;
    if ($1) {
      val = "true";
    } else {
      val = "false";
    }

    $$ = new SyBoolean("bool", val, yylineno);
  }
  | id {
    $$ = new SyIdentifier("expression", "id", yylineno);
    $$->children.push_back($1);
  }
  | THIS {
    $$ = new SyThis("expression", "this", yylineno);
  }
  | NEW INT LS expression_operators RS {
    $$ = new SyArrayInit("expression", "arr", yylineno);
    $$->children.push_back($4);
  }
  | NEW id LP RP {
    $$ = new SyObjectInit("expression", "init", yylineno);
    $$->children.push_back($2);
  }
  | NOT_OP expression {
    $$ = new SyNot("expression", "not", yylineno);
    $$->children.push_back($2);
  }
  ;

operator
  : ADD_OP { $$ = new Node("operator", "add", yylineno); }
  | SUB_OP { $$ = new Node("operator", "sub", yylineno); }
  | AND_OP { $$ = new Node("operator", "and", yylineno); }
  | OR_OP { $$ = new Node("operator", "or", yylineno); }
  | EQ_OP { $$ = new Node("operator", "eq", yylineno); }
  | GT_OP { $$ = new Node("operator", "gt", yylineno); }
  | LT_OP { $$ = new Node("operator", "lt", yylineno); }
  | MULT_OP { $$ = new Node("operator", "mult", yylineno); }
  ;

id 
  : ID {
    $$ = new Node("id", $1,  yylineno);
  }
  ;
