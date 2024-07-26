#include "push_swap.h"

void   *swap_a(t_list *a_list)
{
    t_list  *aux1;
    t_list  *aux2;

    if(a_list->next)
    {
        aux1->content = a_list->next->content;
        aux2->content = a_list->content;
        a_list->content = aux1->content;
        a_list->next->content = aux2->content;
        ft_printf("sa\n");
    }
}

void    push_a(t_list *a_list, t_lost *b_list)
{
    t_list  *aux1;
    t_list  *aux2;

    aux1 = b_list;
    aux2 = b_list->next;
    ft_lstadd_front(&a_list, aux);
    b_list->content = aux->content;
    b_list = aux2;
    ft_printf("pa\n");

}