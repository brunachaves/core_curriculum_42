/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:21:46 by brchaves          #+#    #+#             */
/*   Updated: 2024/07/24 14:11:52 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a_list;

	if (argc > 1)
	{
		check_error(argv);
		a_list = populate_list(argv);
	}
	free(a_list);
	return(0);	
}