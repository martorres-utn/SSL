#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "Scanner2.h"

Token Scanner_GetNextToken()
{
    Scanner_BufferClear(); //(?)

    int newChar = EOF;

    //get char from input stream
    while((newChar = getchar()) != EOF && newChar != '\n')
    {
        if(!isspace(newChar))
        {
            if(isalpha(newChar))
            {
                //token id [a-zA-Z]*

                Scanner_BufferPush(newChar);

				int accepted = 0;
				while( (newChar = getchar()) != EOF && (accepted = isalpha(newChar)) ) {
                    Scanner_BufferPush(newChar);
                }

				if(!accepted)
					ungetc(newChar, stdin);

				return (LastToken = T_ID);
            }
            else if(isdigit(newChar))
            {
                //token const [0-9]*
                
                Scanner_BufferPush(newChar);

				int accepted = 0;
				while( (newChar = getchar()) != EOF && (accepted = isdigit(newChar)) ) {
                    Scanner_BufferPush(newChar);
                }

				if(!accepted)
					ungetc(newChar, stdin);

				return (LastToken = T_CONSTANT);
            }
            else if(newChar == '+')
            {
                Scanner_BufferPush(newChar);

                return (LastToken = T_OP_PLUS);
            }
            else if(newChar == '*')
            {
                Scanner_BufferPush(newChar);

                return (LastToken = T_OP_PROD);
            }
            else if(newChar == '(')
            {
                Scanner_BufferPush(newChar);

                return (LastToken = T_L_PAR);
            }
            else if(newChar == ')')
            {
                Scanner_BufferPush(newChar);

                return (LastToken = T_R_PAR);
            }
            else if (newChar == '=')
            {
                Scanner_BufferPush(newChar);

                return (LastToken = T_ASSIGN);
            }
            else if (newChar == '$')
            {
                Scanner_BufferPush(newChar);

                return (LastToken = T_PRINT);
            }
            else
            {
                printf("[lexical error!]\n");
                LexicalError = true;
                return (LastToken = T_END);
            }
        }
    }
    
    Scanner_BufferPush(newChar);

    //getchar() == EOF or \n
    ReachedEOF = newChar == EOF;
    return (LastToken = T_END);
}

void Scanner_BufferPush(int symbol)
{
    Buffer[BufferTop++] = symbol;
    Buffer[BufferTop] = '\0';
}

int Scanner_BufferPop()
{
    int symbol = Buffer[--BufferTop];
    Buffer[BufferTop] = '\0';
    return symbol;
}

void Scanner_BufferClear()
{
    for(size_t pos = 0; pos < BUFFER_SIZE; pos++)
        Buffer[pos] = '\0';
    BufferTop = 0;
}

void Scanner_BufferGetContent(char output[])
{
    strcpy(output, Buffer);
}

Token Scanner_GetLastToken()
{
    return LastToken;
}

void Scanner_UngetLastToken()
{
    while(BufferTop > 0)
        ungetc(Scanner_BufferPop(), stdin);
    LastToken = T_INITIAL;
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