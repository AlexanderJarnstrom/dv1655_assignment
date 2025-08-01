#ifndef SYMBOL_TABLE
#define SYMBOL_TABLE

#include <vector>
#include <string>
#include "children.h"
#include "record.h"
#include "../node.h"

namespace SymbolTable
{
  class Table : public Record, public Children {
  private:
    Record* m_scope;
    std::vector<std::string> m_errors;

    void add_error(int, std::string);

    Children* children_cast(Record*);
    Record* search(Record*, string, RecordType rt = RecordType::NONE);

    void build_global_table(Node*);
    void check_global_declerations(Node*);
    void check_local_declerations(Node*);

  public:
    Table();
    ~Table();

    void enter_scope(Record*);
    void exit_scope();

    void build_table(Node*);
    void check_identifiers(Node*);
    void check_types(Node*);
    void check_declerations(Node*);

    Record* find(std::string);
    void print(const int l = 0);
    void print_errors();
    void reset();

    Record* get_scope();
  };
}

#endif // !SYMBOL_TABLE
