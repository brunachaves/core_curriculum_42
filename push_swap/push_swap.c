/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:21:46 by brchaves          #+#    #+#             */
/*   Updated: 2024/07/30 13:57:50 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a_list;

	a_list = (t_list *)malloc(sizeof(t_list));
	if (!a_list)
		return (1);
	if (argc > 1)
	{
		check_error(argv);
		a_list = populate_list_a(argv);
		sort_list(a_list);
	}
	dealloc(&a_list);
	return (0);
}
