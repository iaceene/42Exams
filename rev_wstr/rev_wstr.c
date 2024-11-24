#include "unistd.h"

int is(char c)
{
    return (c == ' ' || c == '\n' || c == '\t');
}

int ft_countwords(char *s)
{
    int i  = 0;
    int count = 0;
    while(s[i])
    {
        while(s[i] && is(s[i]))
            i++;
        if(s[i])
            count++;
        while (s[i] && !is(s[i]))
            i++;
    }
    return (count);
}

void ft_print(char *s, int start, int end, int *count)
{
    if (start == -1)
        start = 0;
    while(start <= end)
    {
        write(1, &s[start], 1);
        start++;
    }
    (*count)++;
    if(*count == ft_countwords(s) - 1)
        write(1, " ", 1);
}

void ft(char *s)
{
    int count = 0;
    int end = 0;
    int i = 0;
    while (s[i])
        i++;
    i--;
    while(s[i])
    {
        while(s[i] && is(s[i]))
            i--;
        if(s[i])
            end = i;
        while(s[i] && !is(s[i]))
            i--;
        ft_print(s, i, end, &count);
    }
}

int main(int c, char **v)
{
    if(c == 2)
        ft(v[1]);
    write(1, "\n", 1);
    return (0);
}
