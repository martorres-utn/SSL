#pragma once

#include <stdio.h>
#include <stdbool.h>

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

//Scanner - Public functions
Token Scanner_GetNextToken();
void Scanner_UngetLastToken();
void Scanner_BufferGetContent(char output[]);
bool Scanner_HasReachedEOF();
bool Scanner_HasFoundLexicalError();
void Scanner_MoveToNextExpression();
void Scanner_ResetInternalState();