#include "unistd.h"

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_isupper(int c)
{
    return(c >= 'A' && c <= 'Z');
}

int ft_islower(int c)
{
    return(c >= 'a' && c <= 'z');
}

int check(int c)
{
    return (c == '\0' || c == ' ');
}

void rstr_capitalizer(char **v)
{
    int i, j;
    i = 0;
    while(v[++i])
    {
        j = -1;
        while(v[i][++j])
        {
            if(check(v[i][j + 1]))
            {
                if(ft_isupper(v[i][j]))
                    ft_putchar(v[i][j]);
                else if(ft_islower(v[i][j]))
                    ft_putchar(v[i][j] - 32);
                else
                    ft_putchar(v[i][j]);
            }
            else if (ft_isupper(v[i][j]))
                ft_putchar(v[i][j] + 32);
            else
                ft_putchar(v[i][j]);
        }
        if(v[i + 1])
            ft_putchar('\n');
    }
}

int main(int c, char **v)
{
    if(c >= 2)
        rstr_capitalizer(v);
    return (write(1, "\n", 1), (0));
}