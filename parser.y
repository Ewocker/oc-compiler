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

%nonassoc '('

%start program

%%

program : stmtseq               { $$ = $1 = nullptr; }
        | program structdef		{ $$ = $1->adopt($2);}
        | program function 		{ $$ = $1->adopt($2);}
        | program statement 	{ $$ = $1->adopt($2);}
        |                       { $$ = new astree(TOK_ROOT, {0,0,0},"");}
        ;

stmtseq : stmtseq expr ';'      { destroy ($3); $$ = $1->adopt ($2); }
        | stmtseq error ';'     { destroy ($3); $$ = $1; }
        | stmtseq ';'           { destroy ($2); $$ = $1; }
        |                       { $$ = parser::root; }
        ;

structdef   : structcont '}'    { $$ = $1; }
            ;

structcont  : structcont fielddecl ';'      { $$ = $1->adopt($2); destroy($3); }
            | TOK_STRUCT TOK_IDENT '{'      { $2->symbol = TOK_TYPEID; $$ = $1->adopt($2); }
            ;

fielddecl   : basetype TOK_IDENT  { $2->symbol = TOK_FIELD; $$ = $1->adopt($2);}
            | basetype TOK_ARRAY TOK_IDENT { $3->symbol = TOK_FIELD; $$ = $2->adopt($1, $3);}
            ;

basetype    : TOK_VOID      { $$ = $1; }
            | TOK_INT       { $$ = $1; }
            | TOK_STRING    { $$ = $1; }
            | TOK_IDENT     { $1->symbol = TOK_TYPEID; $$ = $1; }
            ;

function    : identdecl funcargs ')' block      { $$ = (new astree(TOK_FUNCTION, $1->lloc, ""))->adopt($1, $2, $4); destroy($3); }
            | identdecl funcargs ')' ';'        { $$ = (new astree(TOK_PROTOTYPE, $1->lloc, ""))->adopt($1, $2); destroy($3, $4); }
            | identdecl '(' ')' block           { $2->symbol = TOK_PARAMLIST; $$ = (new astree(TOK_FUNCTION, $1->lloc, ""))->adopt($1,$2,$4); destroy($3); }
            | identdecl '(' ')' ';'             { $2->symbol = TOK_PARAMLIST; $$ = (new astree(TOK_PROTOTYPE, $1->lloc, ""))->adopt($1,$2); destroy($3,$4); }
            ;

funcargs    : funcargs ',' identdecl    { $$ = $1->adopt($3); }
            | '(' identdecl             { $1->symbol = TOK_PARAMLIST; $$ = $1->adopt($2); }

identdecl   : basetype TOK_IDENT    { $2->symbol = TOK_DECLID; $$ = $1->adopt($2); }
            | basetype TOK_ARRAY TOK_IDENT  { $3->symbol = TOK_DECLID; $$ = $2->adopt($1,$3); }

block   : blockbody '}'     { $$ = $1; }
        | ';'   { $$ = $1; }
        ;

blockbody   : blockbody statement   { $$ = $1->adopt($2); }
            | '{' statement         { $1->symbol = TOK_BLOCK; $$ = $1->adopt($2); }
            | '{'                   { $1->symbol = TOK_BLOCK; $$ = $1; }
            ;

statement   : block     { $$ = $1; }
            | vardecl   { $$ = $1; }
            | while     { $$ = $1; }
            | ifelse    { $$ = $1; }
            | return    { $$ = $1; }
            | expr ';'  { $$ = $1; }
            ;

vardecl     : identdecl '=' expr ';'    { $2->symbol = TOK_VARDECL; $$ = $2->adopt($1, $3); destroy($4); }
            ;

while   : TOK_WHILE '(' expr ')' statement  { $$ = $1->adopt($3, $5); destroy($2,$4); }
        ;

ifelse  : TOK_IF '(' expr ')' statement     { $$ = $1->adopt($3, $5); destroy($2,$4);}
        | TOK_IF '(' expr ')' statement TOK_ELSE statement  { $$ = $1->adopt($3,$5); $7->symbol = TOK_IFELSE; $1->adopt($7); destroy($2,$4); }
        ;

return  : TOK_RETURN expr ';'   { $$ = $1->adopt($2); destroy($3); }
        | TOK_RETURN ';'        { $1->symbol = TOK_RETURNVOID; $$ = $1; destroy($2); }
        ;

expr    : expr binop expr       { $$ = $2->adopt ($1, $3); }
        | unop expr             { $$ = $1->adopt($2); }
        | allocator             { $$ = $1; }
        | call                  { $$ = $1; }
        | '(' expr ')'          { destroy ($1, $3); $$ = $2; }
        | variable              { $$ = $1; }
        | constant              { $$ = $1; }
        | IDENT                 { $$ = $1; }
        | NUMBER                { $$ = $1; }
        ;

binop   : TOK_EQ    { $$ = $1; }
        | TOK_NE    { $$ = $1; }
        | TOK_LT    { $$ = $1; }
        | TOK_LE    { $$ = $1; }
        | TOK_GT    { $$ = $1; }
        | TOK_GE    { $$ = $1; }
        | '+'       { $$ = $1; }
        | '-'       { $$ = $1; }
        | '*'       { $$ = $1; }
        | '/'       { $$ = $1; }
        | '='       { $$ = $1; }
        | '^'       { $$ = $1; }
        ;

unop    : TOK_POS               { $$ = $1; }
        | TOK_NEG               { $$ = $1; }
        | '!'                   { $$ = $1; }
        | TOK_NEW               { $$ = $1; }
        | TOK_ORD               { $$ = $1; }
        | TOK_CHR               { $$ = $1; }
        ;

variable    : TOK_IDENT             { $$ = $1; }
            | expr '[' expr ']'     { destroy($4); $2->symbol = TOK_INDEX; $$ = $2->adopt($1,$3); }
            | expr '.' TOK_IDENT    { $3->symbol = TOK_FIELD; $$ = $2->adopt($1,$3); }
            ;

constant    : TOK_INTCON    { $$ = $1; }
            | TOK_CHARCON   { $$ = $1; }
            | TOK_STRINGCON { $$ = $1; }
            | TOK_FALSE     { $$ = $1; }
            | TOK_TRUE      { $$ = $1; }
            | TOK_NULL      { $$ = $1; }
            ;

allocator   : TOK_NEW TOK_IDENT '(' ')'         { $2->symbol = TOK_TYPEID; $$ = $1->adopt($2); destroy($3,$4); }
            | TOK_NEW TOK_STRING '(' expr ')'   { $1->symbol = TOK_NEWSTRING; $$ = $1->adopt($4); destroy($3,$5); }
            | TOK_NEW basetype '[' expr ']'     { $1->symbol = TOK_NEWARRAY; $$ = $1->adopt($2,$4); destroy($3,$5); }
            ;

call    : TOK_IDENT '(' ')'     { $2->symbol = TOK_CALL; $$ = $2->adopt($1); }
        | exprs ')'             { $$ = $1; }
        ;

exprs   : TOK_IDENT '(' expr    { $$ = $1->adopt($3); }
        | exprs ',' expr        { $2->symbol = TOK_CALL; $$ = $2->adopt($1,$3); }
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

 %destructor { destroy ($$); } <>
%printer { astree::dump (yyoutput, $$); } <>
 */

