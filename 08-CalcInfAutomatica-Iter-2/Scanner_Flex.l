%{
#include <stdio.h>
#include "SemanticValue.h"

#ifdef AUTOMATIC_PARSER
#include "Parser_Bison.tab.h" //new automatic token definition
#else
#include "TokenDefinition.h"
#endif

int fileno( FILE * stream ); /*removes warning: implicit declaration*/

%}

%option noyywrap

%%
[a-zA-Z]+ { SemanticValue_SetString(yytext); return TK_ID; }
[0-9]+ { SemanticValue_SetInteger(yytext); return TK_CONSTANT; }
\+ { return TK_OP_PLUS; }
\* { return TK_OP_PROD; }
\( { return TK_L_PAR; }
\) { return TK_R_PAR; }
\= { return TK_ASSIGN; }
\$ { return TK_PRINT; }
\n { return TK_END_STATEMENT; };
<<EOF>> { return TK_END_PROGRAM; }
[ ]+ ;
. { printf("[lexical error: unrecognized symbol at %s]", yytext); };
%%