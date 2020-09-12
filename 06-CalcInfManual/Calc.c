#include <stdio.h>
#include "Scanner.h"

#define LOOP_LIMIT 1000

int main(void)
{
    Token currentToken = T_END;
    int loopCounter = 0;
    while((currentToken = Scanner_GetNextToken()) != T_END && loopCounter < LOOP_LIMIT)
    {
        printf("t[%d]\n", currentToken);
        loopCounter++;
    }
    return 0;
}