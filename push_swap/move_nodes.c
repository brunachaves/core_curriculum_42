/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:53:26 by brchaves          #+#    #+#             */
/*   Updated: 2024/09/06 12:28:08 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_cheapiest_up(t_stack **b_stack, t_stack *cheapiest_node)
{
	int 	cheap_position;
	int		cheap_above_median;

	cheap_position = cheapiest_node->position;
	cheap_above_median = cheapiest_node->above_median;
	while (cheap_position)
	{
		if(cheap_above_median)
			rotate_b(b_stack);
		else
			rotate_reverse_b(b_stack);
		cheap_position--;
	}
}

void	move_target_up(t_stack  **a_stack, t_stack *target_node)
{
	int		target_position;
	int		target_above_median;

	target_position = target_node->position;
	target_above_median = target_node->above_median;
	while (target_position)
	{
		if (target_above_median)
			rotate_a(a_stack);
		else
			rotate_reverse_a(a_stack);
		target_position--;
	}
}

void	move_both_up(t_stack  **a_stack, t_stack **b_stack, t_stack *cheapiest_node, t_stack *target_node)
{
	int		target_position;
	int		target_above_median;
	int 	cheap_position;
	int		cheap_above_median;

	cheap_position = cheapiest_node->position;
	cheap_above_median = cheapiest_node->above_median;
	target_position = target_node->position;
	target_above_median = target_node->above_median;
	
	while(cheap_position && target_position)
	{
		if (cheap_above_median && target_above_median)
			rotate_r(a_stack, b_stack);
		else if (!cheap_above_median && !target_above_median)
			rotate_reverse_r(a_stack, b_stack);
		cheap_position--;
		target_position--;
	}
}

void	move_nodes(t_stack  **a_stack, t_stack **b_stack, t_stack *cheapiest_node)
{
	t_stack	*target_node;

	target_node = cheapiest_node->target_node;
	if (cheapiest_node->above_median && target_node->above_median)
		move_both_up(a_stack, b_stack, cheapiest_node, target_node);
	else if (!cheapiest_node->above_median && !target_node->above_median)
		move_both_up(a_stack, b_stack, cheapiest_node, target_node);
	move_cheapiest_up(b_stack, cheapiest_node);
	move_target_up(a_stack, target_node);
	push_a(a_stack, b_stack);
}