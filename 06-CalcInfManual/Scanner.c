#include <stdio.h>
#include "Scanner.h"

Token Scanner_GetNextToken()
{
    int newChar = EOF;
    Token nextState = T_INITIAL;
    Token foundToken = T_INITIAL;

    while((newChar = getchar()) != EOF)
    {
        foundToken = T_INITIAL;

        switch(newChar)
        {
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
            case 'g':
            case 'h':
            case 'i':
            case 'j':
            case 'k':
            case 'l':
            case 'm':
            case 'n':
            case 'o':
            case 'p':
            case 'q':
            case 'r':
            case 's':
            case 't':
            {
                nextState = T_ID;
                
                switch(LastState)
                {
                    case T_INITIAL:
                    {
                        break;
                    }
                    case T_ID:
                    {
                        break;
                    }
                    case T_CONSTANT:
                    {
                        printf("[!LEXICAL_ERROR!]\n");
                        return T_END;
                        break;
                    }
                    case T_OP_PLUS:
                    {
                        //ungetc(newChar, stdin);
                        foundToken =  T_OP_PLUS;
                        break;
                    }
                    case T_OP_PROD:
                    {
                        //ungetc(newChar, stdin);
                        foundToken =  T_OP_PROD;
                        break;
                    }
                    default:
                    {
                        printf("[!LEXICAL_ERROR!]\n");
                        return T_END;
                        break;
                    }
                }
                break;
            }
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            {
                nextState = T_CONSTANT;

                switch(LastState)
                {
                    case T_INITIAL:
                    {
                        break;
                    }
                    case T_ID:
                    {
                        printf("[!LEXICAL_ERROR!]\n");
                        return T_END;
                        break;
                    }
                    case T_CONSTANT:
                    {
                        break;
                    }
                    case T_OP_PLUS:
                    {
                        //ungetc(newChar, stdin);
                        foundToken = T_OP_PLUS;
                        break;
                    }
                    case T_OP_PROD:
                    {
                        //ungetc(newChar, stdin);
                        foundToken = T_OP_PROD;
                        break;
                    }
                    default:
                    {
                        printf("[!LEXICAL_ERROR!]\n");
                        return T_END;
                        break;
                    }
                }
                break;
            }
            case '+':
            {
                nextState = T_OP_PLUS;

                switch(LastState)
                {
                    case T_INITIAL:
                    {
                        printf("[!LEXICAL_ERROR!]\n");
                        return T_END;
                        break;
                    }
                    case T_ID:
                    {
                        //ungetc(newChar, stdin);
                        foundToken = T_ID;
                        break;
                    }
                    case T_CONSTANT:
                    {
                        //ungetc(newChar, stdin);
                        foundToken = T_CONSTANT;
                        break;
                    }
                    case T_OP_PLUS:
                    {
                        printf("[!LEXICAL_ERROR!]\n");
                        return T_END;
                        break;
                    }
                    case T_OP_PROD:
                    {
                        printf("[!LEXICAL_ERROR!]\n");
                        return T_END;
                        break;
                    }
                    default:
                    {
                        printf("[!LEXICAL_ERROR!]\n");
                        return T_END;
                        break;
                    }
                }
                break;
            }
            case '*':
            {
                nextState = T_OP_PROD;

                switch(LastState)
                {
                    case T_INITIAL:
                    {
                        printf("[!LEXICAL_ERROR!]\n");
                        return T_END;
                        break;
                    }
                    case T_ID:
                    {
                        //ungetc(newChar, stdin);
                        foundToken = T_ID;
                        break;
                    }
                    case T_CONSTANT:
                    {
                        //ungetc(newChar, stdin);
                        foundToken = T_CONSTANT;
                        break;
                    }
                    case T_OP_PLUS:
                    {
                        printf("[!LEXICAL_ERROR!]\n");
                        return T_END;
                        break;
                    }
                    case T_OP_PROD:
                    {
                        printf("[!LEXICAL_ERROR!]\n");
                        return T_END;
                        break;
                    }
                    default:
                    {
                        printf("[!LEXICAL_ERROR!]\n");
                        return T_END;
                        break;
                    }
                }
                break;
            }
            default:
            {
                printf("[!LEXICAL_ERROR!]\n");
                return T_END; //lexical error
            }
        }
        
        LastState = nextState;

        if(foundToken != T_INITIAL)
            return foundToken;
    }

    nextState = T_END;

    switch(LastState)
    {
        case T_INITIAL:
        {
            break;
        }
        case T_ID:
        {
            //ungetc(newChar, stdin);
            foundToken = T_ID;
            break;
        }
        case T_CONSTANT:
        {
            //ungetc(newChar, stdin);
            foundToken = T_CONSTANT;
            break;
        }
        case T_OP_PLUS:
        {
            printf("[!LEXICAL_ERROR!]\n");
            return T_END;
            break;
        }
        case T_OP_PROD:
        {
            printf("[!LEXICAL_ERROR!]\n");
            return T_END;
            break;
        }
        case T_END:
        {
            foundToken = T_END;
            break;
        }
        default:
        {
            printf("[!LEXICAL_ERROR!]\n");
            return T_END;
            break;
        }
    }
    
    LastState = nextState;

    return foundToken;
}