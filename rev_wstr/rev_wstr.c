#include "unistd.h"

void rev_wstr(char *s)
{
    int len = -1;
    while(s[++len] == ' ');
    s = s + len;
    len = 0;
    while(s[++len]);
    int start, end = 0;
    while(--len && len >= 0)
    {
        while(*(s + len) && *(s + len) == ' ')
            len--;
        end = len + 1;
        while(*(s + len) && *(s + len) != ' ')
            len--;
        start = len;
        while(++start < end)
            write(1, s + start, 1);
        if(len - 1 > 0)
            write(1, " ", 1);
    }
}

int main(int c, char **v)
{
    if(c == 2)
        rev_wstr(v[1]);
    return(write(1, "\n", 1), 0);
}
