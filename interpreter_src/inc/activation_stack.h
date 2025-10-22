#ifndef ACTIVATION_STACK_H
#define ACTIVATION_STACK_H

#include <stack>

#include "activation.h"

class ActivationStack
{
  std::stack<Activation*> m_activations;

 public:
  ActivationStack() {}
  ActivationStack(const ActivationStack& other)
      : m_activations(other.m_activations)
  {
  }
  ~ActivationStack() {}

  ActivationStack& operator=(const ActivationStack& other);

  void push(Activation* stack);
  Activation* pop();
};

#endif  // !ACTIVATION_STACK_H
