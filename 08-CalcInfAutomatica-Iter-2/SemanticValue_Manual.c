#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "SemanticValue.h"

void SemanticValue_SetString(char stringLexeme[])
{
    strcpy(LastSemanticValue.strVal, stringLexeme);

}

void SemanticValue_SetInteger(char integerLexeme[])
{
    LastSemanticValue.intVal = atoi(integerLexeme);
}