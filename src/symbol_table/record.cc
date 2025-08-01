#include "../../inc/symbol_table/record.h"

using namespace SymbolTable;
using namespace std;

Record::Record(Record* p, RecordType rt) 
  : m_parent(p), m_record_type(rt)
{}

Record::~Record()
{
  m_parent = nullptr;
}

void
Record::set_id(std::string id) 
{
  m_id = id;
}

std::string
Record::get_id()
{
  return m_id;
}

void
Record::set_record_type(RecordType rt)
{
  m_record_type = rt;
}

RecordType
Record::get_record_type()
{
  return m_record_type;
}

void
Record::set_parent(Record* n) 
{
  m_parent = n;
}

Record*
Record::get_parent()
{
  return m_parent;
}
