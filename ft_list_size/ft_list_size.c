#include "libc.h"

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int     ft_list_size(t_list *begin_list)
{
    if(!begin_list)
        return (0);
    int i = 1;
    while(begin_list->next && begin_list)
    {
        begin_list = begin_list->next;
        i++;
    }
    return (i);
}