#pragma once
#include <stdio.h>

#define SEMANTIC_REGISTER_NAME_SIZE 33
#define SEMANTIC_REGISTER_VALUE_SIZE 33
#define SEMANTIC_REGISTER_TABLE_SIZE 10

enum PossibleSemanticRegisterTypes {
    RT_ID = 0,
    RT_CONSTANT
};

typedef enum PossibleSemanticRegisterTypes RegisterType;

struct SemanticRegisterStruct
{
    RegisterType type; //TODO: no es necesario
    char name[SEMANTIC_REGISTER_NAME_SIZE];
    int value;
};

typedef struct SemanticRegisterStruct SemanticRegister;
static SemanticRegister VariableTable[SEMANTIC_REGISTER_TABLE_SIZE]; //TODO: VariableTable
static size_t VariableTableTop = 0;

//SemanticAnalyzer - Semantic building procedures
int SemanticAnalyzer_FindIDValue(char idName[]);
SemanticRegister SemanticAnalyzer_GetID();
SemanticRegister SemanticAnalyzer_GetConstant();
SemanticRegister SemanticAnalyzer_EvaluateProd(SemanticRegister operand1, SemanticRegister operand2);
SemanticRegister SemanticAnalyzer_EvaluateSum(SemanticRegister operand1, SemanticRegister operand2);
void SemanticAnalyzer_Assign(SemanticRegister regID, SemanticRegister regConstant);
void SemanticAnalyzer_CleanVariableTable();