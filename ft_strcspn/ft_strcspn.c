#include "libc.h"

int f(char c, char *s)
{
    int i = 0;
    while(s[i])
    {
        if(s[i] == c)
            return 1;
        i ++;
    }
    return 0;
}

size_t  ft_strcspn(const char *s, const char *reject)
{
    size_t i = 0;
    while(s[i])
    {
        if(f(s[i], (char *)reject))
            return (i);
        i++;
    }
    return (i);
}
