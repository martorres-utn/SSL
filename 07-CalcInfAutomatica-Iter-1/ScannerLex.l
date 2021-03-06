%{
#include <stdio.h>
#include "ScannerTypes.h"

int fileno( FILE * stream ); /*removes warning: implicit declaration*/
%}

%option noyywrap

%%
[a-zA-Z]+ { return T_ID; }
[0-9]+ { return T_CONSTANT; }
\+ { return T_OP_PLUS; }
\* { return T_OP_PROD; }
\( { return T_L_PAR; }
\) { return T_R_PAR; }
\= { return T_ASSIGN; }
\$ { return T_PRINT; }
\n { return T_END; };
<<EOF>> { return T_END; }
[ ]+ ;
. { printf("[lexical error: unrecognized symbol at %s]", yytext); };
%%

/*int main()
{
    yylex();
    return 0;
}*/