/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:59:31 by brchaves          #+#    #+#             */
/*   Updated: 2024/09/10 13:43:50 by brchaves         ###   ########.fr       */
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
	int	size;

	median = stack_size(stack) / 2;
	size = stack_size(stack);
	while (stack)
	{
		stack->above_median = 0;
		if (size % 2 == 0)
		{
			if (stack->position < median)
				stack->above_median = 1;
		}
		else
		{
			if (stack->position <= median)
				stack->above_median = 1;
		}
		stack = stack->next;
	}
}

void	set_push_price(t_stack *a_stack, t_stack *b_stack)
{
	int	a_size;
	int	b_size;

	a_size = stack_size(a_stack);
	b_size = stack_size(b_stack);
	if (!a_stack || !b_stack)
		return ;
	while (b_stack)
	{
		b_stack->push_price = b_stack->position;
		if (!(b_stack->above_median))
			b_stack->push_price = b_size - b_stack->position;
		if (b_stack->target_node->above_median)
			b_stack->push_price += b_stack->target_node->position;
		else
			b_stack->push_price += a_size - b_stack->target_node->position;
		b_stack = b_stack->next;
	}
}

void	set_cheapest(t_stack *b_stack)
{
	long int	cheapest_price;
	t_stack		*aux_node;

	cheapest_price = LONG_MAX;
	aux_node = NULL;
	if (!b_stack)
		return ;
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
	if (aux_node)
		aux_node->cheapest = 1;
}

void	set_target_node(t_stack *a_stack, t_stack *b_stack, t_stack *tg_aux)
{
	t_stack		*current_a;
	long int	aux_value;
	int			cur_value;

	while (b_stack)
	{
		aux_value = LONG_MAX;
		tg_aux = NULL;
		current_a = a_stack;
		while (current_a)
		{
			cur_value = current_a->value;
			if (cur_value > b_stack->value && cur_value < aux_value)
			{
				aux_value = cur_value;
				tg_aux = current_a;
			}
			current_a = current_a->next;
		}
		if (!tg_aux)
			b_stack->target_node = get_smallest(a_stack);
		else
			b_stack->target_node = tg_aux;
		b_stack = b_stack->next;
	}
}
