#ifndef TYPES_H
#define TYPES_H

typedef unsigned int hash_t ;

typedef enum {
  ROOT,
  MAIN_CLASS,
  CLASS,
  METHOD,
  STATEMENT,
  EXPRESION,
  VARIABLE,
  OTHER
} node_t;

typedef enum {
  INT,
  INT_ARR,
  STRING,
  STRING_ARR,
  BOOL,
  USER_DEF,
  NONE
} value_t;

enum errCodes
{
  SUCCESS = 0,
  LEXICAL_ERROR = 1,
  SYNTAX_ERROR = 2,
  AST_ERROR = 3,
  SEMANTIC_ERROR = 4,
  SEGMENTATION_FAULT = 139
};

#endif // !TYPES_H
