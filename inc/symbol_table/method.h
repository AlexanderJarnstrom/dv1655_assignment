#ifndef SYMBOL_METHOD
#define SYMBOL_METHOD

#include "children.h"
#include "record.h"
#include "../node.h"
#include <string>
#include <vector>

namespace SymbolTable
{
  class Method : public Record, public Children
  {
    std::string m_value_type;

    public:
    Method(Node*, Record*);
    Method(Record*);
    ~Method();

    void print(const int);

    std::string get_value_type();
    void set_value_type(std::string);
  };
}

#endif // !SYMBOL_METHOD
