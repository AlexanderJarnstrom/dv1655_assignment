#ifndef ACTIVATION_STACK_H
#define ACTIVATION_STACK_H

#include <stack>

#include "activation.h"

/**
 * @class ActivationStack
 * @brief Stack for activations.
 * @see Activation
 */
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

  /**
   * @brief Push new activation to stack.
   *
   * @param stack Activation* to push.
   */
  void push(Activation* stack);
  /**
   * @brief Pop the last activation pushed.
   *
   * @return poped Activation pointer.
   */
  Activation* pop();
};

#endif  // !ACTIVATION_STACK_H
