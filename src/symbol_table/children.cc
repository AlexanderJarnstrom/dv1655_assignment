#include "../../inc/symbol_table/children.h"

using namespace SymbolTable;
using namespace std;

Children::Children()
{}

Children::~Children()
{
  for (Record* c : m_children)  
    delete c;
}

vector<Record*>
Children::get_children()
{
  return m_children;
}

void
Children::clear()
{
  for (Record* c : m_children)
    delete c;

  m_children.clear();
}

Record*
Children::get(std::string id) 
{
  Record* n = nullptr;
  for (Record* child : m_children)
  {
    if (child->get_id() == id)
    {
      n = child;
      break;
    }
  }

  return n;
}

void
Children::insert(Record* n)
{
  m_children.push_back(n);
}

void
Children::drop(Record* n)
{
  for (auto it = m_children.begin(); it < m_children.end(); it++)
    if (n == *it.base())
    {
      m_children.erase(it);
      it = m_children.end();
    }
}

Record*
Children::pop()
{
  Record* n = m_children[m_children.size() - 1];
  m_children.erase(m_children.end());

  return n;
}


