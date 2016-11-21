// Yueqiao Zhang
// yzhan79
// Hejia Su
// hesu

#ifndef SYMSTACK_H
#define SYMSTACK_H

#include <vector>
#include "symtable.h"

/* symbol stack */
class Symstack {
public:
    // public properties
    vector<size_t> block_stack;
    vector<symtable *> symtable_stack;
    size_t next_block;

    // constructor
    Symstack();

    // enter block and leave block
    void enter_block();
    void leave_block();

    // define an identifier
    void define_ident(astree *node);

    // search for an identifier
    symbol *search_ident(astree *node);

    // look at the top of the stack,
    // if there is nothing, create a symtable
    symtable *peek();
};

#endif
