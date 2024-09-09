/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:21:46 by brchaves          #+#    #+#             */
/*   Updated: 2024/09/06 12:23:56 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	char	**array;

	a_stack = NULL;
	b_stack = NULL;
	array = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
		array = ft_split(argv[1], ' ');
	else if (argc > 2)
		array = argv + 1;
	check_error(array);
	a_stack = populate_stack_a(array);
	if (!is_sorted(a_stack))
		push_swap(&a_stack, &b_stack);
	if (argc == 2)
		free_array(array);
	free_stack(&a_stack);
	return (0);
}
