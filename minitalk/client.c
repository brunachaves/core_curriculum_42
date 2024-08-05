/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:33:12 by brchaves          #+#    #+#             */
/*   Updated: 2024/08/05 13:31:25 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_received = 0;

void	acknowleged(int signum)
{
	(void)signum;
	g_received = 1;
}

void	*char_to_bits(char c, char *binary)
{
	int		i;

	i = 7;
	while (i >= 0)
	{
		binary[i] = (c % 2) + '0';
		c /= 2;
		i--;
	}
	binary[8] = '\0';
	return (binary);
}

void	handle_message(int pid, const char *str)
{
	int		i;
	int		j;
	char	binary[9];

	i = 0;
	signal(SIGUSR1, acknowleged);
	while (str[i])
	{
		char_to_bits(str[i], binary);
		j = 0;
		while (j < 8)
		{
			if (binary[j] == '1')
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j++;
			g_received = 0;
			while (!g_received)
				usleep(100);
		}
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
		return (1);
	}
	pid = ft_atoi(argv[1]);
	handle_message(pid, argv[2]);
	return (0);
}
