#include "../../inc/symbol_table/variable.h"
#include <iostream>

using namespace SymbolTable;
using namespace std;

Variable::Variable(Node* n, Record* p) 
  : Record(p, RecordType::VARIABLE)
{
  string id = (*n)[1]->value;
  set_id(id);

  string type_s = (*n)[0]->value;

  if (type_s == "id")
    type_s = (*(*n)[0])[0]->value;


  m_value_type = type_s;
}

Variable::Variable(Record* p) 
  : Record(p, RecordType::VARIABLE)
{}

Variable::~Variable() 
{}

void
Variable::print(const int l)  
{
  for (int i = 0; i  < l; i++) 
    cout << "  ";

  cout << "- \e[0;36m" << get_id() << "\e[0m: Variable [rt: " 
    << get_record_type() << " vt: "
    << get_value_type() << "]" << endl;
}

void
Variable::set_value_type(string vt)
{
  m_value_type = vt;
}

std::string
Variable::get_value_type() 
{
  return m_value_type;
}
