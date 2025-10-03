#include "../inc/tac.h"

using namespace std;

ExpressionTAC::ExpressionTAC (string t, string l, string r, string o)
    : m_target (t), m_left (l), m_right (r), m_operator (o), TAC ()
{
}

void
ExpressionTAC::generate_tree_content (ofstream *s)
{
  *s << m_target << " := " << m_left << " " << m_operator << " " << m_right << endl;
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

CopyTAC::CopyTAC (string t, string r) : m_target (t), m_right (r), TAC () {}

void
CopyTAC::generate_tree_content (ofstream *s)
{
  *s << m_target << " := " << m_right << endl;
}

ArrayAccessTAC::ArrayAccessTAC (string t, string r, unsigned int s, bool p)
    : m_target (t), m_right (r), m_size (s), m_pull (p), TAC ()
{
}

void
ArrayAccessTAC::generate_tree_content (ofstream *s)
{
  if (m_pull)
    {
      *s << m_target << " := " << m_right << "[" << m_size << "]";
    }
  else
    {
      *s << m_right << "[" << m_size << "]" << " := " << m_target;
    }
}

NewObjectTAC::NewObjectTAC (string t, string r) : m_target (t), m_right (r), TAC () {}

void
NewObjectTAC::generate_tree_content (ofstream *s)
{
  *s << m_target << " := new " << m_right << endl;
}

ArrayNewTAC::ArrayNewTAC (string t, string r, unsigned int s)
    : m_target (t), m_right (r), m_size (s), TAC ()
{
}

void
ArrayNewTAC::generate_tree_content (ofstream *s)
{
  *s << m_target << " := new " << m_right << ", " << m_size << endl;
}

LengthTAC::LengthTAC (string t, string r) : m_target (t), m_right (r), TAC () {}

void
LengthTAC::generate_tree_content (ofstream *s)
{
  *s << m_target << " := new " << m_right << " length" << endl;
}

ParameterTAC::ParameterTAC (string t) : m_target (t), TAC () {}

void
ParameterTAC::generate_tree_content (ofstream *s)
{
  *s << "param " << m_target << endl;
}

MethodTAC::MethodTAC (string t, string r, unsigned int p)
    : m_target (t), m_right (r), m_parameters (p), TAC ()
{
}

void
MethodTAC::generate_tree_content (ofstream *s)
{
  *s << m_target << " := " << m_right << ", " << m_parameters << endl;
}

ReturnTAC::ReturnTAC (string t) : m_target (t), TAC () {}

void
ReturnTAC::generate_tree_content (ofstream *s)
{
  *s << "return " << m_target << endl;
}

UnconditionalTAC::UnconditionalTAC (string t) : m_target (t), TAC () {}

void
UnconditionalTAC::generate_tree_content (ofstream *s)
{
  *s << "goto " << m_target << endl;
}

ConditionalTAC::ConditionalTAC (string t, string r) : m_target (t), m_right (r), TAC () {}

void
ConditionalTAC::generate_tree_content (ofstream *s)
{
  *s << "if-false" << m_right << " goto " << m_target << endl;
}
