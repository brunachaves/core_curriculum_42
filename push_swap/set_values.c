/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:59:31 by brchaves          #+#    #+#             */
/*   Updated: 2024/09/06 12:29:02 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_position(t_stack *stack)
{
	int	position;

	position = 0;
	while (stack)
	{
		stack->position = position;
		position++;
		stack = stack->next;
	}
}

void	set_above_median(t_stack *stack)
{
	int	median;

	median = stack_size(stack) / 2;
	while (stack)
	{
		if (stack->position <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
	}
}

void	set_push_price(t_stack *a_stack, t_stack *b_stack)
{
	int	a_size;
	int	b_size;

	a_size = stack_size(a_stack);
	b_size = stack_size(b_stack);
	while (b_stack)
	{
		b_stack->push_price = b_stack->position;
		if (!(b_stack->above_median))
			b_stack->push_price = b_size - (b_stack->position);
		if (b_stack->target_node->above_median)
			b_stack->push_price += b_stack->target_node->position;
		else
			b_stack->push_price += a_size - (b_stack->target_node->position);
		b_stack = b_stack->next;
	}
}

void	set_cheapest(t_stack *b_stack)
{
	long int	cheapest_price;
	t_stack		*aux_node;

	if (!b_stack)
		return ;
	cheapest_price = LONG_MAX;
	while (b_stack)
	{
		b_stack->cheapest = 0;
		if (b_stack->push_price < cheapest_price)
		{
			cheapest_price = b_stack->push_price;
			aux_node = b_stack;
		}
		b_stack = b_stack->next;
	}
	aux_node->cheapest = 1;
}

void	set_target_node(t_stack *a_stack, t_stack *b_stack)
{
	t_stack		*current_a;
	t_stack		*target_node;
	long int	aux_value;
	int			cur_value;

	while (b_stack)
	{
		aux_value = LONG_MAX;
		current_a = a_stack;
		while (current_a)
		{
			cur_value = current_a->value;
			if (cur_value > b_stack->value && cur_value < aux_value)
			{
				aux_value = cur_value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == aux_value)
			b_stack->target_node = get_smallest(a_stack);
		else
			b_stack->target_node = target_node;
		b_stack = b_stack->next;
	}
}
