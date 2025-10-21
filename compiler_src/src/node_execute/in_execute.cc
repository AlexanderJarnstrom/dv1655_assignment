#include "../../inc/node_execute.h"

using namespace std;

void
SyAssign::in_execute(SymbolTable* table)
{
  string s_id = (*this)[0]->value;

  if (!table->check_scope(s_id, Record::VARIABLE))
    table->add_error(lineno, "definition without declareation: " + s_id);
}


