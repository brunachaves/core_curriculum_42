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

void	swap_b(t_list *b_list, int simultaneous)
{
	void	*aux1;
	void	*aux2;

	if (b_list && b_list->next)
	{
		aux1 = b_list->next->content;
		aux2 = b_list->content;
		b_list->content = aux1;
		b_list->next->content = aux2;
	}
	if (simultaneous == 0)
		ft_printf("sb\n");
}

void	push_b(t_list **a_list, t_list **b_list)
{
	t_list	*aux;

	if (a_list && *a_list)
	{
		aux = *a_list;
		*a_list = aux->next;
		ft_lstadd_front(b_list, aux);
		ft_printf("pa\n");
	}
}

void	rotate_b(t_list **b_list, int simultaneous)
{
	t_list	*first;
	t_list	*last;

	if (*b_list && (*b_list)->next)
	{
		first = *b_list;
		*b_list = first->next;
		last = ft_lstlast(*b_list);
		last->next = first;
		first->next = NULL;
	}
	if (simultaneous == 0)
		ft_printf("rb\n");
}

void	rotate_reverse_b(t_list **b_list, int simultaneous)
{
	t_list	*temp;
	t_list	*last;
	t_list	*aux;

	if (!b_list || !*b_list || !(*b_list)->next)
		return ;
	temp = ft_lstlast(*b_list);
	aux = *b_list;
	while (aux->next)
	{
		last = aux;
		aux = aux->next;
	}
	last->next = NULL;
	ft_lstadd_front(b_list, temp);
	if (simultaneous == 0)
		ft_printf("rrb\n");
}
