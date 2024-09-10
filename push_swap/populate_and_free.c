/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_and_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:59:37 by brchaves          #+#    #+#             */
/*   Updated: 2024/09/10 12:15:58 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*populate_stack_a(char **array)
{
	int		i;
	int		num;
	t_stack	*stack;

	stack = NULL;
	if (!array)
		return (NULL);
	i = 0;
	while (array[i])
	{
		num = ft_atoi(array[i]);
		stack_append(&stack, num);
		i++;
	}
	return (stack);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_all(t_stack **stack, char **array)
{
	if (array)
		free_array(array);
	if (stack)
		free_stack(stack);
}
