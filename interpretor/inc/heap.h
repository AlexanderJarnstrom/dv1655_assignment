#ifndef HEAP_H
#define HEAP_H

#include <map>
#include <string>

class Heap
{
  std::map<std::string, int> m_data;

 public:
  Heap() {}
  Heap(const Heap& other) {}
  ~Heap() {}

  Heap& operator=(const Heap& other);

  int load(std::string& name);
  void store(std::string& name, int value);

  void print();
};

#endif  // !HEAP_H
