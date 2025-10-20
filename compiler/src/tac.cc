#include "../inc/tac.h"
#include "../inc/byte_code.h"
#include <fstream>

using namespace std;

ExpressionTAC::ExpressionTAC (string t, string l, string r, string o)
    : m_target (t), m_left (l), m_right (r), m_operator (o), TAC ()
{
}

void
ExpressionTAC::generate_tree_content (ofstream *s)
{
  *s << m_target << " := " << m_left << " " << m_operator << " " << m_right
     << endl;
}

void
ExpressionTAC::generate_code (ofstream *out)
{
  ByteCode::iload (m_left, out);
  ByteCode::iload (m_right, out);
  ByteCode::iop (m_operator, out);
  ByteCode::istore (m_target, out);
}

UnaryExpressionTAC::UnaryExpressionTAC (string t, string r, string o)
    : m_target (t), m_right (r), m_operator (o), TAC ()
{
}

void
UnaryExpressionTAC::generate_tree_content (ofstream *s)
{
  *s << m_target << " := " << m_operator << " " << m_right << endl;
}

void
UnaryExpressionTAC::generate_code (ofstream *out)
{
  ByteCode::iload (m_right, out);
  ByteCode::iop (m_operator, out);
  ByteCode::istore (m_target, out);
}

CopyTAC::CopyTAC (string t, string r) : m_target (t), m_right (r), TAC () {}

void
CopyTAC::generate_tree_content (ofstream *s)
{
  *s << m_target << " := " << m_right << endl;
}

void
CopyTAC::generate_code (ofstream *out)
{
  ByteCode::iload (m_right, out);
  ByteCode::istore (m_target, out);
}

ArrayAccessTAC::ArrayAccessTAC (string t, string r, string i, bool p)
    : m_target (t), m_right (r), m_index (i), m_pull (p), TAC ()
{
}

void
ArrayAccessTAC::generate_tree_content (ofstream *s)
{
  if (m_pull)
    {
      *s << m_target << " := " << m_right << "[" << m_index << "]" << endl;
    }
  else
    {
      *s << m_target << "[" << m_index << "]" << " := " << m_right << endl;
    }
}

void
ArrayAccessTAC::generate_code (ofstream *out)
{
}

NewObjectTAC::NewObjectTAC (string t, string r)
    : m_target (t), m_right (r), TAC ()
{
}

void
NewObjectTAC::generate_tree_content (ofstream *s)
{
  *s << m_target << " := new " << m_right << endl;
}

void
NewObjectTAC::generate_code (ofstream *out)
{
}

ArrayNewTAC::ArrayNewTAC (string t, string r, string s)
    : m_target (t), m_right (r), m_size (s), TAC ()
{
}

void
ArrayNewTAC::generate_tree_content (ofstream *s)
{
  *s << m_target << " := new " << m_right << ", " << m_size << endl;
}

void
ArrayNewTAC::generate_code (ofstream *out)
{
}

LengthTAC::LengthTAC (string t, string r) : m_target (t), m_right (r), TAC ()
{
}

void
LengthTAC::generate_tree_content (ofstream *s)
{
  *s << m_target << " := " << m_right << ".length" << endl;
}

void
LengthTAC::generate_code (ofstream *out)
{
}

ParameterTAC::ParameterTAC (string t) : m_target (t), TAC () {}

void
ParameterTAC::generate_tree_content (ofstream *s)
{
  *s << "param " << m_target << endl;
}

void
ParameterTAC::generate_code (ofstream *out)
{
  ByteCode::iload (m_target, out);
}

MethodTAC::MethodTAC (string t, string r, unsigned int p)
    : m_target (t), m_right (r), m_parameters (p), TAC ()
{
}

void
MethodTAC::generate_tree_content (ofstream *s)
{
  *s << m_target << " := call " << m_right << ", " << m_parameters << endl;
}

void
MethodTAC::generate_code (ofstream *out)
{
  ByteCode::invokevirtual (m_right, out);
  ByteCode::istore (m_target, out);
}

ReturnTAC::ReturnTAC (string t) : m_target (t), TAC () {}

void
ReturnTAC::generate_tree_content (ofstream *s)
{
  *s << "return " << m_target << endl;
}

void
ReturnTAC::generate_code (ofstream *out)
{
  ByteCode::iload (m_target, out);
  ByteCode::ireturn (out);
}

UnconditionalTAC::UnconditionalTAC (string t) : m_target (t), TAC () {}

void
UnconditionalTAC::generate_tree_content (ofstream *s)
{
  *s << "goto: " << m_target << endl;
}

void
UnconditionalTAC::generate_code (ofstream *out)
{
  ByteCode::igoto (m_target, out);
}

ConditionalTAC::ConditionalTAC (string t, string r)
    : m_target (t), m_right (r), TAC ()
{
}

void
ConditionalTAC::generate_tree_content (ofstream *s)
{
  *s << "if-false: " << m_right << " goto " << m_target << endl;
}

void
ConditionalTAC::generate_code (ofstream *out)
{
  ByteCode::iload (m_right, out);
  ByteCode::iffalse (m_target, out);
}

PrintTAC::PrintTAC () {}

void
PrintTAC::generate_tree_content (std::ofstream *s)
{
  *s << "call print, 1" << endl;
}

void
PrintTAC::generate_code (std::ofstream *out)
{
  ByteCode::iprint (out);
}
