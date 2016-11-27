
#ifndef __EMIT_H__
#define __EMIT_H__

#include "astree.h"

// print string constants
// call this function in parser.y
void emit_stringcon(astree* tree);

// call this function in main to print "oil"
void emit_everything(FILE *oil_file, astree *root, unsigned error_nr);

#endif
