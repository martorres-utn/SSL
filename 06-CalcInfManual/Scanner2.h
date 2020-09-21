#pragma once

#include <stdio.h>
#include <stdbool.h>

#define BUFFER_SIZE 33

enum PossibleTokens {
    T_INITIAL = 0,
    T_ID,
    T_CONSTANT,
    T_OP_PLUS,
    T_OP_PROD,
    T_L_PAR,                // (
    T_R_PAR,                // )
    T_ASSIGN,               // = , a = 3
    T_PRINT,                // $(<expression>) // print keyword
    T_END
};

typedef enum PossibleTokens Token;

static bool ReachedEOF = false;
static bool LexicalError = false;
static Token LastToken = T_INITIAL;
static char Buffer[BUFFER_SIZE]; // 32 characters + 1 '\0' 
static size_t BufferTop = 0;

Token Scanner_GetNextToken();
Token Scanner_GetLastToken();
void Scanner_UngetLastToken();

void Scanner_BufferPush(int symbol);
int Scanner_BufferPop();
void Scanner_BufferClear();
void Scanner_BufferGetContent(char output[]);

bool Scanner_HasReachedEOF();
bool Scanner_HasFoundLexicalError();
void Scanner_MoveToNextExpression();
void Scanner_ResetInternalState();