/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:35:47 by brchaves          #+#    #+#             */
/*   Updated: 2024/09/10 11:20:15 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ack_received = 0;

void	ack_handler(int signum)
{
	(void)signum;
	g_ack_received = 1;
}

void	*char_to_bits(char c, char *binary)
{
	int	i;

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
	while (str[i])
	{
		char_to_bits(str[i], binary);
		j = 0;
		while (j < 8)
		{
			g_ack_received = 0;
			send_signal(binary, j, pid);
			while (!g_ack_received)
				pause();
			j++;
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
	check_error_arg(argv, pid);
	signal(SIGUSR1, ack_handler);
	handle_message(pid, argv[2]);
	return (0);
}
