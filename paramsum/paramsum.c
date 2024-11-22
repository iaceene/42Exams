#include "libc.h"


void ft(int n)
{
    char list[10];
    int i = -1;
    int len = 0;
    int nbr = n;
    while(nbr)
    {
        nbr /= 10;
        len++;
    }
    list[len] = '\0';
    while(n)
    {
        list[--len] = (n % 10) + '0';
        n /= 10;
    }
    while(list[++i])
        write(1, &list[i], 1);
}

int main(int c, char **v)
{
    c -= 1;
    char tmp;
    if(c >= 0 && c <= 9)
    {
        tmp = c + '0';
        write(1, &tmp, 1);
    }
    else
        ft(c);
    write(1, "\n", 1);
}