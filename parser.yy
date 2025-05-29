/* Skeleton and definitions for generating a LALR(1) parser in C++ */
%skeleton "lalr1.cc" 
%defines
%define parse.error verbose
%define api.value.type variant
%define api.token.constructor

/* Required code included before the parser definition begins */
%code requires{
  #include <string>
  #include "./inc/Node.h"
  #define USE_LEX_ONLY false //change this macro to true if you want to isolate the lexer from the parser.
  #define DEBUG true
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
%type <Node *> root main_class id statement expression type operator
%type <Node *> class_declaration var_declaration method_declaration
%type <Node *> class_declaration_list var_declaration_list method_declaration_list statement_list statement_else
%type <Node *> method_arguments method_content

/* Grammar rules section */
/* This section defines the production rules for the language being parsed */
%%
root
  : main_class class_declaration_list END { 
      root = new Node("Root", "", yylineno); 
      root->children.push_back($1);
      root->children.push_back($2);
  }
  ;

main_class
  : PUBLIC CLASS id LB PUBLIC STATIC VOID MAIN LP STRING LS RS id RP LB statement_list RB RB {
    $$ = new Node("main_class", "", yylineno);
    $$->children.push_back($3);
    $$->children.push_back($13);
    $$->children.push_back($16);
  }
  ;

class_declaration_list
  : class_declaration class_declaration_list {
    $$ = new Node("class_decl_lst", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($2);
  }
  | /* empty */ { $$ = new Node(); }

class_declaration
  : CLASS id LB var_declaration_list method_declaration_list RB {
    $$ = new Node("class_decl", "", yylineno);
    $$->children.push_back($2);
    $$->children.push_back($4);
    $$->children.push_back($5);
  }
  ;

var_declaration_list
  : var_declaration var_declaration_list {
    $$ = new Node("var_decl_lst", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($2);
  }
  | /* empty */ { $$ = new Node(); }
  ;

var_declaration
  : type id DELI {
    $$ = new Node("var_decl", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($2);
  }
  ;

method_declaration_list
  : method_declaration method_declaration_list {
    $$ = new Node("method_decl_lst", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($2);
  }
  | /* empty */ { $$ = new Node(); }
  ;

method_declaration
  : PUBLIC type id LP method_arguments RP LB method_content RETURN expression DELI RB {
    $$ = new Node("method_decl", "", yylineno);
    $$->children.push_back($2);
    $$->children.push_back($3);
    $$->children.push_back($5);
    $$->children.push_back($8);
    $$->children.push_back($10);
  }
  ;

method_arguments
  : type id {
    $$ = new Node("method_arg", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($2);
  }
  | method_arguments SEP method_arguments {
    $$ = new Node("method_arg_lst", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  | /* empty */ { $$ = new Node(); }
  ;

method_content
  : var_declaration method_content {
    $$ = new Node("method_content", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($2);
  }
  | statement method_content {
    $$ = new Node("method_content", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($2);
  }
  | /* empty */ { $$ = new Node(); }
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
  : statement statement_list {
    $$ = new Node("statement_lst", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($2);
  }
  | /* empty */ { $$ = new Node(); }
  ;

statement_else
  : ELSE statement {
    $$ = new Node("statement_else", "", yylineno);
    $$->children.push_back($2);
  }
  | /* empty */ { $$ = new Node("", "", yylineno); }
  ;

statement
  : LB statement_list RB {
    $$ = new Node("statement", "sub", yylineno); 
    $$->children.push_back($2);
  }
  | IF LP expression RP statement statement_else {
    $$ = new Node("statement", "if", yylineno);
    $$->children.push_back($3);
    $$->children.push_back($5);
    $$->children.push_back($6);
  }
  | WHILE LP expression RP statement {
    $$ = new Node("statement", "while", yylineno);
    $$->children.push_back($3);
    $$->children.push_back($5);
  } 
  | PRINT LP expression RP DELI {
    $$ = new Node("statement", "print", yylineno);
    $$->children.push_back($3);
  }
  | id ASSIGN_OP expression DELI {
    $$ = new Node("statement", "assign", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  | id LS expression RS ASSIGN_OP expression DELI {
    $$ = new Node("statement", "assign_arr", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
    $$->children.push_back($6);
  }
  ;

expression 
  : expression operator expression {
    $$ = new Node("expression", "operator", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($2);
    $$->children.push_back($3);
  }
  | expression SEP expression {
    $$ = new Node("expression_lst", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  | expression LS expression RS {
    $$ = new Node("expression", "arr", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  | expression ATTR_OP LENGTH {
    $$ = new Node("expression", "length", yylineno);
    $$->children.push_back($1);
  }
  | expression ATTR_OP id LP expression RP {
    $$ = new Node("expression", "attr", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
    $$->children.push_back($5);
  }
  | NUMBER { $$ = new Node("number", std::to_string($1),  yylineno); }
  | BOOL {
    std::string val;
    if ($1) {
      val = "true";
    } else {
      val = "false";
    }

    $$ = new Node("bool", val, yylineno);
  }
  | id {
    $$ = new Node("expression", "id", yylineno);
    $$->children.push_back($1);
  }
  | THIS {
    $$ = new Node("This", "", yylineno);
  }
  | NEW INT LS expression RS {
    $$ = new Node("expression", "arr", yylineno);
    $$->children.push_back($4);
  }
  | NEW id LP RP {
    $$ = new Node("expression", "init", yylineno);
    $$->children.push_back($2);
  }
  | NOT_OP expression {
    $$ = new Node("expression", "not", yylineno);
    $$->children.push_back($2);
  }
  | LP expression RP {
    $$ = new Node("expression", "brackets", yylineno);
    $$->children.push_back($2);
  }
  | /* empty */ { $$ = new Node(); }
  ;

operator
  : ADD_OP { $$ = new Node("operator", "add", yylineno); }
  | SUB_OP { $$ = new Node("operator", "sub", yylineno); }
  | EQ_OP { $$ = new Node("operator", "eq", yylineno); }
  | GT_OP { $$ = new Node("operator", "gt", yylineno); }
  | LT_OP { $$ = new Node("operator", "lt", yylineno); }
  | MULT_OP { $$ = new Node("operator", "mult", yylineno); }
  ;

id 
  : ID { $$ = new Node("id", $1,  yylineno); }
  ;
