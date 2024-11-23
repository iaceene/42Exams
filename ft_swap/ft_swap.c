#include "libc.h"


void    ft_swap(int *a, int *b)
{
    int i = *a;
    *a = *b;
    *b = i;
}