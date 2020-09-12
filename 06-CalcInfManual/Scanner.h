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

static Token LastState = T_INITIAL;

Token Scanner_GetNextToken();