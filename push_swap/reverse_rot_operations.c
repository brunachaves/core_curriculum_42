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

void	rotate_reverse_lst(t_list **list)
{
	t_list	*temp;
	t_list	*last;
	t_list	*aux;

	if (!list || !*list || !(*list)->next)
		return ;
	temp = ft_lstlast(*list);
	aux = *list;
	while (aux->next)
	{
		last = aux;
		aux = aux->next;
	}
	last->next = NULL;
	ft_lstadd_front(list, temp);
}

void	rotate_reverse_a(t_list **a_list)
{
	rotate_reverse_lst(a_list);
	ft_printf("rra\n");
}

void	rotate_reverse_b(t_list **b_list)
{
	rotate_reverse_lst(b_list);
	ft_printf("rrb\n");
}

void	rotate_reverse_r(t_list **a_list, t_list **b_list)
{
	rotate_reverse_lst(a_list);
	rotate_reverse_lst(b_list);
	ft_printf("rrr\n");
}
