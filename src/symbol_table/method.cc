#include "../../inc/symbol_table/method.h"
#include <iostream>

using namespace SymbolTable;
using namespace std;

Method::Method(Node* n, Record *p) 
  : Record(p, RecordType::METHOD), Children()
{
  Node *head = (*n)[0];
  string id = (*head)[1]->value;
  set_id(id);

  string type_s = (*head)[0]->value;

  if (type_s == "id")
    type_s = (*(*head)[0])[0]->value;


  m_value_type = type_s;
}

Method::Method(Record *p) 
  : Record(p, RecordType::METHOD), Children()
{}

Method::~Method()
{}

void
Method::print(const int l)
{
  for (int i = 0; i < l; i++) 
    cout << "  ";

  cout << "- \e[0;36m" << get_id() << "\e[0m: Method [rt: " 
    << get_record_type() << " vt: " 
    << m_value_type << "]" << endl;

  for (Record* child : get_children())
    child->print(l + 1);
}

std::string
Method::get_value_type()
{
  return m_value_type;
}

void
Method::set_value_type(std::string vt)  
{
  m_value_type = vt;
}

