#include "../inc/utils.h"
#include <string>

using namespace std;

void 
extract_class(Node* p_n, SymbolNode **pp_sn)
{
  Node n = *p_n;

  string name = n[0]->value;
  *pp_sn = new SymbolNode(name, CLASS, NONE, n.lineno);
}

void 
extract_main_class(Node* p_n, SymbolNode **pp_sn)
{
  Node n = *p_n;

  string name = n[0]->value;
  *pp_sn = new SymbolNode(name, MAIN_CLASS, NONE, n.lineno);
}

void
extract_main_class_args(Node* p_n, SymbolNode** pp_sn)
{
  Node n = *p_n;

  string name = n[1]->value;
  *pp_sn = new SymbolNode(name, VARIABLE, STRING_ARR, n.lineno);
}

void 
extract_statement(Node* p_n, SymbolNode **pp_sn, int counter)
{
  Node n = *p_n;

  string type = n.value;

  if (type != "block")
  {
    *pp_sn = nullptr;
    return;
  }

  string name = "block_" + to_string(counter);
  *pp_sn = new SymbolNode(name, STATEMENT, NONE, n.lineno);
}

void 
extract_expresion(Node* p_n, SymbolNode **pp_sn)
{
  Node n = *p_n;
  SymbolNode *p_sn = *pp_sn;
}

void 
extract_variable(Node* p_n, SymbolNode **pp_sn)
{
  Node n = *p_n;

  value_t value;
  string value_s = n[0]->value;
  string name = n[1]->value;

  if (value_s == "int_arr") value = INT_ARR;
  else if (value_s == "int") value = INT;
  else if (value_s == "string") value = STRING;
  else if (value_s == "bool") value = BOOL;
  else if (value_s == "id") value = USER_DEF;
  else value = NONE;

  *pp_sn = new SymbolNode(name, VARIABLE, value, n.lineno);
}

void 
extract_method(Node* p_n, SymbolNode **pp_sn)
{
  Node n = *p_n;
  SymbolNode *p_sn = *pp_sn;

  value_t value;
  string value_s = (*n[0])[0]->value;
  string name = (*n[0])[1]->value;

  if (value_s == "int_arr") value = INT_ARR;
  else if (value_s == "int") value = INT;
  else if (value_s == "string") value = STRING;
  else if (value_s == "bool") value = BOOL;
  else if (value_s == "id") value = USER_DEF;
  else value = NONE;

  *pp_sn = new SymbolNode(name, METHOD, value, n.lineno);
}


