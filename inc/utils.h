#ifndef UTILS_H
#define UTILS_H

#include "node.h"
#include "symbol_node.h"
#include "types.h"
#include <string>

void print_error(errCodes, int, std::string);

void extract_root(Node*, SymbolNode**);
void extract_class(Node*, SymbolNode**);
void extract_main_class(Node*, SymbolNode**);
void extract_main_class_args(Node*, SymbolNode**);
void extract_statement(Node*, SymbolNode**, int);
void extract_expresion(Node*, SymbolNode**);
void extract_variable(Node*, SymbolNode**);
void extract_method(Node*, SymbolNode**);

#endif // !UTILS_H
