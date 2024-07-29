#include "push_swap.h"

void    sort_five_less(t_list **a_list)
{
    t_list  *b_list;
    int size;
    int i;

    b_list = (t_list *)malloc(sizeof(t_list));
    if(!b_list)
        return ;
    size = ft_lstsize(*a_list);
    i = size;
    while (i > 3)
    {
        push_b(a_list, &b_list);
        i--;
    }
    if (b_list && b_list->next)
    {
        if ((int)b_list->content < (int)(b_list->next)->content)
            swap_b(b_list, 0);
    }
    sort_a(a_list);
    while(i < size)
    {
        push_a(a_list, &b_list);
        sort_pushed_one(a_list, &b_list);
        i++;
    }
    free(b_list);
}

void    sort_a(t_list **a_list)
{
    int size;
    int a;
    int b;
    int c;

    size = ft_lstsize(*a_list);
    if (size > 1)
    {
        a = (*a_list)->content;
        b = ((*a_list)->next)->content;
        if (size == 2)
        {
            if (a > b)
                swap_a(*a_list, 0);
        }
        else if(size == 3)
        {
            c = (((*a_list)->next)->next)->content;
            if (a > b && a > c)
                rotate_a(*a_list, 0);
            else if(b > a && b > c);
            {
                swap_a(*a_list, 0);
                rotate_a(*a_list, 0);
            }
            if (a > b)
                swap_a(*a_list, 0);
        }
    }
}

void    sort_pushed_one(t_list **a_list, t_list **b_list)
{
    t_list  *added;
    t_list  *next;
    t_list  *previous;
    int     i;

    previous = NULL;
    added = *a_list;
    next =  (*a_list)->next;
    i = 0;
    while(next)
    {
        if(added->content > next->content)
        {
            if(previous == NULL)
                swap_a(*a_list, 0);
            else
            {
                push_b(*a_list, *b_list);
                swap_a(*a_list, 0);
                push_a(*a_list, *b_list);
            }
            next = next->next;
        }
        next = next->content;
    }
}