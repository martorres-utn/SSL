#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "Parser2.h"
#include "Scanner2.h"

#define SEMANTIC_REGISTER_NAME_SIZE 33
#define SEMANTIC_REGISTER_VALUE_SIZE 33
#define SEMANTIC_REGISTER_TABLE_SIZE 10

/*
    Gramatica:

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
    RegisterType type; //TODO: no es necesario
    char name[SEMANTIC_REGISTER_NAME_SIZE];
    int value;
};

typedef struct SemanticRegisterStruct SemanticRegister;

static bool SyntaxError = false;
static SemanticRegister SemanticTable[SEMANTIC_REGISTER_TABLE_SIZE]; //TODO: VariableTable
static size_t SemanticTableTop = 0;

//Parser - Auxiliar Functions
void Parser_Aux_Match(Token expectedToken);
void Parser_Aux_SyntaxError(Token expectedToken[], size_t expectedSize, Token foundToken);


//Parser - Syntactic Analysis Procedures
void Parser_SAP_Program();
void Parser_SAP_SentenceList();
void Parser_SAP_SingleSentence();
void Parser_SAP_Expression(SemanticRegister *result);
void Parser_SAP_Term(SemanticRegister *result);
void Parser_SAP_Factor(SemanticRegister *result);

//Parser - Semantic building procedures
int Parser_Sem_FindIDValue(char idName[]);
SemanticRegister Parser_Sem_GetID();
SemanticRegister Parser_Sem_GetConstant();
SemanticRegister Parser_Sem_EvaluateProd(SemanticRegister operand1, SemanticRegister operand2);
SemanticRegister Parser_Sem_EvaluateSum(SemanticRegister operand1, SemanticRegister operand2);
void Parser_Sem_Assign(SemanticRegister regID, SemanticRegister regConstant);
void Parser_Sem_CleanSemanticTable();


//Parser - Implementations

void Parser_Aux_Match(Token expectedToken)
{
    Token currentToken = Scanner_GetNextToken();
    if(currentToken != expectedToken)
    {
        Token expectedTokens[1] = { expectedToken };
        Parser_Aux_SyntaxError(expectedTokens, 1, currentToken);
    }
}

void Parser_Aux_SyntaxError(Token expectedTokens[], size_t expectedSize, Token foundToken)
{
    SyntaxError = true;
    printf("[syntax error! - expected one of the following:");
    for(size_t pos = 0; pos < expectedSize; pos++)
    {
        printf("t[%d]", expectedTokens[pos]);
    }
    printf(" but current:t[%d] ]", foundToken);
}

void Parser_SAP_Target() 
{
    Parser_Sem_CleanSemanticTable(); //clean (?)

    Parser_SAP_Program();
    Parser_Aux_Match(T_END);
}

void Parser_SAP_Program()
{
    Parser_SAP_SentenceList();
}

void Parser_SAP_SentenceList()
{
    Parser_SAP_SingleSentence(); /* la primera de la lista de sentencias */
    while (!SyntaxError) { /* un ciclo indefinido */
        Token currentToken = Scanner_GetNextToken();
        switch (currentToken) {
            case T_ID: case T_PRINT: /* detectó token correcto */
            {
                Scanner_UngetLastToken(); //devuelvo T_ID o T_PRINT
                Parser_SAP_SingleSentence(); /* procesa la secuencia opcional */
                break;
            }
            default:
            {
                return;
            }
        } /* fin switch */
    }
}

void Parser_SAP_SingleSentence()
{
    Token token = Scanner_GetNextToken();
    switch (token) {
        case T_ID: /* <sentencia> -> ID = <expresion> */
        {
            Scanner_UngetLastToken(); //devolver token ID leido
            
            Parser_Aux_Match(T_ID); 

            SemanticRegister regID = Parser_Sem_GetID();

            Parser_Aux_Match(T_ASSIGN);

            SemanticRegister regExp;
            Parser_SAP_Expression(&regExp);

            Parser_Aux_Match(T_END);

            //asignar regExp al regID y guardar en SemanticTable
            Parser_Sem_Assign(regID, regExp);
            break;
        }
        case T_PRINT: /* <sentencia> -> $(<expresion>) */
        {
            Scanner_UngetLastToken(); //devolver token ID leido

            Parser_Aux_Match(T_PRINT);
            Parser_Aux_Match(T_L_PAR);
            
            SemanticRegister regExp;

            Parser_SAP_Expression(&regExp);

            Parser_Aux_Match(T_R_PAR);
            Parser_Aux_Match(T_END);

            printf("$:%d\n", regExp.value);

            break;
        }
        default:
        {
            Token expectedTokens[2] = { T_ID, T_PRINT };
            Parser_Aux_SyntaxError(expectedTokens, 2, token);
            break;
        }
    }
}

