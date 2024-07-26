#include "push_swap.h"

t_list  *populate_list(char **str)
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
                tem = list;
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