#ifndef NODE_H
#define	NODE_H

#include "types.h"

#include <list>
#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;


class Node {
public:
	int id, lineno;
	string type, value;
  node_t node_type;

	list<Node*> children;
	Node(string t, string v, int l) : type(t), value(v), lineno(l)
  {
    if (t == "root") this->node_type = ROOT;
    else if (t == "main_class") this->node_type = MAIN_CLASS;
    else if (t == "class_decl") this->node_type = CLASS;
    else if (t == "statement") this->node_type = STATEMENT;
    else if (t == "expression") this->node_type = EXPRESION;
    else if (t == "method_decl" && v == "declaration") this->node_type = METHOD;
    else if (t == "var_decl") this->node_type = VARIABLE;
    else if (t == "method_arh") this->node_type = VARIABLE;
    else this->node_type = OTHER;
  }

	Node()
	{
    this->node_type = OTHER;
		this->type = "uninitialised";
		this->value = "uninitialised";
  }   // Bison needs this.
  
  void print_tree(int depth=0) {
    for(int i=0; i<depth; i++)
      cout << "  ";
    cout << type << "[" << node_type << "]"
      << ":" << value << endl; //<< " @line: "<< lineno << endl;
    for(auto i=children.begin(); i!=children.end(); i++)
      (*i)->print_tree(depth+1);
  }

  Node* operator[](const int& i) {
    int x = 0;

    for (Node* child : this->children) {
      if (x == i) {
        return child;
      }
      x++;
    }

    return nullptr;
  }
  
  void generate_tree() {
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

  void generate_tree_content(int &count, ofstream *outStream) {
    id = count++;
    *outStream << "n" << id << " [label=\"" << type << ":" << value << "\"];" << endl;

    for (auto i = children.begin(); i != children.end(); i++)
    {
      (*i)->generate_tree_content(count, outStream);
      *outStream << "n" << id << " -> n" << (*i)->id << endl;
    }
  }

};

#endif
