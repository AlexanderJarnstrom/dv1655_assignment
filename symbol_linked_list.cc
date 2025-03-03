#include "symbol_linked_list.h"

SymbolLinkedList* SymbolLinkedList::next_node() {
  return this->next;
}

void SymbolLinkedList::set_next_node(SymbolLinkedList* node) {
  this->next = node;
}

SymbolLinkedList* SymbolLinkedList::prev_node() {
  return this->before;
}

void SymbolLinkedList::set_prev_node(SymbolLinkedList* node) {
  this->before = node;
}

SymbolLinkedList* SymbolLinkedList::find(const std::string& name) {
  SymbolLinkedList* temp = this;

  while (temp != nullptr && temp->name != name) {
    temp = temp->next;
  }

  return temp;
}

void SymbolLinkedList::print() {
  SymbolLinkedList* temp = this;

  while (temp != nullptr) {
    printf("\t%s\n", temp->name.c_str());
    temp = temp->next_node();
  }
}
