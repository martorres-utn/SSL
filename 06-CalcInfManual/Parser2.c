#include "Parser2.h"

void Parser_Start()
{
    Token tokenBuffer[TOKEN_BUFFER_SIZE];
    Token currentToken = T_END;
    size_t bufferTop = 0;
    
    while(!Scanner_HasReachedEOF())
    {
        Parser_CleanBuffer(tokenBuffer, TOKEN_BUFFER_SIZE);
        bufferTop = 0;

        Scanner_ResetInternalState();

        while((currentToken = Scanner_GetNextToken()) != T_END)
        {
            printf("t[%d],", currentToken);
            tokenBuffer[bufferTop++] = currentToken;
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

//new

void Parser_Aux_Match(Token expectedToken)
{
    Token currentToken = Scanner_GetNextToken();
    if(currentToken != expectedToken)
    {
        Token expectedTokens[1] = { expectedToken };
        Parser_Aux_SyntaxError(expectedTokens, 1, currentToken);
    }
}

void Parser_Aux_SyntaxError(Token expectedTokens[], size_t expectedSize, Token foundToken)
{
    SyntaxError = true;
    printf("[syntax error! - expected one of the following:");
    for(size_t pos = 0; pos < expectedSize; pos++)
    {
        printf("t[%d]", expectedTokens[pos]);
    }
    printf(" but current:%d]", foundToken);
}

void Parser_SAP_Target() 
{
    Parser_SAP_Program();
    Parser_Aux_Match(T_END);
}

void Parser_SAP_Program()
{
    Parser_SAP_SentenceList();
}

void Parser_SAP_SentenceList()
{
    Parser_SAP_SingleSentence(); /* la primera de la lista de sentencias */
    while (!SyntaxError) { /* un ciclo indefinido */
        Token currentToken = Scanner_GetNextToken();
        switch (currentToken) {
            case T_ID: case T_PRINT: /* detectó token correcto */
            {
                Scanner_UngetLastToken(); //devuelvo T_ID o T_PRINT
                Parser_SAP_SingleSentence(); /* procesa la secuencia opcional */
                break;
            }
            default:
            {
                return;
            }
        } /* fin switch */
    }
}

void Parser_SAP_SingleSentence()
{
    Token token = Scanner_GetNextToken();
    switch (token) {
        case T_ID: /* <sentencia> -> ID = <expresion> */
        {
            Scanner_UngetLastToken(); //devolver token ID leido
            
            Parser_Aux_Match(T_ID); 
            Parser_Aux_Match(T_ASSIGN);
            Parser_SAP_Expression(); 
            Parser_Aux_Match(T_END);
            break;
        }
        case T_PRINT: /* <sentencia> -> $(<expresion>) */
        {
            Scanner_UngetLastToken(); //devolver token ID leido

            Parser_Aux_Match(T_PRINT);
            Parser_Aux_Match(T_L_PAR);
            Parser_SAP_Expression();
            Parser_Aux_Match(T_R_PAR);
            Parser_Aux_Match(T_END);
            break;
        }
        default:
        {
            Token expectedTokens[2] = { T_ID, T_PRINT };
            Parser_Aux_SyntaxError(expectedTokens, 2, token);
            break;
        }
    }
}

void Parser_SAP_Expression() 
{
    Parser_SAP_Term(); //single <term>
    
    while (!SyntaxError) //undefined cycle of + <term>
    {
        //if(Scanner_GetLastToken() == T_END) //no T_END in the middle of an expression
            //return;

        Token currentToken = Scanner_GetNextToken();
        switch (currentToken) {
            case T_OP_PLUS:
            {
                Parser_SAP_Expression();
                break;
            }
            default:
            {
                Scanner_UngetLastToken(); //devolver token ID leido
                return;
            }
        }
    }
}

void Parser_SAP_Term() 
{
    Parser_SAP_Factor(); //single expression
    
    while (!SyntaxError) //undefined cycle of * <factor>
    {
        Token currentToken = Scanner_GetNextToken();
        switch (currentToken) {
            case T_OP_PROD:
            {
                Parser_SAP_Term();
                break;
            }
            default:
            {
                Scanner_UngetLastToken(); //devolver token ID leido
                return;
            }
        }
    }
}

void Parser_SAP_Factor()
{
    Token currentToken = Scanner_GetNextToken();

    if(currentToken == T_ID)
    {
        //#process_id
        return;
    }
    else if(currentToken == T_CONSTANT)
    {
        //#process_constant
        return;
    }
    else if(currentToken == T_L_PAR)
    {
        Scanner_UngetLastToken(); //devolver token ID leido

        Parser_Aux_Match(T_L_PAR);
        Parser_SAP_Expression();
        Parser_Aux_Match(T_R_PAR);
        
        return;
    }
    else
    {
        Token expectedTokens[3] = { T_ID, T_CONSTANT, T_L_PAR };
        Parser_Aux_SyntaxError(expectedTokens, 3, currentToken);
        return;
    }
}
