#ifndef H_IR_GEN
#define H_IR_GEN

#include "block_handler.h"
#include "node.h"
#include "symbol_table.h"

/**
 * @brief Generate IR trees.
 *
 * @param root Root node of the AST.
 * @param table Symbol table.
 * @return BlockHandler* the manager of all the blocks.
 */
BlockHandler* generate_ir(Node* root, SymbolTable* table);

#endif  // !H_IR_GEN
