/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:49:47 by brchaves          #+#    #+#             */
/*   Updated: 2024/09/10 13:54:38 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_biggest(t_stack *stack)
{
	t_stack	*biggest;
	int		first;
	int		second;
	int		third;

	if (!stack || !stack->next || !stack->next->next)
		return (NULL);
	first = stack->value;
	second = stack->next->value;
	third = stack->next->next->value;
	if (first > second && first > third)
		biggest = stack;
	else if (second > first && second > third)
		biggest = stack->next;
	else
		biggest = stack->next->next;
	return (biggest);
}

t_stack	*get_smallest(t_stack *stack)
{
	t_stack		*smallest_node;
	long int	smallest_value;

	smallest_value = LONG_MAX;
	smallest_node = NULL;
	while (stack)
	{
		if (stack->value < smallest_value)
		{
			smallest_value = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

t_stack	*get_cheapest(t_stack *stack)
{
	t_stack	*cheapest_node;

	cheapest_node = NULL;
	while (stack)
	{
		if (stack->cheapest)
		{
			cheapest_node = stack;
			break ;
		}
		stack = stack->next;
	}
	return (cheapest_node);
}

void	put_ascendent_order(t_stack **a_stack)
{
	t_stack	*smallest_node;
	int		smallest_above_median;

	smallest_node = get_smallest(*a_stack);
	smallest_above_median = smallest_node->above_median;
	if (!smallest_node)
		return ;
	while (*a_stack != smallest_node)
	{
		if (smallest_above_median)
			rotate_a(a_stack);
		else
			rotate_reverse_a(a_stack);
	}
}
