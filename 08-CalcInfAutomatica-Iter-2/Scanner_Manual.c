#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "Scanner.h"
#include "TokenDefinition.h"
#include "SemanticValue.h"

#define BUFFER_SIZE 33
#define UNINITIALIZED_TOKEN -1

//Scanner - private global variables
static bool ReachedEOF = false;
static bool LexicalError = false;
static Token LastToken = UNINITIALIZED_TOKEN;
static char Buffer[BUFFER_SIZE]; // 32 characters + 1 '\0' 
static size_t BufferTop = 0;

//Scanner - private functions
static void Scanner_BufferPush(int symbol);
static int Scanner_BufferPop();
static void Scanner_BufferClear();

//Scanner - Implementations
int Scanner_GetNextToken()
{
    Scanner_BufferClear(); //(?)

    int newChar = EOF;

    //get char from input stream
    while((newChar = getchar()) != EOF)
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

                SemanticValue_SetString(Buffer);

				return (LastToken = TK_ID);
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
                
                SemanticValue_SetInteger(Buffer);

				return (LastToken = TK_CONSTANT);
            }
            else if(newChar == '+')
            {
                Scanner_BufferPush(newChar);

                return (LastToken = TK_OP_PLUS);
            }
            else if(newChar == '*')
            {
                Scanner_BufferPush(newChar);

                return (LastToken = TK_OP_PROD);
            }
            else if(newChar == '(')
            {
                Scanner_BufferPush(newChar);

                return (LastToken = TK_L_PAR);
            }
            else if(newChar == ')')
            {
                Scanner_BufferPush(newChar);

                return (LastToken = TK_R_PAR);
            }
            else if (newChar == '=')
            {
                Scanner_BufferPush(newChar);

                return (LastToken = TK_ASSIGN);
            }
            else if (newChar == '$')
            {
                Scanner_BufferPush(newChar);

                return (LastToken = TK_PRINT);
            }
            else
            {
                printf("[lexical error!]\n");
                LexicalError = true;
                return (LastToken = TK_END_STATEMENT);
            }
        }
        else if(newChar == '\n')
        {
            Scanner_BufferPush(newChar);
            return (LastToken = TK_END_STATEMENT);
        }
    }
    
    Scanner_BufferPush(newChar);

    //getchar() == EOF or \n
    ReachedEOF = newChar == EOF;
    return (LastToken = TK_END_PROGRAM);
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