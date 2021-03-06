#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "Parser.h"
#include "Scanner.h"
#include "SemanticAnalyzer.h"

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
static bool SyntaxError = false;

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
    SemanticAnalyzer_CleanVariableTable(); //clean (?)

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

            SemanticRegister regID = SemanticAnalyzer_GetID();

            Parser_Aux_Match(T_ASSIGN);

            SemanticRegister regExp;
            Parser_SAP_Expression(&regExp);

            Parser_Aux_Match(T_END);

            //asignar regExp al regID y guardar en VariableTable
            SemanticAnalyzer_Assign(regID, regExp);
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

            SemanticAnalyzer_Print(regExp);

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

                *result = SemanticAnalyzer_EvaluateSum(*result, regExpr);
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

                *result = SemanticAnalyzer_EvaluateProd(*result, regTerm);
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
        (*result) = SemanticAnalyzer_GetID();
        return;
    }
    else if(currentToken == T_CONSTANT)
    {
        //#process_constant: devuelvo el valor expresado por la constante
        (*result) = SemanticAnalyzer_GetConstant();
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