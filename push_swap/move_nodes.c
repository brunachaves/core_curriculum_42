/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:53:26 by brchaves          #+#    #+#             */
/*   Updated: 2024/09/10 13:56:14 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_cheapest_up(t_stack **b_stack, t_stack *cheapest_node)
{
	int		cheap_position;
	int		cheap_above_median;

	cheap_position = cheapest_node->position;
	cheap_above_median = cheapest_node->above_median;
	while (cheap_position && *b_stack)
	{
		if (cheap_above_median)
			rotate_b(b_stack);
		else
			rotate_reverse_b(b_stack);
		cheap_position--;
	}
}

void	move_target_up(t_stack **a_stack, t_stack *target_node)
{
	int		target_position;
	int		target_above_median;

	target_position = target_node->position;
	target_above_median = target_node->above_median;
	while (target_position && *a_stack)
	{
		if (target_above_median)
			rotate_reverse_a(a_stack);
		else
			rotate_a(a_stack);
		target_position--;
	}
}

void	move_both_up(t_stack **a, t_stack **b, t_stack *ch_nd, t_stack *tg_nd)
{
	int		target_position;
	int		target_above_median;
	int		cheap_position;
	int		cheap_above_median;

	cheap_position = ch_nd->position;
	cheap_above_median = ch_nd->above_median;
	target_position = tg_nd->position;
	target_above_median = tg_nd->above_median;
	while (cheap_position && target_position)
	{
		if (cheap_above_median && target_above_median)
			rotate_r(a, b);
		else if (!cheap_above_median && !target_above_median)
			rotate_reverse_r(a, b);
		cheap_position--;
		target_position--;
	}
}

void	move_nodes(t_stack **a_stack, t_stack **b_stack, t_stack *cheap_node)
{
	t_stack	*target_node;

	target_node = cheap_node->target_node;
	if (cheap_node->above_median && target_node->above_median)
		move_both_up(a_stack, b_stack, cheap_node, target_node);
	else if (!cheap_node->above_median && !target_node->above_median)
		move_both_up(a_stack, b_stack, cheap_node, target_node);
	move_cheapest_up(b_stack, cheap_node);
	move_target_up(a_stack, target_node);
	push_a(a_stack, b_stack);
}
