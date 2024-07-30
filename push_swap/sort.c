/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:10:19 by brchaves          #+#    #+#             */
/*   Updated: 2024/07/30 13:59:48 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_list(t_list *a_list)
{
	int			i;
	int			j;
	int			size_list;
	t_list		*b_list;
	char		*buffer;

	i = 31;
	size_list = ft_lstsize(a_list);
	b_list = (t_list *)malloc(sizeof(t_list));
	if (!b_list)
		return ;
	while (i)
	{
		j = 0;
		while (a_list && j < size_list)
		{
			buffer = (char *)malloc(sizeof(char) * 33);
			buffer = a_list->content;
			if (buffer[i] == '0')
				push_b(&a_list, &b_list);
			else
				rotate_a(&a_list, 0);
			free(buffer);
			j++;
		}
		while (b_list)
		{
			push_a(&a_list, &b_list);
			b_list = b_list->next;
		}
		i++;
	}
	if (i == 0)
	{
		while (a_list && j < size_list)
		{
			buffer = a_list->content;
			if (buffer[i] == '1')
				push_b(&a_list, &b_list);
			else
				rotate_a(&a_list, 0);
			free(buffer);
			j++;
		}
		while (b_list)
		{
			push_a(&a_list, &b_list);
			b_list = b_list->next;
		}
	}
}
