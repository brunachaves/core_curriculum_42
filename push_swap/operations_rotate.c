/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:10:27 by brchaves          #+#    #+#             */
/*   Updated: 2024/07/30 13:58:09 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_lst(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		*stack = first->next;
		first->next = NULL;
		last = stack_find_last(*stack);
		last->next = first;
	}
}

void	rotate_a(t_stack **a_stack)
{
	rotate_lst(a_stack);
	ft_printf("ra\n");
}

void	rotate_b(t_stack **b_stack)
{
	rotate_lst(b_stack);
	ft_printf("rb\n");
}

void	rotate_r(t_stack **a_stack, t_stack **b_stack)
{
	rotate_lst(a_stack);
	rotate_lst(b_stack);
	ft_printf("rr\n");
}
