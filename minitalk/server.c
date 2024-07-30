/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:26:35 by brchaves          #+#    #+#             */
/*   Updated: 2024/07/30 11:38:04 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bytes_to_char(const char *str)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (i < 8)
	{
		result = result * 2 + (str[i] - '0');
		i++;
	}
	ft_printf("%c", result);
}

void	bytes_builder(char c)
{
	static int	i = 0;
	static char	str[9];

	str[i] = c;
	i++;
	if (i == 8)
	{
		str[i] = '\0';
		bytes_to_char(str);
		i = 0;
	}
}

void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
		bytes_builder('1');
	else if (signum == SIGUSR2)
		bytes_builder('0');
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	pid = getpid();
	ft_printf("Hi there! Server initialized. The PID is: %d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
