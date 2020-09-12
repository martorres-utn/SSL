#pragma once

enum PossibleTokens {
    T_INITIAL = 0,
    T_ID,
    T_CONSTANT,
    T_OP_PLUS,
    T_OP_PROD,
    T_END
};

/*enum PossibleStates {
    S_INITIAL = 0,
    S_ID,
    S_CONSTANT,
    S_OP_PLUS,
    S_OP_PROD,
    S_END
};*/

typedef enum PossibleTokens Token;
/*typedef enum PossibleStates State;*/

static Token CurrentState = T_INITIAL;

Token Scanner_GetNextToken();