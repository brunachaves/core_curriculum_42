#include "push_swap.h"

void   *swap_s(t_list *a_list, t_list *b_list)
{
    if (a_list->next && b_list->next)
    {
        swap_a(a_list);
        swap_b(b_list);
        ft_printf("sb\n");
    }
}

