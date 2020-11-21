#include "Parser.h"
#include "AutoParser.tab.h"

void Parser_SAP_Target() 
{
    switch( yyparse() ){
    case 0:
        puts("Pertenece al LIC"); return;
    case 1:
        puts("No pertenece al LIC"); return;
    case 2:
        puts("Memoria insuficiente"); return;
    }
}