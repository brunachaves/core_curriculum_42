/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:59:20 by brchaves          #+#    #+#             */
/*   Updated: 2024/09/06 12:26:20 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
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
	set_above_median(a_stack);
	set_above_median(b_stack);
	set_push_price(a_stack, b_stack);
	set_cheapest(b_stack);
	set_target_node(a_stack, b_stack);
}

void	sort_three(t_stack **stack)
{
	t_stack	*biggest;

	biggest = get_biggest(*stack);
	if ((*stack)->value == biggest->value)
		rotate_a(stack);
	else if ((*stack)->next->value == biggest->value)
		rotate_reverse_a(stack);
	if ((*stack)->value > (*stack)->next->value)
		swap_a(*stack);
}

void	put_ascendent_order(t_stack **a_stack)
{
	t_stack *smallest_node;
	int		smallest_above_median;
	
	smallest_node = get_smallest(*a_stack);
	smallest_above_median = smallest_node->above_median;
	while (*a_stack != smallest_node)
	{
		if (smallest_above_median)
			rotate_a(a_stack);
		else
			rotate_reverse_a(a_stack);
		*a_stack = (*a_stack)->next;	
	}
}

void	push_swap(t_stack **a_stack, t_stack **b_stack)
{
	int		size_a;
	t_stack	*cheapiest_node;

	size_a = stack_size(*a_stack);
	while (size_a > 3)
	{
		push_b(a_stack, b_stack);
		size_a--;
	}
	sort_three(a_stack);
	while (*b_stack)
	{
		set_all_attributes(*a_stack, *b_stack);
		cheapiest_node = get_cheapiest(*b_stack);
		move_nodes(a_stack, b_stack, cheapiest_node);
	}
	put_ascendent_order(a_stack);
	free_stack(b_stack);
}
