#ifndef SYM_NODE
#define SYM_NODE

#include "node.h"
#include "types.h"

#include <string>
#include <vector>

class SymbolNode
{
  std::string m_name;
  node_t m_node_type;
  value_t m_value_type;
  
  hash_t m_hash;

  SymbolNode* mp_left;
  SymbolNode* mp_right;
  SymbolNode* mp_table;

public:
  SymbolNode(std::string, node_t, value_t);
  ~SymbolNode();

  void generate_table(Node*, int &counter);
  void isnert_node(SymbolNode*);
  void print(int level = 0);
  std::vector<SymbolNode*> get_scopes();
};

#endif // !SYM_NODE
