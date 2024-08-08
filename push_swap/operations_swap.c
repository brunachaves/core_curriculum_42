/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:10:30 by brchaves          #+#    #+#             */
/*   Updated: 2024/07/30 13:55:24 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack *stack)
{
	int	aux;

	if (stack && stack->next)
	{
		aux = stack->value;
		stack->value = stack->next->value;
		stack->next->value = aux;
	}
}

void	swap_a(t_stack *a_list)
{
	swap_stack(a_list);
	ft_printf("sa\n");
}

void	swap_b(t_stack *b_list)
{
	swap_stack(b_list);
	ft_printf("sb\n");
}

void	swap_s(t_stack *a_list, t_stack *b_list)
{
	swap_stack(a_list);
	swap_stack(b_list);
	ft_printf("sb\n");
}
