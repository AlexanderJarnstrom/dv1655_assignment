#ifndef SEMANTIC_FUNCTIONS
#define SEMANTIC_FUNCTIONS

#include "Node.h"
#include "SymbolTable.h"
#include <string>
 
void analyse(Node* node, std::string scope, SymbolTable* table);

#endif // !SEMANTIC_FUNCTIONS
