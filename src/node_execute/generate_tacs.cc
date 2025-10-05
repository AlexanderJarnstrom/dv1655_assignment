#include "../../inc/node_execute.h"
#include "../../inc/tac.h"
#include <string>
#include <vector>

using namespace std;

void
SyAttribute::generate_tacs (std::vector<TAC *> &tacs, std::string &target, BlockHandler *bh)
{
  vector<TAC *> arguments;
  MethodTAC *tac;
  Node *args;
  unsigned int count;
  string t_s, r_s, obj_type_s, method_s;
  Node *obj, *method, *arg;
  Scope *m_scope;
  Symbol *m_symbol;

  obj = (*this)[0];
  method = (*this)[1];

  bh->m_table->m_intrest = bh->m_table->m_scope;
  obj_type_s = obj->get_type (bh->m_table);
  method_s = method->value;

  cout << bh->m_table->m_scope->m_id << endl;

  m_scope = bh->m_table->m_root->get_scope (obj_type_s);
  m_symbol = m_scope->find (method_s, Record::METHOD);

  if (m_symbol->m_block.empty ())
    m_symbol->m_block = "Block_" + to_string (bh->m_counter++);

  r_s = m_symbol->m_block;

  count = 0;

  if (this->children.size () > 2)
    {
      args = (*this)[2];

      args->generate_tacs (arguments, t_s, bh);

      if (args->type != "expression_lst")
        arguments.push_back (new ParameterTAC (t_s));

      for (TAC *a : arguments)
        {
          tacs.push_back (a);
          if (dynamic_cast<ParameterTAC *> (a) != nullptr)
            count++;
        }
    }

  if (target.empty ())
    t_s = "_t" + to_string (tacs.size ());
  else
    t_s = target;

  tac = new MethodTAC (t_s, r_s, count);
  tacs.push_back (tac);
  target = t_s;
}

void
SyAssignArr::generate_tacs (std::vector<TAC *> &tacs, std::string &target, BlockHandler *bh)
{
  string t_s, i_s, r_s;
  Node *index, *right;

  index = (*this)[1];
  right = (*this)[2];

  index->generate_tacs (tacs, i_s, bh);
  right->generate_tacs (tacs, r_s, bh);

  target = (*this)[0]->value;

  tacs.push_back (new ArrayAccessTAC (target, r_s, i_s, false));
}

void
SyExpressionList::generate_tacs (std::vector<TAC *> &tacs, std::string &target, BlockHandler *bh)
{
  Node *left, *right;
  string t_s, l_s, r_s;
  ParameterTAC *tac;

  left = (*this)[0];
  right = (*this)[1];

  left->generate_tacs (tacs, l_s, bh);
  right->generate_tacs (tacs, r_s, bh);

  if (!r_s.empty ())
    {
      tac = new ParameterTAC (r_s);
      tacs.push_back (tac);
    }

  if (!l_s.empty ())
    {
      tac = new ParameterTAC (l_s);
      tacs.push_back (tac);
    }
}

void
SyOperator::generate_tacs (vector<TAC *> &tacs, string &target, BlockHandler *bh)
{
  Node *left, *right;
  string t_s, l_s, r_s, op;
  ExpressionTAC *tac;

  left = (*this)[0];
  right = (*this)[1];

  op = this->value;

  left->generate_tacs (tacs, l_s, bh);
  right->generate_tacs (tacs, r_s, bh);

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
SyLength::generate_tacs (std::vector<TAC *> &tacs, std::string &target, BlockHandler *bh)
{
  string t_s, r_s;
  Node *right;
  LengthTAC *tac;

  right = (*this)[0];
  right->generate_tacs (tacs, r_s, bh);

  if (target.empty ())
    {
      t_s = "_t" + to_string (tacs.size ());
      target = t_s;
    }
  else
    t_s = target;

  tac = new LengthTAC (t_s, r_s);
  tacs.push_back (tac);
}

void
SyArrayPull::generate_tacs (vector<TAC *> &tacs, string &target, BlockHandler *bh)
{
  string t_s, l_s, r_s;
  Node *left, *right;

  left = (*this)[0];
  right = (*this)[1];

  left->generate_tacs (tacs, l_s, bh);
  right->generate_tacs (tacs, r_s, bh);

  if (target.empty ())
    {
      t_s = "_t" + to_string (tacs.size ());
      target = t_s;
    }
  else
    t_s = target;

  tacs.push_back (new ArrayAccessTAC (t_s, l_s, r_s, true));
}

void
SyIdentifier::generate_tacs (std::vector<TAC *> &tacs, string &target, BlockHandler *bh)
{
  target = (*this)[0]->value;
}

void
SyNumber::generate_tacs (std::vector<TAC *> &tacs, std::string &target, BlockHandler *bh)
{
  target = this->value;
}

void
SyBoolean::generate_tacs (std::vector<TAC *> &tacs, std::string &target, BlockHandler *bh)
{
  target = this->value;
}

void
SyThis::generate_tacs (std::vector<TAC *> &tacs, std::string &target, BlockHandler *bh)
{
  target = "this";
}

void
SyArrayInit::generate_tacs (std::vector<TAC *> &tacs, std::string &target, BlockHandler *bh)
{
  ArrayNewTAC *tac;
  Node *right;
  string r_s, t_s;

  right = (*this)[0];

  right->generate_tacs (tacs, r_s, bh);

  if (target.empty ())
    {
      t_s = "_t" + to_string (tacs.size ());
      target = t_s;
    }
  else
    t_s = target;

  tac = new ArrayNewTAC (t_s, "int", r_s);
  tacs.push_back (tac);
}

void
SyObjectInit::generate_tacs (std::vector<TAC *> &tacs, std::string &target, BlockHandler *bh)
{
  string t_s, r_s;
  NewObjectTAC *tac;

  r_s = (*this)[0]->value;

  if (target.empty ())
    {
      t_s = "_t" + to_string (tacs.size ());
      target = t_s;
    }
  else
    t_s = target;

  tac = new NewObjectTAC (t_s, r_s);
  tacs.push_back (tac);
}

void
SyNot::generate_tacs (std::vector<TAC *> &tacs, std::string &target, BlockHandler *bh)
{
  Node *right;
  string t_s, l_s, r_s;
  UnaryExpressionTAC *tac;

  right = (*this)[0];
  right->generate_tacs (tacs, r_s, bh);

  l_s = this->value;

  if (target.empty ())
    {
      t_s = "_t" + to_string (tacs.size ());
      target = t_s;
    }
  else
    t_s = target;

  tac = new UnaryExpressionTAC (t_s, r_s, l_s);
  tacs.push_back (tac);
}
