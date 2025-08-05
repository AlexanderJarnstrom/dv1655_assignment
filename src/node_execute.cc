#include "../inc/node_execute.h"
#include <iostream>
#include <string>

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
  table->enter_scope(t->m_id);

  t = new Symbol("main", "void", Record::METHOD);
  table->add_symbol(t);
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
  cout << "createing: " << s_id << endl;
  t = new Symbol(s_id, s_id, Record::CLASS);

  if (table->m_scope->find(t->m_id, t->m_record))
    table->add_error((*this)[0]->lineno, "Already declared Class: '" + t->m_id + "'");

  table->add_symbol(t);
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
  table->enter_scope(t->m_id);
}

void
SyMethod::post_execute(SymbolTable* table)
{
  string s_type;
  Node* head = (*this)[0];

  s_type = (*head)[0]->value;

  if (s_type != "id")
    return;

  s_type = (*(*head)[0])[0]->value;

  if (!table->m_root->find(s_type, Record::CLASS))
    table->add_error(lineno, "'" + s_type + "' is undefined.");
}

void
SyVariable::pre_execute(SymbolTable* table)
{
  string s_id, s_type;
  Symbol* t;

  s_type = (*this)[0]->value;

  if (s_type == "id")
    s_type = (*(*this)[0])[0]->value;

  s_id = (*this)[1]->value;
  t = new Symbol(s_id, s_type, Record::VARIABLE);

  if (table->m_scope->find(t->m_id, t->m_record))
    table->add_error((*this)[0]->lineno, "Already declared Variable: '" + t->m_id + "'");

  table->add_symbol(t);
}

void
SyVariable::post_execute(SymbolTable* table)
{
  string s_type;

  s_type = (*this)[0]->value;

  if (s_type != "id")
    return;

  s_type = (*(*this)[0])[0]->value;

  if (!table->m_root->find(s_type, Record::CLASS))
    table->add_error(lineno, "'" + s_type + "' is undefined.");
}

void
SyAssign::in_execute(SymbolTable* table)
{
  string s_id = (*this)[0]->value;

  if (!table->check_scope(s_id, Record::VARIABLE))
    table->add_error(lineno, "definition without declareation: " + s_id);
}

void
SyAssign::post_execute(SymbolTable* table)
{
  string s_type, s_id;
  Symbol *l;

  s_id = (*this)[0]->value;
  table->m_intrest = table->m_scope;
  s_type = (*this)[1]->get_type(table);

  l = table->m_scope->find(s_id);

  if (!l)
    return;

  if (s_type == "")
    return;

  if (l->m_type != s_type)
    table->add_error(lineno, "'" + s_id + "'("
        + l->m_type + ") and '" + s_type + "' are of different types.");
}

void
SyAttribute::post_execute(SymbolTable* table)
{
  string s_id, s_attribute;
  Scope* s;
  Symbol* n;

  if ((*this)[0]->value == "this")
  {
    s = table->m_scope->get_parrent_class();
    s_id = s->m_id;
  }
  else if ((*this)[0]->value == "id")
  {
    s_id = (*(*this)[0])[0]->value;
    n = table->m_root->find(s_id);
    if (!n)
    {
      table->add_error(this->lineno, "variable is not declared: " + s_id);
      return;
    }

    s = table->m_root->get_scope(n->m_type);
    if (!s)
    {
      cout << "Didnt find scope" << endl;
      return;
    }
    table->m_intrest = s;
  }
  else if ((*this)[0]->value == "init")
  {
    s_id = (*(*this)[0])[0]->value;
    s = table->m_root->get_scope(s_id);
    if (!s)
    {
      cout << "Didnt find scope" << endl;
      return;
    }
    table->m_intrest = s;
  }
  else {
    string s_type = (*this)[0]->get_type(table);
    if (s_type == "")
    {
      return;
    }
    
    s = table->m_root->get_scope(s_type);

    if (!s)
    {
      table->add_error(this->lineno, "'" + s_type + "' does not have member: '" + s_id + "'");
      return;
    }
    table->m_intrest = s;
  }

  s_attribute = (*this)[1]->value;
  if (!s->find(s_attribute, Record::METHOD))
    table->add_error(lineno, "'" + s_id + "' does not have attribute: '" + s_attribute + "'");

}

string
SyAttribute::get_type(SymbolTable* table)
{
  string s_id, s_attr;
  s_id = (*this)[0]->get_type(table);
  s_attr = (*this)[1]->value;

  Scope* obj = table->m_root->get_scope(s_id);
  if (!obj)
    return "";

  Symbol* s = obj->find(s_attr, Record::METHOD);
  if (s)
    return s->m_type;

  return "";
}

string
SyOperator::get_type(SymbolTable* table)
{
  Node* op = (*this)[1];
  string s_type = op->value;

  bool b_num, b_bool;

  b_num = s_type == "add";
  b_num = b_num || s_type == "sub";
  b_num = b_num || s_type == "mult";

  if (b_num)
    return "number";

  b_bool = s_type == "and";
  b_bool = b_bool || s_type == "or";
  b_bool = b_bool || s_type == "eq";
  b_bool = b_bool || s_type == "gt";
  b_bool = b_bool || s_type == "lt";

  if (b_bool)
    return "bool";

  return "";
}

string
SyLength::get_type(SymbolTable* table)
{
  return "number";
}

string
SyArrayPull::get_type(SymbolTable* table)
{
  return "int_arr";
}

string
SyParenthesis::get_type(SymbolTable* table)
{
  return (*this)[0]->get_type(table);
}

string
SyNumber::get_type(SymbolTable* table)
{
  return "int";
}

string
SyBoolean::get_type(SymbolTable* table)
{
  return "bool";
}

string
SyIdentifier::get_type(SymbolTable* table)
{
  string s_id = (*this)[0]->value;
  Symbol* s = table->m_intrest->find(s_id, Record::VARIABLE);

  if (s)
    return s->m_type;

  return "";
}

string
SyThis::get_type(SymbolTable* table)
{
  return table->m_scope->m_id;
}

string
SyArrayInit::get_type(SymbolTable* table)
{
  return "int_arr";
}

string
SyObjectInit::get_type(SymbolTable* table)
{
  return (*this)[0]->value;
}

string
SyNot::get_type(SymbolTable* table)
{
  return "bool";
}

std::string 
SyExpressionList::get_type(SymbolTable* table) 
{
  return "";
}
