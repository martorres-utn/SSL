%{
#include <stdio.h>
#include <stdbool.h>
#include "Scanner.h"
#include "SemanticValue.h"
#include "VariableManager.h"

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
    : TK_ID TK_ASSIGN expression statement_end { VariableManager_SetValue($1.strVal, $3.intVal); }
    | TK_PRINT TK_L_PAR expression TK_R_PAR statement_end { /*printf("[debug - AutoParser - 3: %i]\n", $3.intVal);*/ printf("$:%i\n", $3.intVal); }
;

statement_end 
    : TK_END_PROGRAM { VariableManager_RemoveAll(); }
    | TK_END_STATEMENT
;

expression 
    : term  { /*printf("[debug - AutoParser - term: %i]\n", $1.intVal);*/ $$.intVal = $1.intVal; }
    | expression TK_OP_PLUS term  { $$.intVal = $1.intVal + $3.intVal; }
;

term 
    : factor { /*printf("[debug - AutoParser - factor: %i]\n", $1.intVal);*/ $$.intVal = $1.intVal; }
    | term TK_OP_PROD factor { $$.intVal = $1.intVal * $3.intVal; }
;

factor 
    : TK_ID { int value = 0; bool foundVar = VariableManager_GetValue($1.strVal, &value); if(foundVar) { $$.intVal = value; } else { yyerror("Variable Undefined!"); } }
    | TK_CONSTANT { /*printf("[debug - AutoParser - TK_CONSTANT: %i]\n", $1.intVal);*/ $$.intVal = $1.intVal; }
    | TK_L_PAR expression TK_R_PAR  { $$.intVal = $2.intVal; }
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