#include "push_swap.h"

void   swap_s(t_list *a_list, t_list *b_list)
{
    int simultaneous;

    simultaneous = 1;
    swap_a(a_list, simultaneous);
    swap_b(b_list, simultaneous);
    ft_printf("sb\n");
}

void    rotate_r(t_list **a_list, t_list **b_list)
{
    int simultaneous;

    simultaneous = 1;
    rotate_a(a_list, simultaneous);
    rotate_b(b_list, simultaneous);
    ft_printf("rr\n");
}

void    rotate_reverse_r(t_list **a_list, t_list **b_list)
{
    int simultaneous;

    simultaneous = 1;
    rotate_reverse_a(a_list, simultaneous);
    rotate_reverse_b(b_list, simultaneous);
    ft_printf("rrr\n");
}