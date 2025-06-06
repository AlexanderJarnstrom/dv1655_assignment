%top{
    #include "../inc/parser.tab.h"
    #define YY_DECL yy::parser::symbol_type yylex()
    #include "../inc/node.h"
    int lexical_errors = 0;
}
%option yylineno noyywrap nounput batch noinput stack 
%%

"+"                     {if(USE_LEX_ONLY) {printf("ADD_OP ");} else {return yy::parser::make_ADD_OP(yytext);}}
"-"                     {if(USE_LEX_ONLY) {printf("SUB_OP ");} else {return yy::parser::make_SUB_OP(yytext);}}
"*"                     {if(USE_LEX_ONLY) {printf("MULT_OP ");} else {return yy::parser::make_MULT_OP(yytext);}}
"&&"                    {if(USE_LEX_ONLY) {printf("AND_OP ");}  else {return yy::parser::make_AND_OP(yytext);} }
"||"                    {if(USE_LEX_ONLY) {printf("OR_OP ");}  else {return yy::parser::make_OR_OP(yytext);} }
"<"                     {if(USE_LEX_ONLY) {printf("LT_OP ");}  else {return yy::parser::make_LT_OP(yytext);} }
">"                     {if(USE_LEX_ONLY) {printf("GT_OP ");}  else {return yy::parser::make_GT_OP(yytext);} }
"=="                    {if(USE_LEX_ONLY) {printf("EQ_OP ");}  else {return yy::parser::make_EQ_OP(yytext);} }
"!"                     {if(USE_LEX_ONLY) {printf("NOT_OP ");}  else {return yy::parser::make_NOT_OP(yytext);} }
"="                     {if(USE_LEX_ONLY) {printf("ASSIGN_OP ");}  else {return yy::parser::make_ASSIGN_OP(yytext);} }
";"                     {if(USE_LEX_ONLY) {printf("DELI ");} else {return yy::parser::make_DELI(yytext);}}
"."                     {if(USE_LEX_ONLY) {printf("ATTR_OP ");}  else {return yy::parser::make_ATTR_OP(yytext);} }
"length"                {if(USE_LEX_ONLY) {printf("LENGTH ");}  else {return yy::parser::make_LENGTH(yytext);} }
","                     {if(USE_LEX_ONLY) {printf("SEP ");}  else {return yy::parser::make_SEP(yytext);} }

"("                     {if(USE_LEX_ONLY) {printf("LP ");} else {return yy::parser::make_LP(yytext);}}
")"                     {if(USE_LEX_ONLY) {printf("RP ");} else {return yy::parser::make_RP(yytext);}}
"{"                     {if(USE_LEX_ONLY) {printf("LB ");} else {return yy::parser::make_LB(yytext);} }
"}"                     {if(USE_LEX_ONLY) {printf("RB ");} else {return yy::parser::make_RB(yytext);} }
"["                     {if(USE_LEX_ONLY) {printf("LS ");} else {return yy::parser::make_LS(yytext);}}
"]"                     {if(USE_LEX_ONLY) {printf("RS ");} else {return yy::parser::make_RS(yytext);}}

"int"                   {if(USE_LEX_ONLY) {printf("INT ");} else {return yy::parser::make_INT(yytext);}}
"boolean"               {if(USE_LEX_ONLY) {printf("BOOLEAN ");} else {return yy::parser::make_BOOLEAN(yytext);}}
"String"                {if(USE_LEX_ONLY) {printf("STRING ");} else {return yy::parser::make_STRING(yytext);}}
"void"                  {if(USE_LEX_ONLY) {printf("VOID ");} else {return yy::parser::make_VOID(yytext);}}
"new"                   {if(USE_LEX_ONLY) {printf("NEW ");} else {return yy::parser::make_NEW(yytext);} }
"public"                {if(USE_LEX_ONLY) {printf("PUBLIC ");} else {return yy::parser::make_PUBLIC(yytext);} }
"class"                 {if(USE_LEX_ONLY) {printf("CLASS ");} else {return yy::parser::make_CLASS(yytext);} }
"static"                {if(USE_LEX_ONLY) {printf("STATIC ");} else {return yy::parser::make_STATIC(yytext);} }
"main"                  {if(USE_LEX_ONLY) {printf("MAIN ");} else {return yy::parser::make_MAIN(yytext);} }
"return"                {if(USE_LEX_ONLY) {printf("RETURN ");}  else {return yy::parser::make_RETURN(yytext);} }
"this"                  {if(USE_LEX_ONLY) {printf("THIS ");}  else {return yy::parser::make_THIS(yytext);} }
"while"                 {if(USE_LEX_ONLY) {printf("WHILE ");}  else {return yy::parser::make_WHILE(yytext);} }
"if"                    {if(USE_LEX_ONLY) {printf("IF ");}  else {return yy::parser::make_IF(yytext);} }
"else"                  {if(USE_LEX_ONLY) {printf("ELSE ");}  else {return yy::parser::make_ELSE(yytext);} }
"System.out.println"    {if(USE_LEX_ONLY) {printf("PRINT ");}  else {return yy::parser::make_PRINT(yytext);} }

"true"|"false"          {
                          if(USE_LEX_ONLY) {
                            printf("BOOL (%s) ", yytext);
                          } else {
                            if (strcmp(yytext, "true")) {
                              return yy::parser::make_BOOL(false);
                            } else if (strcmp(yytext, "false")) {
                              return yy::parser::make_BOOL(true);
                            }
                          }
                        }
[A-Za-z][A-Za-z0-9_]*   {if(USE_LEX_ONLY) {printf("ID (%s) ", yytext);} else {return yy::parser::make_ID(yytext);}}
0|[1-9][0-9]*           {if(USE_LEX_ONLY) {printf("NUMBER (%s) ", yytext);} else {return yy::parser::make_NUMBER(atoi(yytext));}}

[ \t\n\r]+              {if(USE_LEX_ONLY) {printf("%s", yytext);}}
"//"[^\n]*              {}
.                       {if(!lexical_errors) fprintf(stderr, "Lexical errors found! See the logs below: \n"); fprintf(stderr,"\t@error at line %d. Character %s is not recognized\n", yylineno, yytext); lexical_errors = 1;}
<<EOF>>                 {return yy::parser::make_END();}
%%

