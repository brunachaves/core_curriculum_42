/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:10:22 by brchaves          #+#    #+#             */
/*   Updated: 2024/07/30 13:52:58 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*init_bits(void)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (32 + 1));
	if (!str)
		return (NULL);
	str[32] = '\0';
	while (i < 32)
	{
		str[i] = '0';
		i++;
	}
	return (str);
}

char	*int_to_bits(char *str)
{
	long int	num;
	int			i;
	char		*bits;

	num = (long int)ft_atoi(str);
	i = 31;
	bits = init_bits();
	if (!bits)
		return (NULL);
	if (num < 0)
	{
		bits[0] = '1';
		num *= (-1);
	}
	while (num > 0 && i >= 1)
    {
        bits[i] = (num % 2) + '0';
        num /= 2;
        i--;
    }
    while (i >= 1)
    {
        bits[i] = '0';
        i--;
    }
	return (bits);
}

t_list	*populate_list_a(char **str)
{
	t_list	*list;
	t_list	*new_node;
	t_list	*temp;
	int		i;

	i = 1;
	list = ft_lstnew(int_to_bits(str[i]));
	if (!list)
		return (NULL);
	while (str[++i])
	{
		new_node = ft_lstnew(int_to_bits(str[i]));
		if (!new_node)
		{
			while (list)
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

void	dealloc(t_list **list)
{
	t_list	*temp;

	while (*list)
	{
		temp = (*list)->next;
		free(*list);
		*list = temp;
	}
}
