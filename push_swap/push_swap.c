/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:59:20 by brchaves          #+#    #+#             */
/*   Updated: 2024/09/10 13:47:18 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	unsigned int	size;

	size = stack_size(stack);
	if (size <= 1)
		return (1);
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	set_all_attributes(t_stack *a_stack, t_stack *b_stack)
{
	set_position(a_stack);
	set_position(b_stack);
	set_target_node(a_stack, b_stack);
	set_above_median(a_stack);
	set_above_median(b_stack);
	set_push_price(a_stack, b_stack);
	set_cheapest(b_stack);
}

void	push_swap(t_stack **a_stack, t_stack **b_stack)
{
	int		size_a;
	t_stack	*cheapest_node;

	size_a = stack_size(*a_stack);
	if (size_a <= 3)
		sort_small(a_stack);
	else
	{
		while (size_a > 3)
		{
			push_b(a_stack, b_stack);
			size_a--;
		}
		sort_three(a_stack);
		while (*b_stack)
		{
			set_all_attributes(*a_stack, *b_stack);
			cheapest_node = get_cheapest(*b_stack);
			move_nodes(a_stack, b_stack, cheapest_node);
		}
		put_ascendent_order(a_stack);
		free_stack(b_stack);
	}
}
