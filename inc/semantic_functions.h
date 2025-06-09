#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "symbol_node.h"
#include "node.h"

void definition_validation(Node*, SymbolNode*);

void type_validation(Node*, SymbolNode*);

#endif // !SEMANTIC_H
