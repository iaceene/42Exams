#include "list.h"

int ascending(int a, int b)
{
	return (a <= b);
}

void ft_addback(t_list **head, int data)
{
    t_list *tmp;
    tmp = *head;
    t_list *new = malloc(sizeof(t_list));
    if(!new)
        return ;
    new->data = data;
    new->next = NULL;
    if (!*head)
        *head = new;
    else
    {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
}

int main()
{
    t_list *head;
    t_list *tmp;
    int data[10]= {12, 4, -2, 13, 56, 2, 43, 214, 23, 31};
    head = NULL;
    int i = 0;
    while(i < 10)
    {
        ft_addback(&head, data[i]);
        i++;
    }
    tmp = head;
    printf("       == Before ==\n{ ");
    while(tmp)
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("}\n       == After ==\n{ ");
    tmp = sort_list(head, ascending);
    while(tmp)
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("}\n");
    return (0);
}