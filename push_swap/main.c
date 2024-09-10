/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:21:46 by brchaves          #+#    #+#             */
/*   Updated: 2024/09/10 13:18:11 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**create_array(char **argv, int argc)
{
	char	**array;
	int		i;

	array = malloc(sizeof(char *) * (argc - 1 + 1));
	if (!array)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		array[i - 1] = ft_strdup(argv[i]);
		if (!array[i - 1])
		{
			free_array(array);
			return (NULL);
		}
		i++;
	}
	array[argc - 1] = NULL;
	return (array);
}

int	main(int argc, char **argv)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	char	**array;

	a_stack = NULL;
	b_stack = NULL;
	array = NULL;
	if (argc <= 1 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	if (argc == 2)
		array = ft_split(argv[1], ' ');
	else if (argc > 2)
		array = create_array(argv, argc);
	if (!check_error(array))
	{
		a_stack = populate_stack_a(array);
		if (!is_sorted(a_stack))
			push_swap(&a_stack, &b_stack);
	}
	free_all(&a_stack, array);
	return (0);
}
