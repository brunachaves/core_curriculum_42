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

void	rotate_lst(t_list **list)
{
	t_list	*first;
	t_list	*last;

	if (*list && (*list)->next)
	{
		first = *list;
		*list = first->next;
		first->next = NULL;
		last = ft_lstlast(*list);
		last->next = first;
	}
}

void	rotate_a(t_list **a_list)
{
	rotate_lst(a_list);
	ft_printf("ra\n");
}

void	rotate_b(t_list **b_list)
{
	rotate_lst(b_list);
	ft_printf("rb\n");
}

void	rotate_r(t_list **a_list, t_list **b_list)
{
	rotate_lst(a_list);
	rotate_lst(b_list);
	ft_printf("rr\n");
}
