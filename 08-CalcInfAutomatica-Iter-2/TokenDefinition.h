#pragma once

#define YYTOKENTYPE 1

enum yytokentype
{
    TK_END_PROGRAM = 0,
    TK_ID = 1,
    TK_CONSTANT = 2,
    TK_OP_PLUS = 3,
    TK_OP_PROD = 4,
    TK_L_PAR = 5,
    TK_R_PAR = 6,
    TK_ASSIGN = 7,
    TK_PRINT = 8,
    TK_END_STATEMENT = 9
};

typedef enum yytokentype Token;