#ifndef SYMBOL_CLASS
#define SYMBOL_CLASS

#include "children.h"
#include "record.h"
#include "../node.h"
#include <string>
#include <vector>

namespace SymbolTable {
  class Class : public Record, public Children {
  public:
    Class(Node*, Record*);
    ~Class();

    void print(const int);
  };
}

#endif // !SYMBOL_CLASS
