#include "Parser.h"

void Parser_Start()
{
    Token tokenBuffer[TOKEN_BUFFER_SIZE];
    Token currentToken = T_END;
    size_t bufferTop = 0;

    int iterCounter = 0;
    
    while(!Scanner_HasReachedEOF())
    {
        Parser_CleanBuffer(tokenBuffer, TOKEN_BUFFER_SIZE);
        bufferTop = 0;

        while((currentToken = Scanner_GetNextToken()) != T_END && iterCounter < PARSER_LOOP_LIMIT)
        {
            printf("t[%d],", currentToken);
            tokenBuffer[bufferTop++] = currentToken;
            iterCounter++;
        }

        if(!Scanner_HasFoundLexicalError())
        {
            bool isValid = Parser_IsExpression(tokenBuffer, bufferTop, 0, bufferTop);
            printf(" -> Syntax %s \n", isValid ? "Ok" : "Error");
        }
        else
        {
            Scanner_MoveToNextExpression();
        }
    }
}

void Parser_CleanBuffer(Token buffer[], size_t max)
{
    for(size_t pos = 0; pos < max; pos++)
        buffer[pos] = T_INITIAL;
}

bool Parser_IsExpression(Token buffer[], size_t max, size_t start, size_t end)
{
    size_t pos;
    for(size_t pos = start; pos < end && pos < max; pos++)
        if(buffer[pos] == T_OP_PLUS)
            return Parser_IsTerm(buffer, max, start, pos) && Parser_IsExpression(buffer, max, pos + 1, end);

    return Parser_IsTerm(buffer, max, start, end);
}

bool Parser_IsTerm(Token buffer[], size_t max, size_t start, size_t end)
{
    size_t pos;
    for(size_t pos = start; pos < end && pos < max; pos++)
        if(buffer[pos] == T_OP_PROD)
            return Parser_IsFactor(buffer, max, start, pos) && Parser_IsTerm(buffer, max, pos + 1, end);

    return Parser_IsFactor(buffer, max, start, end);
}

bool Parser_IsFactor(Token buffer[], size_t max, size_t start, size_t end)
{
    return buffer[start] == T_ID || buffer[start] == T_CONSTANT;
}