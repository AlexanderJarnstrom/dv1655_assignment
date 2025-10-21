#include <iostream>
#include <string>
#include <vector>

#include "../inc/byte_code.h"
#include "../inc/file_parser.h"
#include "../inc/runtime.h"

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cerr << argv[0] << " [file path]\n";
    return 1;
  }

  std::vector<ByteCode*> code;
  Engine engine;

  FileParser::read_file(argv[1], code, engine);
  Runtime::run(code, engine);

  ByteCodeUtil::delete_byte_code(code);
  return 0;
}
