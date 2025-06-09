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
  int m_line_nbr;
  
  hash_t m_hash;

  SymbolNode* mp_left;
  SymbolNode* mp_right;
  SymbolNode* mp_table;

  SymbolNode* find_node(const hash_t);

public:
  SymbolNode(std::string, node_t, value_t, int);
  SymbolNode(SymbolNode*);
  ~SymbolNode();

  const std::string get_name();
  const node_t get_node_type();
  const value_t get_value_type();
  const int get_line_number();
  SymbolNode* get_table();

  void generate_table(Node*, int &counter);

  void isnert_node(SymbolNode*);
  SymbolNode* get_node(const std::string);

  void print(int level = 0);


  std::vector<SymbolNode*> get_classes(bool started = false);
  std::vector<SymbolNode*> get_methods(bool started = false);
  std::vector<SymbolNode*> get_blocks(bool started = false);

};

#endif // !SYM_NODE
