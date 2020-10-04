#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "Scanner.h"
#include "lex.yy.h"

#define BUFFER_SIZE 33

//Scanner - private global variables
static bool ReachedEOF = false;
static bool LexicalError = false;
static Token LastToken = T_INITIAL;
static Token RemainingToken = T_INITIAL;
static char Buffer[BUFFER_SIZE]; // 32 characters + 1 '\0' 
static char RemainingText[BUFFER_SIZE]; // 32 characters + 1 '\0' 
//static size_t BufferTop = 0;

//Scanner - private functions
//void Scanner_BufferPush(int symbol);
//int Scanner_BufferPop();
void Scanner_BufferClear(char someBuffer[]);

//Scanner - Implementations
Token Scanner_GetNextToken()
{
    if(RemainingToken != T_INITIAL)
    {
        LastToken = RemainingToken;
        strcpy(Buffer, RemainingText);
        //BufferTop = strlen(RemainingText);

        RemainingToken = T_INITIAL;
        Scanner_BufferClear(RemainingText);
        return LastToken;
    }

    LastToken = yylex(); //get a new token from stream
    strcpy(Buffer, yyget_text()); //get new string from stream

    return LastToken;
}

/*void Scanner_BufferPush(int symbol)
{
    Buffer[BufferTop++] = symbol;
    Buffer[BufferTop] = '\0';
}

int Scanner_BufferPop()
{
    int symbol = Buffer[--BufferTop];
    Buffer[BufferTop] = '\0';
    return symbol;
}*/

void Scanner_BufferClear(char someBuffer[])
{
    for(size_t pos = 0; pos < BUFFER_SIZE; pos++)
        someBuffer[pos] = '\0';
    /*if(someBufferTop != NULL)
        (*someBufferTop) = 0;*/
}

void Scanner_BufferGetContent(char output[])
{
    //strcpy(output, Buffer);
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
    /*while(BufferTop > 0)
        ungetc(Scanner_BufferPop(), stdin);*/

    RemainingToken = LastToken; //save last matching token
    strcpy(RemainingText, Buffer); //save last matching string in buffer
    
    LastToken = T_INITIAL;
    Scanner_BufferClear(Buffer);
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