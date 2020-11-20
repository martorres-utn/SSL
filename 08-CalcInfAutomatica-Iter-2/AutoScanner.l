%{
#include <stdio.h>
#include "SemanticValue.h"
#include "AutoParser.tab.h" //new automatic token definition

int fileno( FILE * stream ); /*removes warning: implicit declaration*/
%}

%option noyywrap

%%
[a-zA-Z]+ { strcpy(yylval.strVal, yytext); return TK_ID; }
[0-9]+ { /*printf("[debug - AutoScanner - TK_CONSTANT: processing yytext value as constant:%s]\n", yytext);*/ yylval.intVal = atoi(yytext); return TK_CONSTANT; }
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