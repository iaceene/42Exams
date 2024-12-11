#include "unistd.h"

int check(char c, char *s, int n)
{
    int i = -1;
    while(s[++i] && i < n)
        if(*(s + i) == c)
            return (0);
    return (1);
}

int in(char c, char *s)
{
    int i = -1;
    while(s[++i])
        if(*(s + i) == c)
            return (1);
    return (0);
}

void inter(char *s1, char *s2)
{
    int i = -1;
    while(s1[++i])
        if(in(*(s1 + i), s2) && check(*(s1 + i), s1, i))
            write(1, s1 + i, 1);
}

int main(int c, char **v)
{
    if(c == 3)
        inter(v[1], v[2]);
    return (write(1, "\n", 1), 0);
}
