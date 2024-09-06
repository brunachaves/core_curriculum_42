/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:59:50 by brchaves          #+#    #+#             */
/*   Updated: 2024/09/06 10:59:51 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*aux;

	if (b_stack && *b_stack)
	{
		aux = *b_stack;
		*b_stack = aux->next;
		aux->next = NULL;
		stack_add_up(a_stack, aux);
		ft_printf("pa\n");
	}
}

void	push_b(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*aux;

	if (a_stack && *a_stack)
	{
		aux = *a_stack;
		*a_stack = aux->next;
		aux->next = NULL;
		stack_add_up(b_stack, aux);
		ft_printf("pb\n");
	}
}
