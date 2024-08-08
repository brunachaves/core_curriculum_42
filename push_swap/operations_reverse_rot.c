/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:10:25 by brchaves          #+#    #+#             */
/*   Updated: 2024/07/30 13:30:16 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_reverse_lst(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;
	t_stack	*aux;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = stack_find_last(*stack);
	aux = *stack;
	while (aux->next)
	{
		last = aux;
		aux = aux->next;
	}
	last->next = NULL;
	stack_add_up(stack, temp);
}

void	rotate_reverse_a(t_stack **a_stack)
{
	rotate_reverse_lst(a_stack);
	ft_printf("rra\n");
}

void	rotate_reverse_b(t_stack **b_stack)
{
	rotate_reverse_lst(b_stack);
	ft_printf("rrb\n");
}

void	rotate_reverse_r(t_stack **a_stack, t_stack **b_stack)
{
	rotate_reverse_lst(a_stack);
	rotate_reverse_lst(b_stack);
	ft_printf("rrr\n");
}
