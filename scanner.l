%{
// $Id: scanner.l,v 1.4 2014-10-20 14:27:17-07 - - $

#include "auxlib.h"
#include "lyutils.h"

//INV_STRING      ((\"{STRINGLIT_ITEM}*)(({STRINGLIT_INV_ITEM}+({STRINGLIT_ITEM}*(\"|\n)))|\n))
#define YY_USER_ACTION  { lexer::advance(); }
#define IGNORE(THING)   { }

int yylval_token (int symbol) {
   yylval = new astree (symbol, lexer::lloc, yytext);
   return symbol;
}

%}

%option 8bit
%option debug
%option nodefault
%option noinput
%option nounput
%option noyywrap
%option warn
/*%option verbose*/

LETTER              [A-Za-z_]
DIGIT               [0-9]

NUMBER         ({DIGIT}+)
CHAR            ('([^\\'\n]|\\[\\'"0nt])')
STRING          (\"([^\\"\n]|\\[\\'"0nt])*\")
IDENT           ({LETTER}({LETTER}|{DIGIT})*)

%%

"#".*           { lexer::include(); }
[ \t]+          { IGNORE (white space) }
\n              { lexer::newline(); }

"void"          { RETURN (TOK_VOID); }
"bool"          { RETURN (TOK_BOOL); }
"char"          { RETURN (TOK_CHAR); }
"int"           { RETURN (TOK_INT); }
"string"        { RETURN (TOK_STRING); }
"struct"        { RETURN (TOK_STRUCT); }
"if"            { RETURN (TOK_IF); }
"else"          { RETURN (TOK_ELSE); }
"while"         { RETURN (TOK_WHILE); }
"return"        { RETURN (TOK_RETURN); }
"false"         { RETURN (TOK_FALSE); }
"true"          { RETURN (TOK_TRUE); }
"null"          { RETURN (TOK_NULL); }
"ord"           { RETURN (TOK_ORD); }
"chr"           { RETURN (TOK_CHR); }
"new"           { RETURN (TOK_NEW); }

"=="            { RETURN (TOK_EQ); }
"!="            { RETURN (TOK_NE); }
"<="            { RETURN (TOK_LE); }
">="            { RETURN (TOK_GE); }

{CHAR}          { RETURN (TOK_CHARCON); }
{STRING}        { RETURN (TOK_STRINGCON); }
{INTEGER}       { RETURN (TOK_INTCON); }
{IDENT}         { RETURN (TOK_IDENT); }

"[]"            { RETURN ('[]'); }
"("             { RETURN ('('); }
")"             { RETURN (')'); }
"["             { RETURN ('['); }
"]"             { RETURN (']'); }
"{"             { RETURN ('{'); }
"}"             { RETURN ('}'); }
";"             { RETURN (';'); }
","             { RETURN (','); }
"."             { RETURN ('.'); }
"="             { RETURN ('='); }
"<"             { RETURN ('<'); }
">"             { RETURN ('>'); }
"+"             { RETURN ('+'); }
"-"             { RETURN ('-'); }
"*"             { RETURN ('*'); }
"/"             { RETURN ('/'); }
"%"             { RETURN ('%'); }
"!"             { RETURN ('!'); }

.               { lexer::badchar (*yytext); }
%%
