#include "../inc/config.h"

#include <cstring>
#include <fstream>
#include <iostream>

namespace Config
{
int flags = 0;
std::string output_name = "";
std::string input_name = "";
}  // namespace Config

void Config::extract_arguments(int argc, char** argv)
{
  int i;
  for (i = 0; i < argc; i++)  // Loop through arguments
  {
    if (argv[i][0] == '-' && argv[i][1] == 'd')  // Debug flags
    {
      flags = flags | Flags::DEBUG;
      int len = std::strlen(argv[i]);
      for (int j = 2; j < len; j++)  // Loop through all sub flags
      {
        if (argv[i][j] == 't')  // generate tree.dot
          flags = flags | Flags::TREE;
        else if (argv[i][j] == 'b')  // generate blocks.dot
          flags = flags | Flags::BLOCKS;
        else if (argv[i][j] == 'a')  // generate both
          flags = flags | Flags::BLOCKS | Flags::TREE;
      }
    }
    else if (argv[i][0] == '-' &&
             argv[i][1] == 'o')  // potential output file name
    {
      i++;
      if (i >= argc)
      {
        std::cerr << "expected file name.\n";
        continue;
      }
      flags = flags | Flags::OUTPUT;
      output_name = argv[i];
    }
    else if (i != 0)  // Potential input file
    {
      std::ifstream file(argv[i]);
      if (file.is_open())
      {
        flags = flags | Flags::INPUT_File;
        input_name = argv[i];
      }
      file.close();
    }
  }
}
