/* 

*/

#include <stdio.h>

enum States
{
    In,
    Out
};

typedef enum States State;

int main(void){
    State s = Out;
    int c, nl, nw, nc;
    nl = nw = nc = 0; 

    while ((c = getchar()) != EOF) {            
        ++nc;
        
        /*
        //original version
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            s = Out;
        else if (s == Out) {
            s = In;
            ++nw;
        }
        */

        //switch version
        switch(c)
        {
            case '\n':
            {
                ++nl; //accion asociada
                s = Out; //transicion
            }
            case ' ':
            case '\t':
            {
                s = Out; //transicion
                break;
            }
            default:
            {
                if (s == Out) {
                    s = In; //transicion
                    ++nw;//accion asociada
                }
                break;
            }
        }
    }

    printf("%d %d %d\n", nl, nw, nc);
}