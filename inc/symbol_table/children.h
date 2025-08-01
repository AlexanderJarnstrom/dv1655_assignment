#ifndef SYMBOL_CHILDREN
#define SYMBOL_CHILDREN

#include "record.h"
#include <vector>
#include <string>

namespace SymbolTable {
  class Children {
    std::vector<Record*> m_children;

    public:
    Children();
    ~Children();

    std::vector<Record*> get_children();
    void clear();
    Record* get(std::string);
    void insert(Record*);
    void drop(Record*);
    Record* pop();
  };
}

#endif // !SYMBOL_CHILDREN
