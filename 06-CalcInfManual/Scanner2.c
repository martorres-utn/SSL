#include <stdio.h>
#include <ctype.h>
#include "Scanner2.h"

/*Token FoundLexicalError(int symbol)
{
    printf("[lexical error!]\n");
    LexicalError = true;
    return T_END;
}

Token FoundID(int symbol)
{
    ungetc(symbol, stdin);
    return T_ID;
}

Token FoundConstant(int symbol)
{
    ungetc(symbol, stdin);
    return T_CONSTANT;
}*/

//S_EXPR -> S_EXPR Do I wan't to return ++a or +a or + as Lexical Errors? I can detect those kind of strings at this level
/*Token FoundOperatorOrLexicalError(int symbol)
{
    if(LastToken == T_CONSTANT || LastToken == T_ID || LastToken == T_INITIAL)
    {
        if(symbol == '+')
            return T_OP_PLUS;
        else if(symbol == '*')
            return T_OP_PROD;
        else
            return FoundLexicalError(symbol); //this shouldn't be possible
    }
    return FoundLexicalError(symbol);
}*/

Token Scanner_GetNextToken()
{
    int newChar = EOF;
    //State nextState = S_EXPR; //[OLD]
    //Token foundToken = T_INITIAL; //[OLD]
    
    //get char from input stream
    while((newChar = getchar()) != EOF && newChar != '\n')
    {
        //foundToken = T_INITIAL; //will containt a token if we find one //[OLD]

        if(!isspace(newChar))
        {
            if(isalpha(newChar))
            {
                //nextState = S_ID; //[OLD]

                //token id [a-zA-Z]*
				int accepted = 0;
				while( (newChar = getchar()) != EOF && (accepted = isalpha(newChar)) ) {}
				if(!accepted)
					ungetc(newChar, stdin);
				return T_ID;
            }
            else if(isdigit(newChar))
            {
                //nextState = S_CONSTANT; //[OLD]

                //token const [0-9]*
				int accepted = 0;
				while( (newChar = getchar()) != EOF && (accepted = isdigit(newChar)) ) {}
				if(!accepted)
					ungetc(newChar, stdin);
				return T_CONSTANT;
            }
            else if(newChar == '+')
            {
                //nextState = S_EXPR; [OLD]
                return T_OP_PLUS;
            }
            else if(newChar == '*')
            {
                //nextState = S_EXPR; //[OLD]
                return T_OP_PROD;
            }
            else if(newChar == '(')
            {
                return T_L_PAR;
            }
            else if(newChar == ')')
            {
                return T_R_PAR;
            }
            else
            {
                //nextState = S_EXPR; //[OLD]
                //foundToken = FoundLexicalError(newChar); [OLD]
                printf("[lexical error!]\n");
                LexicalError = true;
                return T_END;
            }

            /*if(!LexicalError)
            {
                //Check if there is a transition defined for: LastState -> nextState
                if(TokenReturningMatrix[LastState][nextState] != NULL)
                    foundToken = TokenReturningMatrix[LastState][nextState](newChar); //get the token from the transition
            }*/ //[OLD]

            //LastState = nextState; //[OLD]

            //return a new token only if we find one
            /*if(foundToken != T_INITIAL)
            {
                LastToken = foundToken;
                return foundToken;
            }*///[OLD]
        }
    }

    //getchar() == EOF or \n
    ReachedEOF = newChar == EOF;

    //once we reach the end we need to return the corresponding token according to the previous state

    /*switch(LastState)
    {
        case S_EXPR:
        {
            foundToken = T_END;
            break;
        }
        case S_ID:
        {
            foundToken = T_ID;
            if(newChar == '\n')
                ungetc(newChar, stdin);
            break;
        }
        case S_CONSTANT:
        {
            foundToken = T_CONSTANT;
            if(newChar == '\n')
                ungetc(newChar, stdin);
            break;
        }
    }*/ //[OLD]
    
    //LastState = S_EXPR; //return to initial state //[OLD]
    //LastToken = foundToken;//[OLD]
    //return foundToken;//[OLD]

    return T_END;
}

bool Scanner_HasReachedEOF()
{
    return ReachedEOF;
}

bool Scanner_HasFoundLexicalError()
{
    return LexicalError;
}

void Scanner_MoveToNextExpression()
{
    int newChar;
    
    while((newChar = getchar()) != EOF)
        if(newChar == '\n')
            return;
    ReachedEOF = true;
}

void Scanner_ResetInternalState()
{
    LexicalError = false; //clean flag
    //LastToken = T_INITIAL;
    //LastState = S_EXPR;
}