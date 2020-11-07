%{
#include <stdio.h>
#include "Scanner.h"

static int yylex(void);
void yyerror(const char *);

%}

%token TK_ID TK_CONSTANT TK_OP_PLUS TK_OP_PROD TK_L_PAR TK_R_PAR TK_ASSIGN TK_PRINT TK_END_STATEMENT
%token TK_END_PROGRAM 0

%%
statement_list 
    : single_statement 
    | statement_list single_statement
;

single_statement 
    : TK_ID TK_ASSIGN expression statement_end 
    | TK_PRINT TK_L_PAR expression TK_R_PAR statement_end { printf("[debug - AutoParser - 3: %i]\n", $3); printf("$:%i\n", $3); }
;

statement_end : TK_END_PROGRAM | TK_END_STATEMENT
;

expression 
    : term  { printf("[debug - AutoParser - term: %i]\n", $1); $$ = $1; }
    | expression TK_OP_PLUS term  { $$ = $1 + $3; }
;

term 
    : factor { printf("[debug - AutoParser - factor: %i]\n", $1); $$ = $1; }
    | term TK_OP_PROD factor { $$ = $1 * $3; }
;

factor 
    : TK_ID
    | TK_CONSTANT { printf("[debug - AutoParser - TK_CONSTANT: %i]\n", $1); $$ = $1; }
    | TK_L_PAR expression TK_R_PAR  { $$ = $2; }
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