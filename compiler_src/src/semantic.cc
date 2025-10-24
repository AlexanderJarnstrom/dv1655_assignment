#include "../inc/semantic.h"

#include <string>

#include "../inc/node_execute.h"

using namespace std;

/**
 * Runs the first tests and validations while building the table, and continues
 * to the post test after the table is built.
 * */
void Semantic::semantic_analysis(Node* n, SymbolTable* t)
{
  in_check(n, t);
  t->reset();
  post_check(n, t);
}

/**
 * Builds the symbol table and validates everything while building it, like
 * duplication and overall definition in the current scope.
 * */
void Semantic::in_check(Node* n, SymbolTable* table)
{
  // While building table validation.
  n->pre_execute(table);
  // Validate usage, such as assign.
  n->in_execute(table);

  for (Node* c : n->children) in_check(c, table);

  if (dynamic_cast<SyClass*>(n) || dynamic_cast<SyMethod*>(n))
  {
    table->exit_scope();
  }
}

/**
 * Validates types, declearation and usage. Requiers pre built symbol table.
 * */
void Semantic::post_check(Node* n, SymbolTable* table)
{
  if (n->type == "class_decl")
  {
    table->enter_scope((*n)[0]->value);
  }

  for (auto it = n->children.rbegin(); it != n->children.rend(); ++it)
    post_check(*it, table);

  n->post_execute(table);

  if (n->type == "class_decl") table->exit_scope();
}
