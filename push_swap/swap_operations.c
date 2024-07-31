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

void	swap_lst(t_list *lst)
{
	void	*aux;

	if (lst && lst->next)
	{
		aux = lst->content;
		lst->content = lst->next->content;
		lst->next->content = aux;
	}
}

void	swap_a(t_list *a_list)
{
	swap_lst(a_list);
	ft_printf("sa\n");
}

void	swap_b(t_list *b_list)
{
	swap_lst(b_list);
	ft_printf("sb\n");
}

void	swap_s(t_list *a_list, t_list *b_list)
{
	swap_lst(a_list);
	swap_lst(b_list);
	ft_printf("sb\n");
}
