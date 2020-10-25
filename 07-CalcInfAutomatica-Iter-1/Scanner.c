#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "Scanner.h"
#include "lex.yy.h"

#define BUFFER_SIZE 33

//Scanner - private global variables
//static bool ReachedEOF = false;
//static bool LexicalError = false;
static Token LastToken = T_INITIAL;
static Token RemainingToken = T_INITIAL;
static char Buffer[BUFFER_SIZE]; // 32 characters + 1 '\0' 
static char RemainingText[BUFFER_SIZE]; // 32 characters + 1 '\0'

//Scanner - private functions
void Scanner_BufferClear(char someBuffer[]);

//Scanner - Implementations
Token Scanner_GetNextToken()
{
    if(RemainingToken != T_INITIAL)
    {
        LastToken = RemainingToken;
        strcpy(Buffer, RemainingText);

        RemainingToken = T_INITIAL;
        Scanner_BufferClear(RemainingText);
        return LastToken;
    }

    LastToken = yylex(); //get a new token from stream
    strcpy(Buffer, yyget_text()); //get new string from stream

    return LastToken;
}

void Scanner_BufferClear(char someBuffer[])
{
    for(size_t pos = 0; pos < BUFFER_SIZE; pos++)
        someBuffer[pos] = '\0';
}

void Scanner_BufferGetContent(char output[])
{
    if(RemainingText[0] != '\0')
    {
        strcpy(output, RemainingText);
        Scanner_BufferClear(RemainingText);
        return;
    }

    strcpy(output, Buffer);
}

void Scanner_UngetLastToken()
{
    RemainingToken = LastToken; //save last matching token
    strcpy(RemainingText, Buffer); //save last matching string in buffer
    
    LastToken = T_INITIAL;
    Scanner_BufferClear(Buffer);
}

/*bool Scanner_HasReachedEOF()
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
}*/