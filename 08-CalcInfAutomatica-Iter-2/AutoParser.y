%{
/*
Parser Calculadora

Gramatica:

        <objetivo> -> <programa> TK_END ( Esta es la producción global que se agrega)

        <programa> -> <listaSentencias>

        <listaSentencias> -> <sentencia> {<sentencia>}

        <sentencia> -> TK_ID TK_ASSIGN <expresión> TK_END | TK_PRINT TK_L_PAR <expresion> TK_R_PAR TK_END

        <expresion> -> <termino> | <termino> + <expresion>

        <termino> -> <factor> | <factor> * <termino>

        <factor> -> TK_ID | TK_CONSTANT | TK_L_PAR <expresión> TK_R_PAR


*/
#include <stdio.h>
//#include "ScannerTypes.h"
#include "lex.yy.h"
//int yylex(void);
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
/*int main(void){
    switch( yyparse() ){
    case 0:
        puts("Pertenece al LIC"); return 0;
    case 1:
        puts("No pertenece al LIC"); return 1;
    case 2:
        puts("Memoria insuficiente"); return 2;
    }
}*/
/* yylex es el Scanner. Retorna el siguiente símbolo (token).
* Si no hay más símbolos, retorna 0.
*/
/*int yylex(void){
    int c = getchar();
    if(c == EOF)
        return 0;
    return c;
}*/
/* Informa la ocurrencia de un error. */
void yyerror(const char *s){
    puts(s);
    return;
}