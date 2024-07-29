#include "push_swap.h"

t_list  *populate_list_a(char **str)
{
    t_list *list;
    t_list  *new_node;
    t_list  *temp;
    int     i;

    i = 1;
    list = ft_lstnew(ft_atoi(str[i]));
    if (!list)
        return (NULL);
    while (str[++i])
    {
        new_node = ft_lstnew(ft_atoi(str[i]));
        if (!new_node)
        {
            while(list)
            {
                temp = list;
                list = list->next;
                free(temp);
            }
            return (NULL);
        }
        ft_lstadd_back(&list, new_node);
        free(new_node);
    }
    return (list);
}

t_list *init_list_b()
{
    t_list *b_list;

    b_list = (t_list *)malloc(sizeof(t_list));
    if (!b_list)
    {
        ft_printf("Error\n");
        return (NULL);
    }
    return(b_list);
}

void    dealloc(t_list **list)
{
    t_list  *temp;

    while(*list)
    {
        temp = (*list)->next;
        free(*list);
        *list = temp;
    }
}