void Parser_SAP_Expression(SemanticRegister *result) 
{
    Parser_SAP_Term(result); //single <term>
    
    while (!SyntaxError) //undefined cycle of + <term>
    {
        Token currentToken = Scanner_GetNextToken();
        switch (currentToken) {
            case T_OP_PLUS:
            {
                SemanticRegister regExpr;
                Parser_SAP_Expression(&regExpr);

                *result = Parser_Sem_EvaluateSum(*result, regExpr);
                break;
            }
            default:
            {
                Scanner_UngetLastToken(); //devolver token ID leido
                return;
            }
        }
    }
}

void Parser_SAP_Term(SemanticRegister *result) 
{

    Parser_SAP_Factor(result); //single expression
    
    while (!SyntaxError) //undefined cycle of * <factor>
    {
        Token currentToken = Scanner_GetNextToken();
        switch (currentToken) {
            case T_OP_PROD:
            {
                SemanticRegister regTerm;
                Parser_SAP_Term(&regTerm);

                *result = Parser_Sem_EvaluateProd(*result, regTerm);
                break;
            }
            default:
            {
                Scanner_UngetLastToken(); //devolver token ID leido
                return;
            }
        }
    }
}

void Parser_SAP_Factor(SemanticRegister *result)
{
    Token currentToken = Scanner_GetNextToken();

    if(currentToken == T_ID)
    {
        //#process_id: devuelvo el valor que contiene el ID
        (*result) = Parser_Sem_GetID();
        return;
    }
    else if(currentToken == T_CONSTANT)
    {
        //#process_constant: devuelvo el valor expresado por la constante
        (*result) = Parser_Sem_GetConstant();
        return;
    }
    else if(currentToken == T_L_PAR)
    {
        Scanner_UngetLastToken(); //devolver token ID leido
        Parser_Aux_Match(T_L_PAR);
        Parser_SAP_Expression(result);
        Parser_Aux_Match(T_R_PAR);
        
        return;
    }
    else
    {
        Token expectedTokens[3] = { T_ID, T_CONSTANT, T_L_PAR };
        Parser_Aux_SyntaxError(expectedTokens, 3, currentToken);
        return;
    }
}

int Parser_Sem_FindValue(char name[])
{
    for(size_t pos = 0; pos < SEMANTIC_REGISTER_TABLE_SIZE; pos++)
        if(strcmp(name, SemanticTable[pos].name) == 0)
            return SemanticTable[pos].value;
    return -1; //uninitialized (?) //TODO debería devolver algo dentro del universo
}

SemanticRegister Parser_Sem_GetID() 
{
    SemanticRegister sr;
    sr.type = RT_ID;
    Scanner_BufferGetContent(sr.name);
    sr.value = Parser_Sem_FindValue(sr.name);
    return sr;
}

SemanticRegister Parser_Sem_GetConstant()
{
    SemanticRegister sr;
    sr.type = RT_CONSTANT;
    strcpy(sr.name, "[constant]");
    char stringValue[SEMANTIC_REGISTER_VALUE_SIZE] = "";
    Scanner_BufferGetContent(stringValue);
    sscanf(stringValue, "%d", &sr.value);
    return sr;
}

SemanticRegister Parser_Sem_EvaluateProd(SemanticRegister operand1, SemanticRegister operand2) 
{
    SemanticRegister result;
    result.type = RT_CONSTANT;
    result.value = operand1.value * operand2.value;
    return result;
}

SemanticRegister Parser_Sem_EvaluateSum(SemanticRegister operand1, SemanticRegister operand2) 
{
    SemanticRegister result;
    result.type = RT_CONSTANT;
    result.value = operand1.value + operand2.value;
    return result;
}

void Parser_Sem_Assign(SemanticRegister regID, SemanticRegister regConstant)
{
    size_t pos;
    size_t max = SEMANTIC_REGISTER_TABLE_SIZE;
    for(size_t pos = 0; pos < max; pos++)
    {
        if(strcmp(regID.name, SemanticTable[pos].name) == 0)
        {
            SemanticTable[pos].value = regConstant.value;
            return;
        }
    }

    SemanticRegister newReg = { .type = (RegisterType)regID.type, .value = (int)regConstant.value };
    strcpy(newReg.name, regID.name);

    SemanticTable[SemanticTableTop++] = newReg;
}

void Parser_Sem_CleanSemanticTable()
{
    size_t pos;
    size_t max = SEMANTIC_REGISTER_TABLE_SIZE;
    for(size_t pos = 0; pos < max; pos++)
    {
        SemanticTable[pos].type = RT_ID;
        strcpy(SemanticTable[pos].name, "");
        SemanticTable[pos].value = 0;
    }
    SemanticTableTop = 0;
}