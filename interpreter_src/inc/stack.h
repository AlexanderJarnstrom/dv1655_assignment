#ifndef STACK_H
#define STACK_H

#include <stack>
/**
 * @class Stack
 * @brief Value stack
 *
 */
class Stack
{
  std::stack<int> m_data;

 public:
  Stack() {}
  Stack(const Stack& other) : m_data(other.m_data) {}
  ~Stack() {}

  Stack& operator=(const Stack& other);

  /**
   * @brief Push value to stack.
   *
   * @param value int.
   */
  void push(int value);
  /**
   * @brief Pop last value.
   *
   * @return poped int.
   */
  int pop();
  /**
   * @brief Top value.
   *
   * @return top int.
   */
  int top();
};

#endif  // !STACK_H
