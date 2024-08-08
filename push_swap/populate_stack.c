/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:10:22 by brchaves          #+#    #+#             */
/*   Updated: 2024/07/30 13:52:58 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_stack	*populate_stack_a(char **array)
{
	int		i;
	int		num;
	t_stack	*stack;

	if(!array)
		return (NULL);
	i = 0;
	stack = (t_stack *)malloc(sizeof(t_stack));
	if(!stack)
		return (NULL);
	while(array[i])
	{
		num = ft_atoi(array[i]);
		stack_append(&stack, num);
		i++;
	}
	return(stack);	
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;
    t_stack *current;

    if(!stack)
        return ;
    current = *stack;
	while (*stack)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
    *stack = NULL;
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array || !(*array))
		return ;
	while (array[i])
    {
		free(array[i]);
        i++;
    }
    free(array[i]);
}

