#include <stdio.h>
#include "Scanner.h"

Token Scanner_GetNextToken()
{
    int newChar = EOF;
    while((newChar = getchar()) != EOF)
    {
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
                switch(CurrentState)
                {
                    case T_INITIAL:
                        CurrentState = T_ID;
                        break;
                    case T_ID:
                        CurrentState = T_ID;
                        break;
                    /*case T_CONSTANT:
                    {
                        ungetc(newChar, stdin);
                        return T_CONSTANT;
                        break;
                    }*/
                    case T_OP_PLUS:
                    {
                        ungetc(newChar, stdin);
                        return T_OP_PLUS;
                        break;
                    }
                    case T_OP_PROD:
                    {
                        ungetc(newChar, stdin);
                        return T_OP_PROD;
                        break;
                    }
                    default:
                    {
                        printf("[!LEXICAL_ERROR!]");
                        return T_END; //lexical error
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
                switch(CurrentState)
                {
                    case T_INITIAL:
                        CurrentState = T_CONSTANT;
                        break;
                    /*case T_ID:
                    {
                        ungetc(newChar, stdin);    
                        return T_ID;
                        break;
                    }*/
                    case T_CONSTANT: //there was a constant token before
                        CurrentState = T_CONSTANT;
                        break;
                    case T_OP_PLUS:
                    {
                        ungetc(newChar, stdin);
                        return T_OP_PLUS;
                        break;
                    }
                    case T_OP_PROD:
                    {
                        ungetc(newChar, stdin);
                        return T_OP_PROD;
                        break;
                    }
                    default:
                    {
                        printf("[!LEXICAL_ERROR!]");
                        return T_END; //lexical error
                    }
                }
                break;
            }
            case '+':
            {
                switch(CurrentState)
                {
                    case T_INITIAL:
                    {
                        CurrentState = T_OP_PLUS;
                        break;
                    }
                    case T_ID:
                    {
                        ungetc(newChar, stdin);
                        CurrentState = T_OP_PLUS;
                        return T_ID;
                        break;
                    }
                    case T_CONSTANT:
                    {
                        ungetc(newChar, stdin);
                        CurrentState = T_OP_PLUS;
                        return T_CONSTANT;
                        break;
                    }
                    /*case T_OP_PLUS:
                        CurrentState = T_OP_PLUS;
                        break;*/
                    case T_OP_PROD:
                    {
                        ungetc(newChar, stdin);
                        CurrentState = T_OP_PLUS;
                        return T_OP_PROD;
                        break;
                    }
                    default:
                    {
                        printf("[!LEXICAL_ERROR!]");
                        return T_END; //lexical error
                    }
                }

                CurrentState = T_OP_PLUS;

                break;
            }
            case '*':
            {
                switch(CurrentState)
                {
                    /*case T_INITIAL:
                        CurrentState = T_OP_PROD;
                        break;*/
                    case T_ID:
                    {
                        ungetc(newChar, stdin);
                        return T_ID;
                        break;
                    }
                    case T_CONSTANT:
                    {
                        ungetc(newChar, stdin);
                        return T_CONSTANT;
                        break;
                    }
                    /*case T_OP_PLUS:
                    {
                        ungetc(newChar, stdin);
                        return T_OP_PLUS;
                        break;
                    }*/
                    /*case T_OP_PROD:
                        CurrentState = T_OP_PROD;
                        break;*/
                    default:
                    {
                        printf("[!LEXICAL_ERROR!]");
                        return T_END; //lexical error
                    }
                }
                break;
            }
            default:
            {
                printf("[!LEXICAL_ERROR!]");
                return T_END; //lexical error
            }
        }
    }

    switch(CurrentState)
    {
        case T_INITIAL:
        {
            return T_END;
            break;
        }
        case T_ID:
        {
            ungetc(newChar, stdin);
            CurrentState = T_END;
            return T_ID;
            break;
        }
        case T_CONSTANT:
        {
            ungetc(newChar, stdin);
            CurrentState = T_END;
            return T_CONSTANT;
            break;
        }
        case T_OP_PLUS:
        {
            ungetc(newChar, stdin);
            CurrentState = T_END;
            return T_OP_PLUS;
            break;
        }
        case T_OP_PROD:
        {
            ungetc(newChar, stdin);
            CurrentState = T_END;
            return T_OP_PROD;
            break;
        }
        case T_END:
        {
            return T_END;
            break;
        }
        default:
        {
            printf("[!LEXICAL_ERROR!]");
            return T_END; //lexical error
            break;
        }
    }

    return T_END;
}