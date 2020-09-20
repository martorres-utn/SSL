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
    T_PRINT,                // print(<expression>) // print keyword
    T_END
};

/*enum PossibleStates {
    S_EXPR = 0,
    S_ID,
    S_CONSTANT
};*/

typedef enum PossibleTokens Token;
//typedef enum PossibleStates State;
//typedef Token (*TokenReturningTransition)(int);

//static State LastState = S_EXPR;
//static Token LastToken = T_INITIAL;
static bool ReachedEOF = false;
static bool LexicalError = false;

/*Token FoundLexicalError();
Token FoundID();
Token FoundConstant();
Token FoundOperatorOrLexicalError();*/

/*static TokenReturningTransition TokenReturningMatrix[3][3] = {
    {
        &FoundOperatorOrLexicalError, //S_EXPR -> S_EXPR
        NULL,               //S_EXPR -> S_ID
        NULL                //S_EXPR -> S_CONSTANT
    },
    {
        &FoundID,           //S_ID -> S_EXPR
        NULL,               //S_ID -> S_ID
        &FoundLexicalError  //S_ID -> S_CONSTANT
    },
    {
        &FoundConstant,         //S_CONSTANT -> S_EXPR
        &FoundLexicalError,     //S_CONSTANT -> S_ID
        NULL                    //S_CONSTANT -> S_CONSTANT
    }
};*/

Token Scanner_GetNextToken();
bool Scanner_HasReachedEOF();
bool Scanner_HasFoundLexicalError();
void Scanner_MoveToNextExpression();
void Scanner_ResetInternalState();