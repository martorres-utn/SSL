#include <stdio.h>
//#include "Parser.h"
#include "AutoParser.tab.h"

int main(void)
{
    //Parser_SAP_Target();

    switch( yyparse() ){
    case 0:
        puts("Pertenece al LIC"); return 0;
    case 1:
        puts("No pertenece al LIC"); return 1;
    case 2:
        puts("Memoria insuficiente"); return 2;
    }

    return 0;
}