#ifndef SYMBOL_DEBUG
#define SYMBOL_DEBUG

namespace SymbolTable {
  class Debug {
    public:
      virtual void print(const int) = 0;
  };
}

#endif // !SYMBOL_DEBUG
