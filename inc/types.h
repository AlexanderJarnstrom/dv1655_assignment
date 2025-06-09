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

#endif // !TYPES_H
