// $Id: astree.h,v 1.7 2016-10-06 16:13:39-07 - - $

#ifndef __ASTREE_H__
#define __ASTREE_H__

#include <string>
#include <vector>
#include <bitset>
#include <unordered_map>
using namespace std;

#include "auxlib.h"

struct symbol;
using symbol_table = unordered_map<string*,symbol*>;

enum { attr_void, attr_bool, attr_char, attr_int, attr_null,
attr_string, attr_struct, attr_array, attr_function,
attr_variable, attr_field, attr_typeid, attr_param, attr_lval,
attr_const, attr_vreg, attr_vaddr, attr_bitset_size,
};

using attr_bitset = bitset<attr_bitset_size>;


struct location {
    size_t filenr;
    size_t linenr;
    size_t offset;
};

struct astree {
    
    // Fields.
    int symbol;               // token code
    location lloc;            // source location
    const string* lexinfo;    // pointer to lexical information
    vector<astree*> children; // children of this n-way node
    
    // Functions.
    astree (int symbol, const location&, const char* lexinfo);
    ~astree();
    astree* adopt (astree* child1,
                   astree* child2 = nullptr, 
                   astree* child3 = nullptr);
    astree* adopt_sym (astree* child, int symbol);
    void dump_node (FILE*);
    void dump_tree (FILE*, int depth = 0);
    static void dump (FILE* outfile, astree* tree);
    static void print (FILE* outfile, astree* tree, int depth = 0);
    size_t blocknr;
    attr_bitset attr;
    symbol_table* struct_table;
    size_t deffilenr, deflinenr, defoffset;
};

void destroy (astree* tree1, astree* tree2 = nullptr);

void errllocprintf (const location&, const char* format, const char*);


astree* new_astree (int symbol, int filenr, int linenr,
                    int offset, const char* lexinfo);
astree* new_function (
      astree* identdecl, astree* paramlist, astree* block);
astree* new_proto (astree* identdecl, astree* paramlist);
string enum_bitset(attr_bitset a);

#endif
