#include "minitalk.h"

void	check_error_arg(char **argv, int pid)
{
	int	i;

	i = 0;
	if (!argv[2][0])
	{
		ft_printf("You should enter a non-empty text as second argument.\n");
		exit (1);
	}
	if (pid <= 0)
	{
		ft_printf("Check your given PID, please.\n");
		exit (1);
	}
	while (argv[1][i])
	{
		if (!ft_strchr("0123456789", argv[1][i]))
		{
			ft_printf("Check your given PID, please.\n");
			exit (1);
		}
		i++;
	}
}

void	check_error_signal(char *binary, int j, int pid)
{
	if (binary[j] == '1')
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_printf("Error sending SIGUSR1");
			exit(1);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_printf("Error sending SIGUSR2");
			exit(1);
		}
	}
}
