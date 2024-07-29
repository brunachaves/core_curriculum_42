#include "push_swap.h"

void   swap_s(t_list *a_list, t_list *b_list)
{
    swap_a(a_list);
    swap_b(b_list);
    ft_printf("sb\n");
}

void    rotate_r(t_list **a_list, t_list **b_list)
{
    rotate_a(a_list);
    rotate_b(b_list);
    ft_printf("rr\n");
}

void    rotate_reverse_r(t_list **a_list, t_list **b_list)
{
    rotate_reverse_a(a_list);
    rotate_reverse_b(b_list);
    ft_printf("rrr\n");
}