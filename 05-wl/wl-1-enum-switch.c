/* 
wl-1-enum-switch.h
martorres-utn
20200709
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
    int c;

    while ((c = getchar()) != EOF) {            
        switch(c)
        {
            case ' ':
            case '\t':
            case '\n':
            case '.':
            case ',':
            case ';':
            {
                if(s == In)
                {
                    s = Out;
                    putchar('\n');
                }
                break;
            }
            default:
            {
                s = In;
                putchar(c);
                break;
            }
        }
    }
    
    return 0;
}