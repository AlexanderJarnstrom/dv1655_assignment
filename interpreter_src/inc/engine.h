#ifndef ENGINE_H
#define ENGINE_H

#include <map>
#include <string>
#include <vector>

#include "activation_stack.h"
#include "heap.h"
#include "stack.h"

/**
 * @class Engine
 * @brief The engine.
 *
 * the class is responsible for handling stack, heap and activations.
 */
class Engine
{
  unsigned m_program_counter;
  std::map<std::string, unsigned> m_labels;
  Heap* m_local_variables;
  Stack m_stack;
  ActivationStack m_activation_stack;

 public:
  Engine()
      : m_program_counter(0),
        m_labels(),
        m_local_variables(new Heap()),
        m_stack(),
        m_activation_stack()
  {
  }

  Engine(const Engine& other)
      : m_program_counter(other.m_program_counter),
        m_labels(other.m_labels),
        m_local_variables(other.m_local_variables),
        m_stack(other.m_stack),
        m_activation_stack(other.m_activation_stack)
  {
  }

  ~Engine() { delete m_local_variables; }

  unsigned get_program_counter() const { return m_program_counter; }
  std::map<std::string, unsigned>& get_labels() { return m_labels; }
  Heap& get_local_variables() { return *m_local_variables; }
  Stack& get_stack() { return m_stack; }
  ActivationStack& get_activation_stack() { return m_activation_stack; }

  void increment_counter() { m_program_counter++; }

  /**
   * @brief Jump to the given label
   *
   * @param label Label of the jump location.
   */
  void jump(const std::string& label);
  /**
   * @brief Push current context to activation stack and create a new.
   *
   * Pushes the current context to the activation stack and jumps to the new
   * context with the given label.
   *
   * @param label of the jump placement.
   */
  void push_activation(const std::string& label);
  /**
   * @brief Exit current context and enther previous one.
   */
  void pop_activation();

  Engine& operator=(const Engine& other);
};

#endif  // !ENGINE_H
