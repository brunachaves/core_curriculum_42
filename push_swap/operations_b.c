#include "push_swap.h"

void   *swap_b(t_list *b_list)
{
    t_list  *aux1;
    t_list  *aux2;

    if(b_list->next)
    {
        aux1->content = b_list->next->content;
        aux2->content = b_list->content;
        b_list->content = aux1->content;
        b_list->next->content = aux2->content;
        ft_printf("sb\n");
    }
}

void    push_b(t_list *a_list, t_lost *b_list)
{
    t_list  *aux1;
    t_list  *aux2;

    aux1 = a_list;
    aux2 = a_list->next;
    ft_lstadd_front(&b_list, aux);
    a_list->content = aux->content;
    a_list = aux2;
    ft_printf("pb\n");

}