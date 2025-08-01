#ifndef SYMBOL_VARIABLE
#define SYMBOL_VARIABLE

#include "record.h"
#include "../node.h"
#include <string>

namespace SymbolTable
{
  class Variable : public Record
  {
    std::string m_value_type;
    
    public:
    Variable(Record*);
    Variable(Node*, Record*);
    ~Variable();

    void print(const int);

    void set_value_type(std::string);
    std::string get_value_type();
  };
}

#endif // !SYMBOL_VARIABLE

