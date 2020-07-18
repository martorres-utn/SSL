/* 
wl-1-enum-switch.c
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
                switch(s)
                {
                    case In:
                    {
                        s = Out;
                        putchar('\n');
                    }
                    case Out:
                        s = Out;
                }
                break;
            }
            default:
            {
                switch(s)
                {
                    case In:
                    case Out:
                    {        
                        s = In;
                        putchar(c);
                    }
                }
                break;
            }
        }
    }
    
    return 0;
}