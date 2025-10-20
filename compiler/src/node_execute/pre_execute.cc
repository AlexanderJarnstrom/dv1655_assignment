#include "../../inc/node_execute.h"

using namespace std;

void
SyRoot::pre_execute(SymbolTable* table)
{
  Symbol t("root", "root", Record::ROOT);
  table->m_scope = new Scope(&t, nullptr);
  table->m_root = table->m_scope;
}
 
void
SyMainClass::pre_execute(SymbolTable* table)
{
  string s_id, s_type;
  Symbol *t;

  s_id = (*this)[0]->value;
  t = new Symbol(s_id, s_id, Record::CLASS);

  table->add_symbol(t);
  table->add_scope(t);
  table->enter_scope(t->m_id);

  t = new Symbol("main", "void", Record::METHOD);
  table->add_symbol(t);
  table->add_scope(t);
  table->enter_scope(t->m_id);

  s_id = (*this)[1]->value;
  t = new Symbol(s_id, "arg_arr", Record::VARIABLE);
  table->add_symbol(t);

  table->exit_scope();
  table->exit_scope();
}

void
SyClass::pre_execute(SymbolTable* table)
{
  string s_id, s_type;
  Symbol* t;

  s_id = (*this)[0]->value;
  t = new Symbol(s_id, s_id, Record::CLASS);

  if (table->m_scope->find(t->m_id, t->m_record))
    table->add_error((*this)[0]->lineno, "Already declared Class: '" + t->m_id + "'");

  table->add_symbol(t);
  table->add_scope(t);
  table->enter_scope(s_id);
}

void
SyMethod::pre_execute(SymbolTable* table)
{
  string s_id, s_type;
  Symbol* t;

  Node* head = (*this)[0];
  s_type = (*head)[0]->value;

  if (s_type == "id")
    s_type = (*(*head)[0])[0]->value;

  s_id = (*head)[1]->value;
  t = new Symbol(s_id, s_type, Record::METHOD);

  if (table->m_scope->find(t->m_id, t->m_record))
      table->add_error((*this)[0]->lineno, "Already declared Method: '" + t->m_id + "'");

  table->add_symbol(t);
  table->add_scope(t);
  table->enter_scope(t->m_id);
}
void
SyVariable::pre_execute(SymbolTable* table)
{
  string s_id, s_type;
  Symbol* t;
  Record type;

  s_type = (*this)[0]->value;

  if (s_type == "id")
    s_type = (*(*this)[0])[0]->value;

  s_id = (*this)[1]->value;

  if (this->type == "method_arg")
    type = Record::ARGUMENT;
  else 
    type = Record::VARIABLE;

  t = new Symbol(s_id, s_type, type);

  if (table->m_scope->find(t->m_id, t->m_record))
    table->add_error((*this)[0]->lineno, "Already declared Variable: '" + t->m_id + "'");

  table->add_symbol(t);
}


