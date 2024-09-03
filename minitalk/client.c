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
	while (str[i++])
	{
		char_to_bits(str[i], binary);
		j = 0;
		while (j < 8)
		{
			g_ack_received = 0;
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
			while (g_ack_received)
				pause();
			j++;
		}
	}
}

void	handle_error(char **argv)
{
	int	pid;
	int	i;

	pid = ft_atoi(argv[1]);
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

int	main(int argc, char **argv)
{
	int		pid;

	if (argc != 3)
	{
		ft_printf("Error! This is how the program should be executed:\n");
		ft_printf("    ./client <PID NUMBER> <MESSAGE>\n");
		return (1);
	}
	signal(SIGUSR1, ack_handler);
	handle_error(argv);
	pid = ft_atoi(argv[1]);
	handle_message(pid, argv[2]);
	return (0);
}
