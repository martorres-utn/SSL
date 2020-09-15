#include <stdio.h>
#include <ctype.h>
#include "Scanner.h"

Token FoundLexicalError(int symbol)
{
    printf("[lexical error!]\n");
    LexicalError = true;
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
    while((newChar = getchar()) != EOF && newChar != '\n')
    {
        foundToken = T_INITIAL; //will containt a token if we find one

        if(!isspace(newChar))
        {
            if(isalpha(newChar))
            {
                nextState = S_ID;
            }
            else if(isdigit(newChar))
            {
                nextState = S_CONSTANT;
            }
            else if(newChar == '+')
            {
                nextState = S_EXPR;
                RemainingToken = T_OP_PLUS;
            }
            else if(newChar == '*')
            {
                nextState = S_EXPR;
                RemainingToken = T_OP_PROD;
            }
            else
            {
                nextState = S_EXPR;
                foundToken = FoundLexicalError(newChar);
            }

            if(!LexicalError)
            {
                //Check if there is a transition defined for: LastState -> nextState
                if(TokenReturningMatrix[LastState][nextState] != NULL)
                    foundToken = TokenReturningMatrix[LastState][nextState](newChar); //get the token from the transition
            }

            LastState = nextState;

            //return a new token only if we find one
            if(foundToken != T_INITIAL)
                return foundToken;
        }
    }

    //getchar() == EOF or \n
    ReachedEOF = newChar == EOF;

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
    
    LastState = S_EXPR; //return to initial state

    return foundToken;
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
    LexicalError = false; //clean flag
    RemainingToken = T_INITIAL; //clean remaining token
    while((newChar = getchar()) != EOF)
        if(newChar == '\n')
            return;
    ReachedEOF = true;
}