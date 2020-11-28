%{
#include <stdio.h>
#include <stdbool.h>
#include "Scanner.h"
#include "SemanticValue.h"
#include "VariableManager.h"
#include "TokenDefinition.h"

static int yylex(void);
void yyerror(const char *);

%}

%token TK_END_PROGRAM 0
%token TK_ID 1
%token TK_CONSTANT 2
%token TK_OP_PLUS 3
%token TK_OP_PROD 4
%token TK_L_PAR 5
%token TK_R_PAR 6
%token TK_ASSIGN 7
%token TK_PRINT 8
%token TK_END_STATEMENT 9

%%
statement_list 
    : single_statement 
    | statement_list single_statement
;

single_statement 
    : TK_ID TK_ASSIGN expression statement_end { VariableManager_SetValue($1.strVal, $3.intVal); }
    | TK_PRINT TK_L_PAR expression TK_R_PAR statement_end { printf("$:%i\n", $3.intVal); }
;

statement_end 
    : TK_END_PROGRAM { VariableManager_RemoveAll(); }
    | TK_END_STATEMENT
;

expression 
    : term  { $$.intVal = $1.intVal; }
    | expression TK_OP_PLUS term  { $$.intVal = $1.intVal + $3.intVal; }
;

term 
    : factor { $$.intVal = $1.intVal; }
    | term TK_OP_PROD factor { $$.intVal = $1.intVal * $3.intVal; }
;

factor 
    : TK_ID { int value = 0; bool foundVar = VariableManager_GetValue($1.strVal, &value); if(foundVar) { $$.intVal = value; } else { yyerror("Variable Undefined!"); } }
    | TK_CONSTANT { $$.intVal = $1.intVal; }
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