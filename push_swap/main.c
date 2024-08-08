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
	t_stack	*a_stack;
	t_stack	*b_stack;
	char 	**array;

	a_stack = NULL;
	b_stack = NULL;
	if (argc == 1 || argc > 2 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
	{
		array = ft_split(argv[1], ' ');
		check_error(array);
		a_stack = populate_stack_a(array);
	}
	if(array)
		free_array(array);
	free_stack(&a_stack);
	free_stack(&b_stack);
	return (0);
}
