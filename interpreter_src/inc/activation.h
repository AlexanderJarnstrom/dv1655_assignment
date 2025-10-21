#ifndef ACTIVATION_H
#define ACTIVATION_H

#include "heap.h"
class Activation
{
  unsigned m_program_counter;
  Heap* m_local_heap;

 public:
  Activation(unsigned program_counter, Heap* local_heap)
      : m_program_counter(program_counter), m_local_heap(local_heap)
  {
  }

  Activation(const Activation& other)
      : m_program_counter(other.m_program_counter),
        m_local_heap(other.m_local_heap)
  {
  }

  ~Activation() {}

  Activation& operator=(const Activation& other);

  unsigned get_program_counter() { return m_program_counter; }
  Heap* get_local_heap() { return m_local_heap; }
};

#endif  // !ACTIVATION_H
