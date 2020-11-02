%{
/* Ejemplo de Parser generado automáticamente.
* JMS 20090722
* El LIC analizado por el Parser es generado por la GIC:
*
S -> aTc
*
T -> aTc | b
*/
#include <stdio.h>
int yylex(void);
void yyerror(const char *);
%}
%%
S
    : 'a' T 'c'
    ;
T
    : 'a' T 'c'
    | 'b'
    ;
%%
int main(void){
    switch( yyparse() ){
    case 0:
        puts("Pertenece al LIC"); return 0;
    case 1:
        puts("No pertenece al LIC"); return 1;
    case 2:
        puts("Memoria insuficiente"); return 2;
    }
}
/* yylex es el Scanner. Retorna el siguiente símbolo (token).
* Si no hay más símbolos, retorna 0.
*/
int yylex(void){
    int c = getchar();
    if(c == EOF)
        return 0;
    return c;
}
/* Informa la ocurrencia de un error. */
void yyerror(const char *s){
    puts(s);
    return;
}