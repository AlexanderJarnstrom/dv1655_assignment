#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "node.h"
#include "symbol_table.h"

namespace Semantic
{
/**
 * Run semantic analysis.
 *
 * @param root node.
 * @param symbol table.
 * */
void semantic_analysis(Node*, SymbolTable*);

/**
 * Pre/during build validation.
 *
 * @param root node.
 * @param symbol table.
 * */
void in_check(Node*, SymbolTable*);

/**
 * Post build validation.
 *
 * @param root node.
 * @param symbol table.
 * */
void post_check(Node*, SymbolTable*);
}  // namespace Semantic

#endif  // !SEMANTIC_H
