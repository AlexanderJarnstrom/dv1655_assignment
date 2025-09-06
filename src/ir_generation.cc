#include "../inc/ir_generation.h"

BlockHandler*
generate_ir(Node* r, SymbolTable* t)
{
  BlockHandler* bh = new BlockHandler(t);
  r->generate_block(bh);
  return bh;
}

