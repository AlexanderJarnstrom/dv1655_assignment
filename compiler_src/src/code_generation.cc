#include "../inc/code_generation.h"

#include <fstream>
#include <iostream>

#include "../inc/config.h"

using namespace std;

void CodeGeneration::generate_code(BlockHandler* bh)
{
  std::string file_name;
  if (Config::flags & Config::Flags::OUTPUT)
    file_name = Config::output_name;
  else
  {
    file_name = Config::input_name;
    format_filename(file_name);
  }

  ofstream file(file_name);

  if (!file.is_open())
  {
    cerr << "Could not open file: " << file_name << endl;
    return;
  }

  bh->generate_code(&file);

  file.close();
}

void CodeGeneration::format_filename(string& name)
{
  name = name.substr(0, name.size() - 5);
  name = name.append(".jar");
}
