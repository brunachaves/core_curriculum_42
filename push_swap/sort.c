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

void	sort_three_a(t_list **a_list)
{
	int first;
	int middle;
	int last;

	first = ft_atoi((*a_list)->content);
	middle = ft_atoi((*a_list)->next->content);
	last = ft_atoi((*a_list)->next->next->content);
	if (first < middle && first < last)
	{
		if (last < middle)
		{
			rotate_a(a_list);
			swap_a(*a_list);
			rotate_reverse_a(a_list);
		}
	}	
	else if (middle < first && middle < last)
	{
		if (first < last)
			swap_a(*a_list);
		else
		{
			rotate_reverse_a(a_list);
			rotate_reverse_a(a_list);
		}
	}
	else if (last < first && last < middle)
	{
		if(first < middle)
			rotate_reverse_a(a_list);
		else
		{
			swap_a(*a_list);
			rotate_reverse_a(a_list);
		}
	}
}

void	sort_small(t_list **a_list, t_list **b_list)
{
	int size_a;
	int num1;
	int num2;
	int num3;
	int	rot_counter;

	size_a = ft_lstsize(*a_list);
	rot_counter = 0;
	while (size_a > 3)
	{
		push_b(a_list, b_list);
		size_a--;;
	}
	sort_three_a(a_list);
	while(*b_list)
	{
		num1 = ft_atoi((*a_list)->content);
		num2 = ft_atoi((ft_lstlast(*a_list))->content);
		num3 = ft_atoi((*b_list)->content);
		if(num3 < num1)
			push_a(a_list, b_list);
		else if (num3 > num2)
		{
			push_a(a_list, b_list);
			rotate_a(a_list);
		}
		else
		{
			while(num3 > num1)
			{
				rot_counter++;
				rotate_a(a_list);
				num1 = ft_atoi((*a_list)->content);
			}
			push_a(a_list, b_list);
			while (rot_counter--)
				rotate_reverse_a(a_list);
		}
	}
}

int	is_list_sorted(t_list *a_list)
{
	int num1;
	int num2;

	while (a_list && a_list->next)
	{
		num1 = ft_atoi(a_list->content);
		num2 = ft_atoi(a_list->next->content);
		if (num1 > num2)
			return (0);
		a_list = a_list->next;
	}
	return (1);
}

void	sort_list(t_list **a_list)
{
	int			i;
	int			j;
	int			size_list;
	t_list		*b_list;
	char		*buffer;

	i = 31;
	size_list = ft_lstsize(*a_list);
	if (size_list <= 1 || is_list_sorted(*a_list))
		return ;
	b_list = NULL;
	if(size_list <= 10)
	{
		sort_small(a_list, &b_list);
		return ;
	}
	while (i >= 1 && !(is_list_sorted(*a_list)))
	{
		j = 0;
		while ((*a_list) && j < size_list && !(is_list_sorted(*a_list)))
		{
			buffer = (*a_list)->content;
			if (buffer[i] == '0')
				push_b(a_list, &b_list);
			else
				rotate_a(a_list);
			j++;
		}
		while (b_list)
			push_a(a_list, &b_list);
		i--;
	}
	while(!is_list_sorted(*a_list))
	{
		j = 0;
		while ((*a_list) && j < size_list && !(is_list_sorted(*a_list)))
		{
			buffer = (*a_list)->content;
			if (buffer[i] == '1')
				push_b(a_list, &b_list);
			else
				rotate_a(a_list);
			j++;
		}
		while (b_list)
			push_a(a_list, &b_list);
	}
}
