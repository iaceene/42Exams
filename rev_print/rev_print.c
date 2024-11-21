#include "libc.h"

void ft(char *s)
{
    int len = 0;
    while(s[len])
        len++;
    while(s[--len])
        write(1, &s[len], 1);
}

int main(int c, char **v)
{
    if(c == 2)
        ft(v[1]);
    write(1, "\n", 1);
    return (0);
}