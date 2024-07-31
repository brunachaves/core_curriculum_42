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

char	*int_to_bits(int num)
{
	char	*bits;
	int		i;

	i = 31;
	bits = (char *)malloc(sizeof(char) * (32 + 1));
	if (!bits)
		return (NULL);
	bits[32] = '\0';
	while (i >= 0)
	{
		if (num & 1)
			bits[i] = '1';
		else
			bits[i] = '0';
		num >>= 1;
		i--;
	}
	return (bits);
}

t_list	*populate_list_a(char **str)
{
	t_list	*list;
	t_list	*new_node;
	int		i;

	list = NULL;
	i = 1;
	while (str[i])
	{
		new_node = ft_lstnew(int_to_bits(ft_atoi(str[i])));
		if (!new_node)
		{
			dealloc(&list);
			return (NULL);
		}
		ft_lstadd_back(&list, new_node);
		i++;
	}
	return (list);
}

void	dealloc(t_list **list)
{
	t_list	*temp;

	while (*list)
	{
		temp = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = temp;
	}
}
