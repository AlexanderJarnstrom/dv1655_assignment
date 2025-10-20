#include "../inc/code_generation.h"
#include <fstream>
#include <iostream>

using namespace std;

void
format_filename (string &name)
{
  name = name.substr (0, name.size () - 5);
  name = name.append (".jar");
}

void
generate_code (BlockHandler *bh, string name)
{
  format_filename (name);

  ofstream file (name);

  if (!file.is_open ())
    {
      cerr << "Could not open file: " << name << endl;
      return;
    }

  bh->generate_code (&file);

  file.close ();
}
