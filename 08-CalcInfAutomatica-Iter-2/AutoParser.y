%{
#include <stdio.h>
#include "Scanner.h"

static int yylex(void);
void yyerror(const char *);

%}

%token TK_ID TK_CONSTANT TK_OP_PLUS TK_OP_PROD TK_L_PAR TK_R_PAR TK_ASSIGN TK_PRINT TK_END_STATEMENT
%token TK_END_PROGRAM 0

%%
statement_list : single_statement | statement_list single_statement
;

single_statement : TK_ID TK_ASSIGN expression statement_end | TK_PRINT TK_L_PAR expression TK_R_PAR statement_end
;

statement_end : TK_END_PROGRAM | TK_END_STATEMENT
;

expression : term | expression TK_OP_PLUS term
;

term : factor | term TK_OP_PROD factor
;

factor : TK_ID | TK_CONSTANT | TK_L_PAR expression TK_R_PAR
;
%%

/* 
* yylex es el Scanner. Retorna el siguiente símbolo (token).
* Si no hay más símbolos, retorna 0.
*/
int yylex(void){   
    return Scanner_GetNextToken();
}

/* Informa la ocurrencia de un error. */
void yyerror(const char *s){
    puts(s);
    return;
}