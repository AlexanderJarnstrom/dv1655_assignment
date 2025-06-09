#ifndef TYPES_H
#define TYPES_H

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
  BOOL,
  USER_DEF,
  NONE
} value_t;

#endif // !TYPES_H
