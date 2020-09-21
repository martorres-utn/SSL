#pragma once

#include <stdio.h>
#include <stdbool.h>
#include "Scanner2.h"

#define TOKEN_BUFFER_SIZE 1000
#define PARSER_LOOP_LIMIT 50

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
static bool SyntaxError = false;

void Parser_Aux_Match(Token expectedToken);
void Parser_Aux_SyntaxError(Token expectedToken[], size_t expectedSize, Token foundToken);
void Parser_SAP_Target();
void Parser_SAP_Program();
void Parser_SAP_SentenceList();
void Parser_SAP_SingleSentence();
void Parser_SAP_Expression();
void Parser_SAP_Term();
void Parser_SAP_Factor();