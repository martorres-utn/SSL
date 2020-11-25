#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "SemanticValue.h"
#include "Parser_Bison.tab.h"

void SemanticValue_SetString(char stringLexeme[])
{
    strcpy(yylval.strVal, stringLexeme);
}

void SemanticValue_SetInteger(char integerLexeme[])
{
    yylval.intVal = atoi(integerLexeme);
}