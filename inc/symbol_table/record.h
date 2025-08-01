#ifndef SYMBOL_RECORD
#define SYMBOL_RECORD

#include "debug.h"
#include <string>

namespace SymbolTable
{
  enum RecordType
  {
    TABLE,
    CLASS,
    METHOD,
    VARIABLE,
    NONE
  };

  class Record : public Debug
  {
    RecordType m_record_type;
    std::string m_id;
    Record* m_parent;

    public: 
    Record(Record*, RecordType);
    virtual ~Record();

    void set_id(std::string id);
    std::string get_id();

    void set_record_type(RecordType);
    RecordType get_record_type();

    void set_parent(Record*);
    Record* get_parent();
  };
}

#endif // !SYMBOL_RECORD
