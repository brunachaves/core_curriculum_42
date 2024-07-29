#include "push_swap.h"

void   swap_a(t_list *a_list)
{
    int  aux1;
    int  aux2;

    if(a_list && a_list->next)
    {
        aux1 = a_list->next->content;
        aux2 = a_list->content;
        a_list->content = aux1;
        a_list->next->content = aux2;
        ft_printf("sa\n");
    }
}

void    push_a(t_list **a_list, t_list **b_list)
{
    t_list  *aux;

    if (b_list && *b_list)
    {
        aux = *b_list;
        *b_list = aux->next;
        ft_lstadd_front(a_list, aux);
        ft_printf("pa\n");
    }
}

void    rotate_a(t_list **a_list)
{
    t_list  *first;
    t_list *last;

    if(*a_list && (*a_list)->next)
    {
        first = *a_list;
        *a_list = first->next;
        last = ft_lstlast(*a_list);
        last->next = first;
        first->next =  NULL;
        ft_printf("ra\n");
    }
}

void    rotate_reverse_a(t_list **a_list)
{
    t_list  *temp;
    t_list *last;
    t_list *aux;

    if (!a_list || !*a_list || !(*a_list)->next)
        return ;
    temp = ft_lstlast(*a_list);
    aux = *a_list;
    while(aux->next)
    {
        last = aux;
        aux = aux->next;
    }
    last->next = NULL;
    ft_lstadd_front(a_list, temp);
    ft_printf("rra\n");
}