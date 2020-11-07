#pragma once
#define YYSTYPE_IS_DECLARED 1

union SemanticValueUnion 
{
    int intVal;
    char strVal[33];
};

typedef union SemanticValueUnion YYSTYPE; //AutoParser lo usa