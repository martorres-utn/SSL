/* 
wl-2-goto.c
martorres-utn
20200709
*/

#include <stdio.h>

int main(void){

    int c;

MainLoop:
    if ((c = getchar()) != EOF) {            
        switch(c)
        {
            case ' ':
            case '\t':
            case '\n':
            case '.':
            case ',':
            case ';':
            {
                goto Out;
                break;
            }
            default:
            {
                goto In;
                break;
            }
        }
    }
    
    return 0;

In:
    putchar(c);
    goto MainLoop;

Out:
    putchar('\n');
    goto MainLoop;
}