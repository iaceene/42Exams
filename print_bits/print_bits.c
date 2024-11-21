#include "libc.h"


void    print_bits(unsigned char octet)
{
    char s[8];
    int i = 0;
    int len = 8;

    while (i < 8)
    {
        s[len - 1] = octet % 2 + '0';
        i++;
        len--;
        octet = octet / 2;
    }
    i = 0;
    while(i < 8)
    {
        write(1, &s[i], 1);
        i++;
    }
}