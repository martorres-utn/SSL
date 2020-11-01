#pragma once

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