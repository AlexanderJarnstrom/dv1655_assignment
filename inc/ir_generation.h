#ifndef H_IR_GEN
#define H_IR_GEN

#include "block.h"
#include "node.h"
#include "symbol_table.h"

BlockHandler* generate_ir(Node*, SymbolTable*);

#endif // !H_IR_GEN
