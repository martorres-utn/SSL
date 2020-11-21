#pragma once
#define YYSTYPE_IS_DECLARED 1

union SemanticValueUnion 
{
    int intVal;
    char strVal[33];
};

typedef union SemanticValueUnion YYSTYPE; //AutoParser lo usa

typedef union SemanticValueUnion SemanticValue; //Parser Manual

SemanticValue LastSemanticValue; //Scanner Manual + Parser Manual