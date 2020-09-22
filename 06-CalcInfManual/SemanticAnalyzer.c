#include <stdio.h>
#include <string.h>
#include "SemanticAnalyzer.h"
#include "Scanner2.h"

int SemanticAnalyzer_FindValue(char name[])
{
    for(size_t pos = 0; pos < SEMANTIC_REGISTER_TABLE_SIZE; pos++)
        if(strcmp(name, VariableTable[pos].name) == 0)
            return VariableTable[pos].value;
    return -1; //uninitialized (?) //TODO debería devolver algo dentro del universo
}

SemanticRegister SemanticAnalyzer_GetID() 
{
    SemanticRegister sr;
    sr.type = RT_ID;
    Scanner_BufferGetContent(sr.name);
    sr.value = SemanticAnalyzer_FindValue(sr.name);
    return sr;
}

SemanticRegister SemanticAnalyzer_GetConstant()
{
    SemanticRegister sr;
    sr.type = RT_CONSTANT;
    strcpy(sr.name, "[constant]");
    char stringValue[SEMANTIC_REGISTER_VALUE_SIZE] = "";
    Scanner_BufferGetContent(stringValue);
    sscanf(stringValue, "%d", &sr.value);
    return sr;
}

SemanticRegister SemanticAnalyzer_EvaluateProd(SemanticRegister operand1, SemanticRegister operand2) 
{
    SemanticRegister result;
    result.type = RT_CONSTANT;
    result.value = operand1.value * operand2.value;
    return result;
}

SemanticRegister SemanticAnalyzer_EvaluateSum(SemanticRegister operand1, SemanticRegister operand2) 
{
    SemanticRegister result;
    result.type = RT_CONSTANT;
    result.value = operand1.value + operand2.value;
    return result;
}

void SemanticAnalyzer_Assign(SemanticRegister regID, SemanticRegister regConstant)
{
    size_t pos;
    size_t max = SEMANTIC_REGISTER_TABLE_SIZE;
    for(size_t pos = 0; pos < max; pos++)
    {
        if(strcmp(regID.name, VariableTable[pos].name) == 0)
        {
            VariableTable[pos].value = regConstant.value;
            return;
        }
    }

    SemanticRegister newReg = { .type = (RegisterType)regID.type, .value = (int)regConstant.value };
    strcpy(newReg.name, regID.name);

    VariableTable[VariableTableTop++] = newReg;
}

void SemanticAnalyzer_CleanVariableTable()
{
    size_t pos;
    size_t max = SEMANTIC_REGISTER_TABLE_SIZE;
    for(size_t pos = 0; pos < max; pos++)
    {
        VariableTable[pos].type = RT_ID;
        strcpy(VariableTable[pos].name, "");
        VariableTable[pos].value = 0;
    }
    VariableTableTop = 0;
}