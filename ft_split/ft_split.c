#include "libc.h"

int is(char c)
{
    return (c == ' ' || c == '\n' || c == '\t');
}

int ft_coutwords(char *s)
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

char *ft_allo(char *s, int *i)
{
    int j = 0;
    while(s[*i] && is(s[*i]))
        (*i)++;
    j = *i;
    while(s[j] && !is(s[j]))
        j++;
    char *res = malloc(j  + 1);
    j = 0;
    while(s[*i] && !is(s[*i]))
    {
        res[j] = s[*i];
        j++;
        (*i)++;
    }
    res[j] = '\0';
    return (res);
}


char    **ft_split(char *str)
{
    int count = ft_coutwords(str);
    char **p = malloc((count + 1) * sizeof(char *));
    p[count] = NULL;
    int index = 0;
    int i = 0;
    while(i < count)
    {
        p[i] = ft_allo(str, &index);
        i++;
    }
    return(p);
}
