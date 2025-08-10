#include "../inc/node_execute.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string>
get_arguments(Node* n, SymbolTable* table)
{
  vector<string> args;

  if (n->type == "expression_lst" && n->value == "sep")
  {
    args.push_back(n->get_type(table));

    if ((*n)[1]->type != "expression_lst")
      args.push_back((*n)[1]->get_type(table));
  }

  for (Node* c : n->children)
    for (string s : get_arguments(c, table))
      args.push_back(s);

  return args;
}

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
SyMethod::post_execute(SymbolTable* table)
{
  string s_type, s_id, s_return;
  Node *head, *body, *ret;
  Symbol *t;

  head = (*this)[0];

  table->m_intrest = table->m_scope;

  if (this->children.size() == 3)
    body = (*this)[2];
  else
    body = (*this)[1];

  s_type = (*head)[0]->value;

  if (s_type == "id")
  {
    s_type = (*(*head)[0])[0]->value;

    if (!table->m_root->find(s_type, Record::CLASS))
      table->add_error(lineno, "'" + s_type + "' is undefined");
  }

  s_id = (*head)[1]->value;

  if (body->children.size() == 1) 
    ret = (*body)[0];
  else
    ret = (*body)[1];

  s_return = ret->get_type(table);
  t = table->m_scope->find(s_id, Record::METHOD);

  if (t && t->m_type != s_return)
      table->add_error(head->lineno, "'" + s_id + "' has wrong return type ('" + t->m_type + "' and '" + s_return + "')");
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
SyAssignArr::post_execute(SymbolTable* table)
{
  string s_type, s_id;
  Scope* t;
  Symbol* n;

  t = table->m_intrest;
  table->m_intrest = table->m_scope;

  s_id = (*this)[0]->value;
  n = table->m_scope->find(s_id);
  
  if (!n)
    table->add_error((*this)[0]->lineno, "'" + s_id + "' is not decleared");

  s_type = n->m_type;

  if (s_type != "int_arr")
    table->add_error((*this)[0]->lineno, "expected an integer array found '" + s_type + "'");

  s_type = (*this)[1]->get_type(table);
  if (s_type != "int")
    table->add_error((*this)[0]->lineno, "wrong type in int array operation [], expected 'int' got '" + s_type + "'");

  s_type = (*this)[2]->get_type(table);
  if (s_type != "int")
    table->add_error((*this)[2]->lineno, "can not assign value of type '" + s_type + "' to an integer array");


  table->m_intrest = t;
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
      return;

    table->m_intrest = s;
  }
  else if ((*this)[0]->value == "init")
  {
    s_id = (*(*this)[0])[0]->value;
    s = table->m_root->get_scope(s_id);
    if (!s)
      return;

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
  {
    table->add_error(lineno, "'" + s_id + "' does not have attribute: '" + s_attribute + "'");
    return;
  }

  Scope* m = s->get_scope(s_attribute);
  vector<Symbol*> m_param = m->find_all(Record::ARGUMENT);

  if (!m_param.empty() && this->value == "attr")
    table->add_error(this->lineno, "'" + s_attribute + "' requiers " + to_string(m_param.size()) + " arguments but non where given");
  else if (this->value == "attr_exp")
  {
    Scope* t = table->m_intrest;
    table->m_intrest = table->m_scope;

    vector<string> args = get_arguments(this, table);

    if (args.empty())
    {
      string arg = (*this)[2]->get_type(table);
      if (arg != "")
        args.push_back(arg);
    }

    for (int i = 0; i < m_param.size(); i++)
    {
      if (i >= args.size())
      {
        table->add_error((this->lineno), "missing " + to_string(m_param.size() - i) + " argument(s) for '" + s_attribute + "'.");
        break;
      }

      if (args[i] != m_param[i]->m_type)
        table->add_error((this->lineno), "invalid argument for '" + s_attribute + "' at position: " + to_string(i) + " expected '" + m_param[i]->m_type + "' but got '" + args[i] + "'");
    }

    table->m_intrest = t;
  }
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

void
SyOperator::post_execute(SymbolTable* table)
{
  string l_type, r_type, o_type;
  bool b_bool, b_num;
  Scope* t;

  t = table->m_intrest;
  table->m_intrest = table->m_scope;

  l_type = (*this)[0]->get_type(table);
  r_type = (*this)[2]->get_type(table);

  if (l_type != r_type)
  {
    table->add_error(this->lineno, "invalid operation ('" + l_type + "' and '" + r_type + "')");
    return;
  }

  o_type = (*this)[1]->value;

  b_bool = o_type == "and";
  b_bool = b_bool || o_type == "or";
  b_bool = b_bool || o_type == "eq";

  if (b_bool && l_type != "boolean")
    table->add_error(this->lineno, "invalid operation, left should be a boolean");

  if (b_bool && r_type != "boolean")
    table->add_error(this->lineno, "invalid operation, right should be a boolean");

  b_num = o_type == "add";
  b_num = b_num || o_type == "sub";
  b_num = b_num || o_type == "mult";
  b_num = b_num || o_type == "gt";
  b_num = b_num || o_type == "lt";

  if (b_num && l_type != "int")
    table->add_error(this->lineno, "invalid operation, left should be an integer");

  if (b_num && r_type != "int")
    table->add_error(this->lineno, "invalid operation, right should be an integer");

  table->m_intrest = t;
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
    return "int";

  b_bool = s_type == "and";
  b_bool = b_bool || s_type == "or";
  b_bool = b_bool || s_type == "eq";
  b_bool = b_bool || s_type == "gt";
  b_bool = b_bool || s_type == "lt";

  if (b_bool)
    return "boolean";

  return "";
}

void
SyLength::post_execute(SymbolTable *table)
{
  Scope* t;
  string s_type;

  t = table->m_intrest;
  table->m_intrest = table->m_scope;

  s_type = (*this)[0]->get_type(table);
  if (s_type != "int_arr")
    table->add_error((*this)[0]->lineno, "'" + s_type + "' does not have member 'length'");

  table->m_intrest = t;
}

string
SyLength::get_type(SymbolTable* table)
{
  return "int";
}

void
SyArrayPull::post_execute(SymbolTable* table)
{
  Scope* t;
  string s_type;
  
  t = table->m_intrest;
  table->m_intrest = table->m_scope;
  s_type =(*this)[1]->get_type(table);

  if (s_type != "int")
    table->add_error((*this)[1]->lineno, "wrong type in int array expression [], expected 'int' got '" + s_type + "'");

  table->m_intrest = t;
}

string
SyArrayPull::get_type(SymbolTable* table)
{
  return "int";
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
  return "boolean";
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

void
SyArrayInit::post_execute(SymbolTable* table)
{
  string s_type;
  Scope* t;

  t = table->m_intrest;
  table->m_intrest = table->m_scope;

  s_type = (*this)[0]->get_type(table);

  if (s_type != "int")
    table->add_error((*this)[0]->lineno, "expected 'int' but go '" + s_type + "'");

  table->m_intrest = t;
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

void
SyNot::post_execute(SymbolTable* table) 
{
  Scope *t;
  string s_type;

  t = table->m_intrest;
  table->m_intrest = table->m_scope;
  s_type = (*this)[0]->get_type(table);

  if (s_type != "boolean")
    table->add_error((*this)[0]->lineno, "Expression inside 'not' operation is not of type 'boolean'");

  table->m_intrest = t;
}

string
SyNot::get_type(SymbolTable* table)
{
  return "boolean";
}

std::string 
SyExpressionList::get_type(SymbolTable* table) 
{
  return (*this)[0]->get_type(table);
}
