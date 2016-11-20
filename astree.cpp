// $Id: astree.cpp,v 1.8 2016-09-21 17:13:03-07 - - $

#include <assert.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "astree.h"
#include "string_set.h"
#include "lyutils.h"

astree::astree (int symbol_, const location& lloc_, const char* info) {
    symbol = symbol_;
    lloc = lloc_;
    lexinfo = string_set::intern (info);
    // vector defaults to empty -- no children
}

astree::~astree() {
    while (not children.empty()) {
        astree* child = children.back();
        children.pop_back();
        delete child;
    }
    if (yydebug) {
        fprintf (stderr, "Deleting astree (");
        astree::dump (stderr, this);
        fprintf (stderr, ")\n");
    }
}

astree* astree::adopt (astree* child1, astree* child2, astree* child3) {
    if (child1 != nullptr) children.push_back (child1);
    if (child2 != nullptr) children.push_back (child2);
    if (child3 != nullptr) children.push_back (child3);
    return this;
}

astree* astree::adopt_sym (astree* child, int symbol_) {
    symbol = symbol_;
    return adopt (child);
}


void astree::dump_node (FILE* outfile) {
    fprintf (outfile, "%p->{%s %zd.%zd.%zd \"%s\":",
             this, parser::get_tname (symbol),
             lloc.filenr, lloc.linenr, lloc.offset,
             lexinfo->c_str());
    for (size_t child = 0; child < children.size(); ++child) {
        fprintf (outfile, " %p", children.at(child));
    }
}

void astree::dump_tree (FILE* outfile, int depth) {
    fprintf (outfile, "%*s", depth * 3, "");
    dump_node (outfile);
    fprintf (outfile, "\n");
    for (astree* child: children) child->dump_tree (outfile, depth + 1);
    fflush (NULL);
}

void astree::dump (FILE* outfile, astree* tree) {
    if (tree == nullptr) fprintf (outfile, "nullptr");
    else tree->dump_node (outfile);
}

void astree::print (FILE* outfile, astree* tree, int depth) {
    fprintf (outfile, "; %*s", depth * 3, "");
    fprintf (outfile, "%s \"%s\" (%zd.%zd.%zd)\n",
             parser::get_tname (tree->symbol), tree->lexinfo->c_str(),
             tree->lloc.filenr, tree->lloc.linenr, tree->lloc.offset);
    for (astree* child: tree->children) {
        astree::print (outfile, child, depth + 1);
    }
}

void destroy (astree* tree1, astree* tree2) {
    if (tree1 != nullptr) delete tree1;
    if (tree2 != nullptr) delete tree2;
}

void errllocprintf (const location& lloc, const char* format,
                    const char* arg) {
    static char buffer[0x1000];
    assert (sizeof buffer > strlen (format) + strlen (arg));
    snprintf (buffer, sizeof buffer, format, arg);
    errprintf ("%s:%zd.%zd: %s",
               lexer::filename (lloc.filenr), lloc.linenr, lloc.offset,
               buffer);
}

static string enum_tostring(size_t i){
   switch(i){
   case 0: return "void";
   case 1: return "bool";
   case 2: return "char";
   case 3: return "int";
   case 4: return "null";
   case 5: return "string";
   case 6: return "struct";
   case 7: return "array";
   case 8: return "function";
   case 9: return "variable";
   case 10: return "field";
   case 11: return "typeid";
   case 12: return "param";
   case 13: return "lval";
   case 14: return "const";
   case 15: return "vreg";
   case 16: return "vaddr";
   case 17: return "bitset_size";
   }
   return "invalid_enum";
}

string enum_bitset(attr_bitset a){
   string buf;
   for(int i=0; i<attr_bitset_size; ++i){
      if(a[i]){
         buf += enum_tostring(i);
         buf += " ";
      }
   }
   return buf;
}

