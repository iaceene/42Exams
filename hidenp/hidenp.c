#include "libc.h"


int check(char c, char *s, int *index)
{
    while(s[*index])
    {
        if(s[*index] == c)
            return 1;
        (*index)++;
    }
    return 0;
}

void ft(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    int count = 0;
    while(s1[i])
    {
        if(check(s1[i], s2, &j))
            count++;
        else
        {
            write(1, "0", 1);
            return;
        }
        i++;
    }
    write(1, "1", 1);
}

int main(int c, char **v)
{
    if (c == 3)
        ft(v[1], v[2]);
    write(1, "\n", 1);
    return (0);
}