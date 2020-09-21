#pragma once

#include <stdio.h>
#include <stdbool.h>
#include "Scanner2.h"

#define TOKEN_BUFFER_SIZE 1000
#define PARSER_LOOP_LIMIT 50

#define SEMANTIC_REGISTER_NAME_SIZE 33
//#define SEMANTIC_REGISTER_VALUE_SIZE 33
#define SEMANTIC_REGISTER_TABLE_SIZE 5
//OLD

void Parser_Start();
void Parser_CleanBuffer(Token buffer[], size_t max);
bool Parser_IsExpression(Token buffer[], size_t max, size_t start, size_t end);
bool Parser_IsTerm(Token buffer[], size_t max, size_t start, size_t end);
bool Parser_IsFactor(Token buffer[], size_t max, size_t start, size_t end);

//PAS

/*
<objetivo> -> <programa> T_END ( Esta es la producción global que se agrega)

<programa> -> <listaSentencias>

<listaSentencias> -> <sentencia> {<sentencia>}

<sentencia> -> T_ID T_ASSIGN <expresión> T_END | T_PRINT T_L_PAR <expresion> T_R_PAR T_END

<expresion> -> <termino> | <termino> + <expresion>

<termino> -> <factor> | <factor> * <termino>

<factor> -> T_ID | T_CONSTANT | T_L_PAR <expresión> T_R_PAR

*/

enum PossibleSemanticRegisterTypes {
    RT_ID = 0,
    RT_CONSTANT
};

typedef enum PossibleSemanticRegisterTypes RegisterType;

struct SemanticRegisterStruct
{
    RegisterType type;
    char name[SEMANTIC_REGISTER_NAME_SIZE];
    //char value[SEMANTIC_REGISTER_VALUE_SIZE];
    int value;
};

typedef struct SemanticRegisterStruct SemanticRegister;

static bool SyntaxError = false;
static SemanticRegister SemanticTable[SEMANTIC_REGISTER_TABLE_SIZE];
static size_t SemanticTableTop = 0;

void Parser_Aux_Match(Token expectedToken);
void Parser_Aux_SyntaxError(Token expectedToken[], size_t expectedSize, Token foundToken);

void Parser_SAP_Target();
void Parser_SAP_Program();
void Parser_SAP_SentenceList();
void Parser_SAP_SingleSentence();
void Parser_SAP_Expression(SemanticRegister *result);
void Parser_SAP_Term(SemanticRegister *result);
void Parser_SAP_Factor(SemanticRegister *result);

int Parser_Sem_FindIDValue(char idName[]);
SemanticRegister Parser_Sem_GetID();
SemanticRegister Parser_Sem_GetConstant();
SemanticRegister Parser_Sem_EvaluateProd(SemanticRegister operand1, SemanticRegister operand2);
SemanticRegister Parser_Sem_EvaluateSum(SemanticRegister operand1, SemanticRegister operand2);
void Parser_Sem_Assign(SemanticRegister regID, SemanticRegister regConstant);
void Parser_Sem_CleanSemanticTable();