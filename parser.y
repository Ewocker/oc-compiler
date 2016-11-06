%{
    // Dummy parser for scanner project.
    
    #include <cassert>
    #include <assert.h>
	#include <stdlib.h>
	#include <string.h>
    
    #include "lyutils.h"
    #include "astree.h"
    
    %}

%debug
%defines
%error-verbose
%token-table
%verbose

%destructor { destroy ($$); } <>
%printer { astree::dump (yyoutput, $$); } <>

%initial-action {
   parser::root = new astree (ROOT, {0, 0, 0}, "<<ROOT>>");
}
%token  ROOT IDENT NUMBER

// reserved words
%token TOK_VOID TOK_BOOL TOK_CHAR TOK_INT TOK_STRING
%token TOK_IF TOK_ELSE TOK_WHILE TOK_RETURN TOK_STRUCT
%token TOK_FALSE TOK_TRUE TOK_NULL TOK_NEW TOK_ORD TOK_CHR

// two-character symbols
%token TOK_EQ TOK_NE TOK_LE TOK_GE TOK_ARRAY

// patterns
%token TOK_IDENT TOK_INTCON TOK_CHARCON TOK_STRINGCON

// synthetic tokens
%token TOK_ROOT TOK_BLOCK TOK_PARAMLIST TOK_DECLID
%token TOK_FUNCTION TOK_TYPEID TOK_FIELD TOK_VARDECL TOK_IFELSE
%token TOK_RETURNVOID TOK_NEWSTRING TOK_NEWARRAY TOK_INDEX
%token TOK_PROTOTYPE TOK_CALL TOK_POS TOK_NEG

%right TOK_IF TOK_ELSE
%right '='
%left  TOK_EQ TOK_NE TOK_LT TOK_LE TOK_GT TOK_GE
%left  '+' '-'
%left  '*' '/' '%'
%right '^'
%right POS NEG
%right TOK_POS TOK_NEG '!' TOK_NEW TOK_ORD TOK_CHR
%left  TOK_ARRAY TOK_FIELD TOK_FUNCTION
%left  '[' '.'

%nonassoc TOK_NEW
%nonassoc TOK_PARENS

%start program

%%

program : stmtseq               { $$ = $1 = nullptr; }
        | program structdef		{ $$ = $1->adopt($2);}
        | program function 		{ $$ = $1->adopt($2);}
        | program statement 	{ $$ = $1->adopt($2);}
        |                       { $$ = new_parseroot();}
        ;

stmtseq : stmtseq expr ';'      { destroy ($3); $$ = $1->adopt ($2); }
        | stmtseq error ';'     { destroy ($3); $$ = $1; }
        | stmtseq ';'           { destroy ($2); $$ = $1; }
        |                       { $$ = parser::root; }
        ;

expr    : expr '=' expr         { $$ = $2->adopt ($1, $3); }
        | expr '+' expr         { $$ = $2->adopt ($1, $3); }
        | expr '-' expr         { $$ = $2->adopt ($1, $3); }
        | expr '*' expr         { $$ = $2->adopt ($1, $3); }
        | expr '/' expr         { $$ = $2->adopt ($1, $3); }
        | expr '^' expr         { $$ = $2->adopt ($1, $3); }
        | '+' expr %prec POS    { $$ = $1->adopt_sym ($2, POS); }
        | '-' expr %prec NEG    { $$ = $1->adopt_sym ($2, NEG); }
        | '(' expr ')'          { destroy ($1, $3); $$ = $2; }
        | IDENT                 { $$ = $1; }
        | NUMBER                { $$ = $1; }
        ;

structdef   : structcont '}'    { $$ = $1; destroy ($2);}
            ;

structcont  : structcont fielddecl ';'      { $$ = $1->adopt($2); destroy($3)}
            | TOK_STRUCT TOK_IDENT '{'      { $2->symbol = TOK_TYPEID; $$ = $1->adopt($2); destroy($3);}
            ;

fielddecl   : basetype TOK_IDENT  { $2->symbol = TOK_FIELD; $$ = $1->adopt($2);}
            | basetype TOK_ARRAY TOK_IDENT { $3->symbol = TOK_FIELD; $$ = $2->adopt($1, $3);}
            ;

basetype    : TOK_VOID      { $$ = $1; }
            | TOK_INT       { $$ = $1; }
            | TOK_STRING    { $$ = $1; }
            | TOK_IDENT     { $1->symbol = TOK_TYPEID; $$ = $1; }
            ;
%%


const char *parser::get_tname (int symbol) {
    return yytname [YYTRANSLATE (symbol)];
}


bool is_defined_token (int symbol) {
    return YYTRANSLATE (symbol) > YYUNDEFTOK;
}

/*
 static void* yycalloc (size_t size) {
 void* result = calloc (1, size);
 assert (result != nullptr);
 return result;
 }
 */

