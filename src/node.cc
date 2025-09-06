#include "../inc/node.h"

using namespace std;

Node::Node(string t, string v, int l) : type(t), value(v), lineno(l)
{}

Node::Node()
{
  this->type = "uninitialised";
  this->value = "uninitialised";
}   // Bison needs this.

Node::~Node()
{
  for (Node* n : children)
    delete n;
}

void
Node::pre_execute(SymbolTable*)
{}

void
Node::in_execute(SymbolTable*)
{}

void
Node::post_execute(SymbolTable*)
{}

void
Node::generate_block(BlockHandler* bh)
{
  for (Node* c : this->children)
    c->generate_block(bh);
}

vector<TAC>
Node::generate_tacs()
{
  return vector<TAC>();
}

std::string
Node::get_type(SymbolTable*)
{
  return "";
}

void
Node::print_tree(int depth)
{
  for(int i=0; i<depth; i++)
    cout << "  ";
  cout << "[" << lineno << "] " << type << ":" << value << endl; //<< " @line: "<< lineno << endl;
  for(auto i=children.begin(); i!=children.end(); i++)
    (*i)->print_tree(depth+1);
}

Node*
Node::operator[](const int& i)
{
  int x = 0;

  for (Node* child : this->children)
  {
    if (x == i) {
      return child;
    }
    x++;
  }

  return nullptr;
}

void
Node::generate_tree()
{
  std::ofstream outStream;
  const char* filename = "tree.dot";
  outStream.open(filename);

  int count = 0;
  outStream << "digraph {" << std::endl;
  generate_tree_content(count, &outStream);
  outStream << "}" << std::endl;
  outStream.close();

  printf("\nBuilt a parse-tree at %s. Use 'make tree' to generate the pdf version.\n", filename);
}

void
Node::generate_tree_content(int &count, ofstream *outStream)
{
  id = count++;
  *outStream << "n" << id << " [label=\"" 
    << type << ":" << value << "\"];" << endl;

  for (auto i = children.begin(); i != children.end(); i++)
  {
    (*i)->generate_tree_content(count, outStream);
    *outStream << "n" << id << " -> n" << (*i)->id << endl;
  }
}


