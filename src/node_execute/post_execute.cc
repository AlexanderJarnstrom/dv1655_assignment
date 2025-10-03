#include "../../inc/node_execute.h"

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

void
SyOperator::post_execute(SymbolTable* table)
{
  string l_type, r_type, o_type;
  bool b_bool, b_num;
  Scope* t;

  t = table->m_intrest;
  table->m_intrest = table->m_scope;

  l_type = (*this)[0]->get_type(table);
  r_type = (*this)[1]->get_type(table);

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
