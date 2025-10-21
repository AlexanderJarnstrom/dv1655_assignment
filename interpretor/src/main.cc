#include <iostream>
#include <string>
#include <vector>

#include "../inc/byte_code.h"
#include "../inc/file_parser.h"

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cerr << argv[0] << " [file path]\n";
    return 1;
  }

  std::vector<ByteCode*> code;
  FileParser::read_file(argv[1], code);

  Stack stack;
  Heap heap;

  for (ByteCode* b : code)
  {
    b->execute(stack, heap);
  }

  ByteCodeUtil::delete_byte_code(code);
  return 0;
}
