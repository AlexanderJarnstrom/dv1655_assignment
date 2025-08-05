#include "../inc/symbol.h"

Symbol::Symbol(std::string id, std::string t, Record r)
  : m_id(id), m_type(t), m_record(r)
{}

Symbol::~Symbol()
{}
