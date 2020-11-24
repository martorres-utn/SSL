#include "Scanner.h"
#include "lex.yy.h"

int Scanner_GetNextToken()
{
    return yylex();
}