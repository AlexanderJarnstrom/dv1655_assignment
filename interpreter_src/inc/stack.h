#ifndef STACK_H
#define STACK_H

#include <stack>
class Stack
{
  std::stack<int> m_data;

 public:
  Stack() {}
  Stack(const Stack& other) : m_data(other.m_data) {}
  ~Stack() {}

  Stack& operator=(const Stack& other);

  void push(int value);
  int pop();
  int top();
};

#endif  // !STACK_H
