/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:39:45 by brchaves          #+#    #+#             */
/*   Updated: 2024/07/24 14:10:54 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	is_integer(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int    check_is_num(char **array)
{
    int i;
    int	j;

	i = 1;
	while (array[i])
	{
		j = 0;
        if(array[i][j] == '-')
            j++;
		while (array[i][j])
		{
			if (!is_integer(array[i][j]))
				return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int    check_is_int(char **array)
{
    int i;
    int j;
    long int num;

    i = 1;
    num = 0;
    while (array[i])
	{
		num = ft_atoi(array[i]);
        if (num < INT_MIN || num > INT_MAX)
			return (0);
        i++;
        num = 0;
    }
    return (1);
}

int    check_duplicates(char **array)
{
    int i;
    int j;
    int num1;
    int num2;
    
    i = 2;
    while (array[i])
	{
        num1 = ft_atoi(array[i]);
        j = i - 1;
        while(array[j] && j)
        {
            num2 = ft_atoi(array[j]);
            if (num1 ==  num2)
                return (1);
            j--;            
        }
        i++;        
    }
    return (0);
    
}

void	check_error(char **array)
{
    if(!check_is_num(array))
    {
        ft_printf("Error\n");
        exit (-1);
    }
    else if(!check_is_int(array))
    {
        ft_printf("Error\n");
        exit (-1);
    }
	else if(check_duplicates(array))
    {
        ft_printf("Error\n");
        exit (-1);
    }
}