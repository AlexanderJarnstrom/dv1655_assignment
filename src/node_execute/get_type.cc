#include "../../inc/node_execute.h"

using namespace std;

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
  return "boolean";
}

std::string 
SyExpressionList::get_type(SymbolTable* table) 
{
  return (*this)[0]->get_type(table);
}


