#include "../inc/byte_code.h"

using namespace std;

void
ByteCode::iload (std::string target, std::ofstream *out)
{
  if (target.c_str ()[0] == '#')
    *out << "iconst " << target.substr (1, target.size ()) << endl;
  else
    *out << "iload " << target << endl;
}

void
ByteCode::istore (std::string target, std::ofstream *out)
{
  *out << "istore " << target << endl;
}

void
ByteCode::iop (std::string op, std::ofstream *out)
{
  if (op == "add")
    {
      *out << "iadd" << endl;
    }
  else if (op == "sub")
    {
      *out << "isub" << endl;
    }
  else if (op == "mult")
    {
      *out << "imul" << endl;
    }
  else if (op == "lt")
    {
      *out << "ilt" << endl;
    }
  else if (op == "gt")
    {
      *out << "igt" << endl;
    }
  else if (op == "eq")
    {
      *out << "ieq" << endl;
    }
  else if (op == "and")
    {
      *out << "iand" << endl;
    }
  else if (op == "or")
    {
      *out << "ior" << endl;
    }
  else if (op == "not")
    {
      *out << "inot" << endl;
    }
}

void
ByteCode::invokevirtual (std::string target, std::ofstream *out)
{
  *out << "invokevirtual " << target << endl;
}

void
ByteCode::ireturn (std::ofstream *out)
{
  *out << "ireturn " << endl;
}

void
ByteCode::igoto (std::string target, std::ofstream *out)
{
  *out << "goto " << target << endl;
}

void
ByteCode::iffalse (std::string target, std::ofstream *out)
{
  *out << "iffalse " << target << endl;
}

void
ByteCode::iprint (std::ofstream *out)
{
  *out << "print\n";
}
