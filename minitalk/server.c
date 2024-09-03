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
	write(1, &result, 1);
}

void	bytes_builder(char c, pid_t client_pid)
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
	kill(client_pid, SIGUSR1);
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	pid_t	client_pid;

	(void)context;
	client_pid = info->si_pid;
	if (signum == SIGUSR1)
		bytes_builder('1', client_pid);
	else if (signum == SIGUSR2)
		bytes_builder('0', client_pid);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	ft_printf("Hi there! Server initialized. The PID is: %d\n", pid);
	sa.sa_sigaction = &signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
