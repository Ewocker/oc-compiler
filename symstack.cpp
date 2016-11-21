#include "symstack.h"


symtable *Symstack::peek() {
    if (symtable_stack.back() == nullptr) {
        symtable_stack.back() = new symtable();
    }

    return symtable_stack.back();
}

// constructor
Symstack::Symstack() {
    // initialize next_block to 1
    next_block = 1;

    // push a 0 onto the block stak
    block_stack.push_back(0);

    // push a new symtable onto the symtable stack
    symtable_stack.push_back(new symtable);
}

void Symstack::leave_block() {
    // pop the topmost symbol table
    symtable_stack.pop_back();

    // pop the topmost block number
    block_stack.pop_back();
}

void Symstack::enter_block() {
    // push nullptr onto the top of the symbol stack
    symtable_stack.push_back(nullptr);

    // push the current block number on to block symbol table stack
    block_stack.push_back(next_block);

    // increase next_block
    next_block++;
}

symbol *Symstack::search_ident(astree *node) {
    // starts from the top of the symbol table stak
    // search downward,
    // since local identifiers should hide global identifiers
    for (int i = symtable_stack.size() - 1; i >= 0; i--) {
        symtable *table = symtable_stack[i];

        if (table != nullptr && !table->empty()) {
            symbol *symbol = symtable_search(table, node);
            if (symbol != nullptr) return symbol;
        }
    }

    return nullptr;
}

void Symstack::define_ident(astree *node) {
    if (symtable_stack.back() == nullptr) {
        symtable_stack.back() = new symtable;
    }

    // insert symbol into the topmost symbol table
    symtable_insert(symtable_stack.back(), node);
}