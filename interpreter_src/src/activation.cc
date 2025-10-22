#include "../inc/activation.h"

Activation& Activation::operator=(const Activation& other)
{
  if (this == &other) return *this;

  this->m_program_counter = other.m_program_counter;
  this->m_local_heap = other.m_local_heap;

  return *this;
}
