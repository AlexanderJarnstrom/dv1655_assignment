#include "../../inc/symbol_table/class.h"
#include "../../inc/symbol_table/method.h"
#include "../../inc/symbol_table/variable.h"
#include <iostream>

using namespace SymbolTable;
using namespace std;

Class::Class(Node* n, Record* p) 
  : Record(p, RecordType::CLASS), Children()
{
  string id = (*n)[0]->value;
  set_id(id);

  if (n->type != "main_class")
    return;

  Method* main = new Method(this);
  main->set_id("main");
  main->set_value_type("void");

  Variable* args = new Variable(this);

  id = (*n)[1]->value;
  args->set_id(id);
  args->set_value_type("arg_arr");

  main->insert(args);
  insert(main);
}

Class::~Class()
{}

void
Class::print(const int l)
{
  for (int i = 0; i < l; i++) 
    cout << "  ";

  cout << "- \e[0;36m" << get_id() << "\e[0m: Class [rt: " 
    << get_record_type() << "]" << endl;

  for (Record* child : get_children())
    child->print(l + 1);
}


