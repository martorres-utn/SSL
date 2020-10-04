%{
#include <stdio.h>
%}

%option noyywrap

%%
[a-zA-Z]+ { printf("[ID]"); }
[0-9]+ { printf("[CONSTANT]"); }
\+ { printf("[+]"); }
\* { printf("[*]"); }
\( { printf("[(]"); }
\) { printf("[)]"); }
\= { printf("[=]"); }
\$ { printf("[$]"); }
\n { printf("\n"); };
. ;
%%

int main()
{
    yylex();
    return 0;
}