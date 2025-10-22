#include "../inc/activation_stack.h"

ActivationStack& ActivationStack::operator=(const ActivationStack& other)
{
  if (this == &other) return *this;

  this->m_activations = other.m_activations;

  return *this;
}

void ActivationStack::push(Activation* stack) { m_activations.push(stack); }

Activation* ActivationStack::pop()
{
  Activation* temp = m_activations.top();
  m_activations.pop();
  return temp;
}
