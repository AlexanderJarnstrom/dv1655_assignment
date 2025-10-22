#include "../inc/engine.h"

#include <iostream>

Engine& Engine::operator=(const Engine& other)
{
  if (this == &other) return *this;

  this->m_program_counter = other.m_program_counter;
  this->m_activation_stack = other.m_activation_stack;
  this->m_stack = other.m_stack;
  this->m_labels = other.m_labels;
  this->m_local_variables = other.m_local_variables;

  return *this;
}

void Engine::jump(const std::string& label)
{
  auto it = m_labels.find(label);

  if (it == m_labels.end())
  {
    std::cerr << "Label: " << label << " does not exist.\n";
    return;
  }

  m_program_counter = it->second;
}

void Engine::push_activation(const std::string& label)
{
  auto it = m_labels.find(label);

  if (it == m_labels.end())
  {
    std::cerr << "Label: " << label << " does not exist.\n";
    return;
  }

  Activation* activation = new Activation(m_program_counter, m_local_variables);
  m_activation_stack.push(activation);
  m_local_variables = new Heap;
  m_program_counter = it->second;
}

void Engine::pop_activation()
{
  Activation* activation = m_activation_stack.pop();
  delete m_local_variables;
  m_local_variables = activation->get_local_heap();
  m_program_counter = activation->get_program_counter() + 1;
  delete activation;
}
