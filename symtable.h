//Yueqiao Zhang
// yzhan79
// Hejia Su
// hesu

#ifndef __SYMTABLE_H__
#define __SYMTABLE_H__

#include <vector>
#include <unordered_map>
#include <string>
#include <utility>
#include <bitset>
#include <iostream>

#include "string_set.h"
#include "lyutils.h"
#include "astree.h"

using namespace std;

struct symbol;
struct astree;

/* symbol table and symbol entry */
using symtable = unordered_map<string*, symbol*>;
using symbol_entry = symtable::value_type;

/* symbol */
struct symbol {
    attr_bitset attributes;
    symtable* fields;
    size_t filenr, linenr, offset;
    size_t block_nr;
    vector<symbol*> parameters;

    astree *node;
    const string *type_name;
};

// create a new symbol
symbol *create_symbol(astree *node);

// insert a new symbol into the symbol table
symbol *symtable_insert(symtable *table, astree *node);

// symbol table search for lexinfo of the node
symbol *symtable_search(symtable *table, astree *node);

// symbol table search for type name of the node
symbol *symtable_search_type_name(symtable *table, astree *node);


#endif
