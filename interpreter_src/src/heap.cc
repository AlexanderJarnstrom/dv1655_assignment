#include "../inc/heap.h"

#include <iostream>

Heap& Heap::operator=(const Heap& other)
{
  if (this == &other) return *this;

  this->m_data = other.m_data;

  return *this;
}

int Heap::load(std::string& name) { return m_data.at(name); }

void Heap::store(std::string& name, int value)
{
  auto it = m_data.find(name);
  if (it == m_data.end())
    m_data.insert({name, value});
  else
    it->second = value;
}

void Heap::print()
{
  for (auto d : m_data)
  {
    std::cout << d.first << ": " << d.second << std::endl;
  }
}
