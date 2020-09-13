#include <stdio.h>
#include "Scanner.h"

Token Scanner_GetNextToken()
{
    int newChar = EOF;
    State nextState = S_EXPR;
    Token foundToken = T_INITIAL;
    
    if(RemainingToken != T_INITIAL)
    {
        foundToken = RemainingToken;
        RemainingToken = T_INITIAL;
    }

    if(foundToken != T_INITIAL)
        return foundToken;

    while((newChar = getchar()) != EOF)
    {
        foundToken = T_INITIAL;

        switch(newChar)
        {
            case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g': case 'h': case 'i': case 'j': case 'k': case 'l': case 'm': case 'n': case 'o': case 'p': case 'q': case 'r': case 's': case 't': case 'u': case 'v': case 'w': case 'x': case 'y': case 'z':
            {
                nextState = S_ID;
                
                switch(LastState)
                {
                    case S_EXPR:
                    {
                        break;
                    }
                    case S_ID:
                    {
                        break;
                    }
                    case S_CONSTANT:
                    {
                        printf("[!LEXICAL_ERROR!]\n");
                        foundToken = T_END;
                        break;
                    }
                }
                break;
            }
            case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
            {
                nextState = S_CONSTANT;

                switch(LastState)
                {
                    case S_EXPR:
                    {
                        break;
                    }
                    case S_ID:
                    {
                        printf("[!LEXICAL_ERROR!]\n");
                        foundToken = T_END;
                        break;
                    }
                    case S_CONSTANT:
                    {
                        break;
                    }
                }

                break;
            }
            case '+':
            {
                nextState = S_EXPR;

                switch(LastState)
                {
                    case S_EXPR:
                    {
                        printf("[!LEXICAL_ERROR!]\n");
                        foundToken = T_END;
                        break;
                    }
                    case S_ID:
                    {
                        foundToken = T_ID;
                        break;
                    }
                    case S_CONSTANT:
                    {
                        foundToken = T_CONSTANT;
                        break;
                    }
                }
                
                RemainingToken = T_OP_PLUS;

                break;
            }
            case '*':
            {
                nextState = S_EXPR;

                switch(LastState)
                {
                    case S_EXPR:
                    {
                        printf("[!LEXICAL_ERROR!]\n");
                        foundToken = T_END;
                        break;
                    }
                    case S_ID:
                    {
                        foundToken = T_ID;
                        break;
                    }
                    case S_CONSTANT:
                    {
                        foundToken = T_CONSTANT;
                        break;
                    }
                }
                
                RemainingToken = T_OP_PROD;
                
                break;
            }
            default:
            {
                printf("[!LEXICAL_ERROR!]\n");
                foundToken = T_END;
            }
        }
        
        LastState = nextState;

        if(foundToken != T_INITIAL)
            return foundToken;
    }

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
            break;
        }
        case S_CONSTANT:
        {
            foundToken = T_CONSTANT;
            break;
        }
    }

    RemainingToken = T_END;

    return foundToken;
}