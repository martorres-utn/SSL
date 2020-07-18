/* 
wl-4.c
martorres-utn
20200718
*/

#include <stdio.h>

#define OUT 0
#define IN 1

//Funciones asociadas a transiciones

void PrintSymbol(int symbol)
{
    putchar(symbol);
}

void PrintLn(int symbol)
{
    putchar('\n');
}

//FSM

int main(void)
{   
    int currentState = OUT; //estado inicial
    int nextState; //estado siguiente
    int symbol; //symbolo por el cual se transiciona

    //matriz de acciones/funciones asociadas a transiciones
    void (*actionPtr[2][2])(int);

    //listado de acciones/funciones asociadas a transiciones
    actionPtr[OUT][OUT] = NULL;
    actionPtr[OUT][IN] = &PrintSymbol;
    actionPtr[IN][OUT] = &PrintLn;
    actionPtr[IN][IN] = &PrintSymbol;
    
    while ((symbol = getchar()) != EOF) {            
        switch(symbol)
        {
            case ' ':
            case '\t':
            case '\n':
            case '.':
            case ',':
            case ';':
            {
                nextState = OUT;
                break;
            }
            default:
            {
                nextState = IN;
                break;
            }
        }

        //ejecutar accion

        if(actionPtr[currentState][nextState] != NULL)
            actionPtr[currentState][nextState](symbol);

        currentState = nextState;
    }

    return 0;
}