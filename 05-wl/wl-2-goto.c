/* 
wl-2-goto.c
martorres-utn
20200709
*/

#include <stdio.h>

int main(void){
    int c;
Out:
    switch(c = getchar())
    {
        case ' ': case '\t': case '\n': case '.': case ',': case ';': putchar('\n');
            goto Out;
        case EOF: goto EndMain;
        default: goto In;
    }
In:
    putchar(c);
    goto Out;
EndMain:    
    return 0;
}