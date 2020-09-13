#include <stdio.h>
#include "Scanner.h"

Token FoundLexicalError(int symbol)
{
    printf("[!LEXICAL_ERROR!]\n");
    return T_END;
}

Token FoundID(int symbol)
{
    return T_ID;
}

Token FoundConstant(int symbol)
{
    return T_CONSTANT;
}

Token Scanner_GetNextToken()
{
    int newChar = EOF;
    State nextState = S_EXPR;
    Token foundToken = T_INITIAL;
    
    // check if there is a remaining token from a previous call like operators: +, *
    if(RemainingToken != T_INITIAL)
    {
        foundToken = RemainingToken;
        RemainingToken = T_INITIAL;
        return foundToken;
    }
    
    //get char from input stream
    while((newChar = getchar()) != EOF)
    {
        foundToken = T_INITIAL; //will containt a token if we find one

        switch(newChar)
        {
            //[a-z]
            case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g': case 'h': case 'i': case 'j': case 'k': case 'l': case 'm': case 'n': case 'o': case 'p': case 'q': case 'r': case 's': case 't': case 'u': case 'v': case 'w': case 'x': case 'y': case 'z':
            {
                nextState = S_ID;
                break;
            }
            //[0-9]
            case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
            {
                nextState = S_CONSTANT;
                break;
            }
            case '+':
            {
                nextState = S_EXPR;
                RemainingToken = T_OP_PLUS;
                break;
            }
            case '*':
            {
                nextState = S_EXPR;
                RemainingToken = T_OP_PROD;
                break;
            }
            default:
            {
                printf("[!LEXICAL_ERROR!]\n");
                foundToken = T_END;
            }
        }
        
        //Check if there is a transition defined for: LastState -> nextState
        if(TokenReturningMatrix[LastState][nextState] != NULL)
            foundToken = TokenReturningMatrix[LastState][nextState](newChar); //get the token from the transition

        LastState = nextState;

        //return a new token only if we find one
        if(foundToken != T_INITIAL)
            return foundToken;
    }

    //getchar() == EOF
    
    //once we reach the end we need to return the corresponding token according to the previous state

    switch(LastState)
    {
        case S_EXPR:
        {
            foundToken = T_END;
            break;
        }
        case S_ID:
        {
            foundToken = T_ID;
            RemainingToken = T_END;
            break;
        }
        case S_CONSTANT:
        {
            foundToken = T_CONSTANT;
            RemainingToken = T_END;
            break;
        }
    }

    return foundToken;
}