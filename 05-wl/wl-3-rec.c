/* 
wl-3-rec.c
martorres-utn
20200709
*/

#include <stdio.h>

//declaration

void InOut(void);
void In(void);
void Out(void);

//implementation

void InOut()
{     
    int c;    
    switch((c = getchar()))
    {
        case EOF:
            return;
        case ' ':
        case '\t':
        case '\n':
        case '.':
        case ',':
        case ';':
        {
            putchar('\n');
            break;
        }
        default:
            putchar(c);
    }
    InOut();
}

void Out()
{
    int c;
    switch((c = getchar()))
    {
        case EOF:
            return;
        case ' ':
        case '\t':
        case '\n':
        case '.':
        case ',':
        case ';':
        {
            Out();
            break;
        }
        default:
        {
            putchar(c);
            In();
        }
    }
}

void In()
{
    int c;
    switch((c = getchar()))
    {
        case EOF:
            return;
        case ' ':
        case '\t':
        case '\n':
        case '.':
        case ',':
        case ';':
        {
            putchar('\n');
            Out();
            break;
        }
        default:
        {
            putchar(c);
            In();
        }
    }
}

int main(void)
{
    Out();
    return 0;
}