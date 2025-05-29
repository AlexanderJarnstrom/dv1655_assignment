#pragma once

#include "Node.h"
#include "symbolTable.h"



/* Checks the scopes oof all the assignments and such things.
 * 
 * @param Node* the root node.
 * @param sym::SymbolTable the the symbol table.
 * */
void scope_check(Node*, sym::SymbolTable&);

/* Checks if everything used is defined.
 *
 * @param Node* the root node of the AST.
 * @param sym::SymbolTable the symbol table.
 * */
void definition_check(Node*, sym::SymbolTable&);

/* Validates the used types..
 *
 * @param Node* the root node of the AST.
 * @param sym::SymbolTable the symbol table.
 * */
void type_check(Node*, sym::SymbolTable&);
