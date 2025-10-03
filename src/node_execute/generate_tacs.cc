#include "../../inc/node_execute.h"
#include "../../inc/tac.h"
#include <string>
#include <vector>

using namespace std;

void
SyAttribute::generate_tacs (std::vector<TAC *> &tacs, std::string &target)
{
  vector<TAC *> arguments;
  MethodTAC *tac;
  Node *args;
  unsigned int count;
  string t_s, r_s;

  count = 0;

  if (this->children.size () > 2)
    {
      args = (*this)[2];

      args->generate_tacs (arguments, t_s);

      for (TAC *a : arguments)
        {
          tacs.push_back (a);
          if (dynamic_cast<ParameterTAC *> (a) != nullptr)
            count++;
        }
    }

  r_s = (*this)[1]->value;

  if (target.empty ())
    t_s = "_t" + to_string (tacs.size ());
  else
    t_s = target;

  tac = new MethodTAC (t_s, r_s, count);
  tacs.push_back (tac);
  target = t_s;
}

void
SyExpressionList::generate_tacs (std::vector<TAC *> &tacs, std::string &target)
{
  Node *left, *right;
  string t_s, l_s, r_s;
  ParameterTAC *tac;

  left = (*this)[0];
  right = (*this)[1];

  left->generate_tacs (tacs, l_s);
  right->generate_tacs (tacs, r_s);

  tac = new ParameterTAC (l_s);
  tacs.push_back (tac);
  tac = new ParameterTAC (r_s);
  tacs.push_back (tac);
}

void
SyOperator::generate_tacs (vector<TAC *> &tacs, string &target)
{
  Node *left, *right;
  string t_s, l_s, r_s, op;
  ExpressionTAC *tac;

  left = (*this)[0];
  right = (*this)[1];

  op = this->value;

  left->generate_tacs (tacs, l_s);
  right->generate_tacs (tacs, r_s);

  if (target.empty ())
    {
      t_s = "_t" + to_string (tacs.size ());
      tac = new ExpressionTAC (t_s, l_s, r_s, op);
      target = t_s;
    }
  else
    {
      tac = new ExpressionTAC (target, l_s, r_s, op);
    }

  tacs.push_back (tac);
}

void
SyArrayPull::generate_tacs (vector<TAC *> &tacs, string &target)
{
}

void
SyIdentifier::generate_tacs (std::vector<TAC *> &tacs, string &target)
{
  target = (*this)[0]->value;
}

void
SyNumber::generate_tacs (std::vector<TAC *> &tacs, std::string &target)
{
  target = this->value;
}
