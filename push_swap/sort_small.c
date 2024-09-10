/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:41:10 by brchaves          #+#    #+#             */
/*   Updated: 2024/09/10 13:20:42 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_bubble_alg(t_stack **stack)
{
	t_stack	*current;
	int		temp;
	int		swapped;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		current = *stack;
		while (current && current->next)
		{
			if (current->value > current->next->value)
			{
				temp = current->value;
				current->value = current->next->value;
				current->next->value = temp;
				swapped = 1;
			}
			current = current->next;
		}
	}
}

void	sort_small(t_stack **stack)
{
	int	size;

	size = stack_size(*stack);
	if (!stack || !(*stack))
		return ;
	if (size <= 1)
		return ;
	if (size == 2)
	{
		if ((*stack)->value > (*stack)->next->value)
			swap_a(*stack);
	}
	else if (size == 3)
		sort_three(stack);
	else
		sort_bubble_alg(stack);
}
