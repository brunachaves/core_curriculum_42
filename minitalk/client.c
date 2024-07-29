/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:33:12 by brchaves          #+#    #+#             */
/*   Updated: 2024/07/17 11:59:38 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*char_to_bits(char c)
{
	char	*binary;
	int		i;

	i = 7;
	binary = (char *)malloc(sizeof(char) * 9);
	if (!binary)
		return (NULL);
	binary[8] = '\0';
	while (i >= 0)
	{
		binary[i] = (c % 2) + '0';
		c /= 2;
		i--;
	}
	return (binary);
}

void	handle_message(int pid, const char *str)
{
	int		i;
	int		j;
	char	*binary;

	i = 0;
	j = 0;
	while (str[i])
	{
		binary = char_to_bits(str[i]);
		if (!binary)
			return ;
		while (j < 8)
		{
			if (binary[j] == '1')
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			j++;
		}
		free (binary);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Error! This is how the program should be executed:\n");
		ft_printf("    ./client <PID NUMBER> <MESSAGE>\n");
		exit(-1);
	}
	pid = ft_atoi(argv[1]);
	handle_message(pid, argv[2]);
	return (0);
}
