#include "../../inc/node_execute.h"
#include <vector>

using namespace std;

void
SyOperator::generate_tacs (vector<TAC *> &tacs, string &target)
{
  Node *left, *right;
  string l_s, r_s, op;
  TAC *tac;

  left = (*this)[0];
  right = (*this)[1];

  op = this->value;

  left->generate_tacs (tacs, l_s);
  right->generate_tacs (tacs, r_s);

  tac = new TAC (tacs.size (), l_s, r_s, op);
  tacs.push_back (tac);

  if (target.empty ())
    target = tac->m_target;
  else
    tac->m_target = target;
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
