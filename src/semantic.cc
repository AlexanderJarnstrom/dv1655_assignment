#include "../inc/semantic.h"
#include "../inc/node_execute.h"
#include <iostream>
#include <string>

using namespace std;

void in_check(Node*, SymbolTable*);
void post_check(Node*, SymbolTable*);

void
semantic_analysis(Node* n, SymbolTable* t)
{
  cout << "Running semantic analysis." << endl;
  in_check(n, t);
  t->reset();
  post_check(n, t);
}

void
in_check(Node* n, SymbolTable* table)
{
  n->pre_execute(table);
  n->in_execute(table);

  for (Node* c : n->children)
    in_check(c, table);

  if (dynamic_cast<SyClass*>(n) || dynamic_cast<SyMethod*>(n))
  {
    table->exit_scope();
  }
}

void
post_check(Node* n, SymbolTable* table)
{
  if (n->type == "class_decl")
  {
    table->enter_scope((*n)[0]->value);
  }

  for (auto it = n->children.rbegin(); it != n->children.rend(); ++it)
    post_check(*it, table);

  n->post_execute(table);

  if (n->type == "class_decl")
    table->exit_scope();
}
