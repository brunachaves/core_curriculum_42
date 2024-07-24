/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:20:07 by brchaves          #+#    #+#             */
/*   Updated: 2024/05/21 12:32:37 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;
	t_list	*temp;

	aux = *lst;
	while (aux)
	{
		temp = aux -> next;
		(*del)(aux -> content);
		free (aux);
		aux = temp;
	}
	*lst = NULL;
}
