#ifndef HEAP_H
#define HEAP_H

#include <map>
#include <string>

/**
 * @class Heap
 * @brief Heap class
 *
 */
class Heap
{
  std::map<std::string, int> m_data;

 public:
  Heap() {}
  Heap(const Heap& other) {}
  ~Heap() {}

  Heap& operator=(const Heap& other);

  /**
   * @brief Load value from heap.
   *
   * @param name name of variable.
   * @return value.
   */
  int load(std::string& name);
  /**
   * @brief Store value to heap.
   *
   * @param name name of variable.
   * @param value int.
   */
  void store(std::string& name, int value);

  /**
   * @brief Print current content to stdout.
   */
  void print();
};

#endif  // !HEAP_H
