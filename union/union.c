#include "libc.h"

int check(char c, int i, char *s)
{
    int index = 0;
    while(index < i)
    {
        if(c == s[index])
            return (0);
        index++;
    }
    return (1);
}

void ft(char *s1, char *s2)
{
    int i = 0;
    int index = 0;
    char s[300];
    while(s1[i])
        s[index++] = s1[i++];
    i = 0;
    while(s2[i])
        s[index++] = s2[i++];
    s[index] = '\0';
    i = 0;
    while(s[i])
    {
        if(check(s[i], i, s))
            write(1, &s[i], 1);
        i++;
    }
}

int main(int c, char **v)
{
    if(c == 3)
        ft(v[1], v[2]);
    write(1, "\n", 1);
    return (0);
}