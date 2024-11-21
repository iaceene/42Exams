#include <unistd.h>
#include <stdlib.h>

void ft_putstr(char *s)
{
    int i = 0;
    while(s[i])
    {
        write(1, &s[i], 1);
        i++;
    }
}


int ft_isspliter(char c)
{
    return (c == ' ' || c == '\n' || c == '\t');
}
void new_putstr(char *str)
{
    int i = 0;
    while(str[i] && ft_isspliter(str[i]))
        i++;
    while(str[i] && !ft_isspliter(str[i]))
    {
        write(1, &str[i], 1);
        i++;
    }
}

int ft_count(char *str)
{
    int i = 0;
    int c = 0;
    while (str[i])
    {
        while (str[i] && ft_isspliter(str[i]))
            i++;
        if (str[i])
            c++;
        while (str[i] && !ft_isspliter(str[i]))
            i++;
    }
    return (c);
}

int ft_size(char *s, int *i)
{
    int len = 0;
    while(s[*i] && ft_isspliter(s[*i]))
        (*i)++;
    while(s[*i] && !ft_isspliter(s[*i]))
    {
        (*i)++;
        len++;
    }
    return (len);
}

char *ft_cpy(char *s, char *d, int *index)
{
    int i = 0;
    while(s[*index] && ft_isspliter(s[*index]))
        (*index)++;
    while(s[*index] && !ft_isspliter(s[*index]))
    {
        d[i] = s[*index];
        (*index)++;
        i++;
    }
    d[i] = '\0';
    return (d);
}

void ft_swap(char **a, char **b)
{
    char *tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void ft_rostring(char **words, int count)
{
    int i = 1;
    char *tmp = words[0];
    while (i < count)
    {
        ft_swap(&words[i], &words[i - 1]);
        i++;
    }
    ft_swap(&tmp, &words[count]);
    i = 0;
    while (i < count)
    {
        ft_putstr(words[i]);
        if(i + 1 < count)
            ft_putstr(" ");
        free(words[i]);
        i++;
    }
    free(words);
}

void ft(char *s)
{
    int count = ft_count(s);
    if(count == 1)
    {
        new_putstr(s);
        return;
    }
    char **words = malloc(sizeof(char *) * (count + 1));
    if(!words)
        return;
    int i = 0;
    int index = 0;
    words[count] = NULL;
    
    while(i < count)
    {
        words[i] = malloc(ft_size(s, &index) + 1);
        if(!words[i])
            return;
        i++;
    }
    i = 0;
    index = 0;
    while(i < count)
    {
        words[i] = ft_cpy(s, words[i], &index);
        i++;
    }
    ft_rostring(words, count);
}

int main(int c, char **v)
{
    if(c >= 2)
        ft(v[1]);
    write(1, "\n", 1);
    return (0);
}
