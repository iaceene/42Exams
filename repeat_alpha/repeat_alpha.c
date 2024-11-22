#include "libc.h"

int is_alpha(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int get_index(char c)
{
    if(c >= 'a' && c <= 'z')
        return (c - 'a');
    else
        return (c - 'A');
}

void ft(char *s)
{
    int i = 0;
    int j = 0;
    while(s[i])
    {
        j = 0;
        if(is_alpha(s[i]))
        {
            while(j <= get_index(s[i]))
            {
                write(1, &s[i], 1);
                j++;
            }
        }
        else
            write(1, &s[i], 1);
        i++;
    }
}

int main(int c, char **v)
{
    if(c == 2)
        ft(v[1]);
    write(1, "\n", 1);
    return (0);
}