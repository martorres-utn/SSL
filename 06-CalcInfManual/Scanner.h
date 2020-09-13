#pragma once

enum PossibleTokens {
    T_INITIAL = 0,
    T_ID,
    T_CONSTANT,
    T_OP_PLUS,
    T_OP_PROD,
    T_END
};

enum PossibleStates {
    S_EXPR = 0,
    S_ID,
    S_CONSTANT
};

typedef enum PossibleTokens Token;
typedef enum PossibleStates State;
typedef Token (*TokenReturningTransition)(int);

static State LastState = S_EXPR;
static Token RemainingToken = T_INITIAL;


Token FoundLexicalError();
Token FoundID();
Token FoundConstant();

static TokenReturningTransition TokenReturningMatrix[3][3] = {
    {
        &FoundLexicalError, //S_EXPR -> S_EXPR
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
};

Token Scanner_GetNextToken();