#include <stdio.h>
#include <ctype.h>
#include "Scanner2.h"

Token Scanner_GetNextToken()
{
    int newChar = EOF;

    //get char from input stream
    while((newChar = getchar()) != EOF && newChar != '\n')
    {
        if(!isspace(newChar))
        {
            if(isalpha(newChar))
            {
                //token id [a-zA-Z]*
				int accepted = 0;
				while( (newChar = getchar()) != EOF && (accepted = isalpha(newChar)) ) {}
				if(!accepted)
					ungetc(newChar, stdin);
				return T_ID;
            }
            else if(isdigit(newChar))
            {
                //token const [0-9]*
				int accepted = 0;
				while( (newChar = getchar()) != EOF && (accepted = isdigit(newChar)) ) {}
				if(!accepted)
					ungetc(newChar, stdin);
				return T_CONSTANT;
            }
            else if(newChar == '+')
            {
                return T_OP_PLUS;
            }
            else if(newChar == '*')
            {
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
                printf("[lexical error!]\n");
                LexicalError = true;
                return T_END;
            }
        }
    }
    //getchar() == EOF or \n
    ReachedEOF = newChar == EOF;
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
}