// Yueqiao Zhang
// yzhan79
// Hejia Su
// hesu

#ifndef TABLE_MANAGER_H
#define TABLE_MANAGER_H

#include <iostream>
#include <string>
#include "astree.h"
#include "symtable.h"
#include "symstack.h"

using namespace std;

class TableManager {
public:
    // public properties
    Symstack *symstack;
    symtable *type_names;
    FILE *out;     // .sym file
    astree *root;  // root of astree
    int scope_nr;  // number of scope

    const string *current_struct;
    const string *current_function;

    attr_bitset attr_prim;  // primitive attribute
    attr_bitset attr_ref;  // reference attribute
    attr_bitset attr_prim_or_ref;  // primitive or reference attribute
    attr_bitset attr_array;  // array attribtue

    // number of errors
    // if there are some error(s), don't generate oil code
    unsigned errors;

    // constructor: takes the root of ast and .sym file
    TableManager(astree *root, FILE *out);

    // dump symbol table(s) to out file, .sym file
    void print_symtables();

private:
    int tok2attr(int token);
    string attrs2str(symbol *s, int exclude);
    symbol *get_declared_symbol(attr_bitset attrs, symtable *table,
        astree *node, size_t block_nr);
    void process_field(symtable *table, astree *node);
    void traverse_fields(symbol *s, astree *node, astree *type_id_node);
    void traverse_struct(astree *node);
    symbol *process_parameter(symtable *table, astree *node);
    void traverse_parameters(symbol *s, astree *node);
    void traverse_block(astree *node);
    void traverse_function(astree *node);
    void process_decl(astree *node);
    void check_field(astree *node);
    void check_array(astree *node);
    void process_base_type(astree *node);
    void check_type(astree *node);
    void process_node(astree *node);
    void traverse_next(astree *node);
    void end_block(astree *node);
    void traverse_ast(astree *node);

};

#endif
