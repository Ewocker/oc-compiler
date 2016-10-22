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

"#".*           { scanner_include(); }
[ \t]+          { IGNORE (white space) }
\n              { scanner_newline(); }

"void"          { return yylval_token(TOK_VOID); }
"bool"          { return yylval_token(TOK_BOOL); }
"char"          { return yylval_token(TOK_CHAR); }
"int"           { return yylval_token(TOK_INT); }
"string"        { return yylval_token(TOK_STRING); }
"struct"        { return yylval_token(TOK_STRUCT); }
"if"            { return yylval_token(TOK_IF); }
"else"          { return yylval_token(TOK_ELSE); }
"while"         { return yylval_token(TOK_WHILE); }
"return"        { return yylval_token(TOK_RETURN); }
"false"         { return yylval_token(TOK_FALSE); }
"true"          { return yylval_token(TOK_TRUE); }
"null"          { return yylval_token(TOK_NULL); }
"ord"           { return yylval_token(TOK_ORD); }
"chr"           { return yylval_token(TOK_CHR); }
"new"           { return yylval_token(TOK_NEW); }

{NUMBER}        { return yylval_token (TOK_INTCON); }
{CHAR}     { return yylval_token (TOK_CHARCON); }
{STRING}        { return yylval_token (TOK_STRINGCON); }
{IDENT}         { return yylval_token (TOK_IDENT); }

"="             { return yylval_token ('='); }
"+"             { return yylval_token ('+'); }
"-"             { return yylval_token ('-'); }
"*"             { return yylval_token ('*'); }
"/"             { return yylval_token ('/'); }
"^"             { return yylval_token ('^'); }
"("             { return yylval_token ('('); }
")"             { return yylval_token (')'); }
"["             { return yylval_token ('['); }
"]"             { return yylval_token (']'); }
"{"             { return yylval_token ('{'); }
"}"             { return yylval_token ('}'); }
";"             { return yylval_token (';'); }
","             { return yylval_token (','); }
"."             { return yylval_token ('.'); }
"<"             { return yylval_token ('<'); }
">"             { return yylval_token ('>'); }
"%"             { return yylval_token ('%'); }
"!"             { return yylval_token ('!'); }

"[]"            { return yylval_token (TOK_ARRAY); }
"=="            { return yylval_token (TOK_EQ); }
"!="            { return yylval_token (TOK_NE); }
"<="            { return yylval_token (TOK_LE); }
">="            { return yylval_token (TOK_GE); }

.               { lexer_badchar (*yytext); }
%%