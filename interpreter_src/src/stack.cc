#include "../inc/stack.h"

Stack& Stack::operator=(const Stack& other)
{
  if (this == &other) return *this;

  this->m_data = other.m_data;
  return *this;
}

void Stack::push(int value) { m_data.push(value); }

int Stack::pop()
{
  int temp = m_data.top();
  m_data.pop();
  return temp;
}

int Stack::top()
{
  if (m_data.size() == 0) return 0;
  return m_data.top();
}
