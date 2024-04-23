#include "libft.h"

unsigned int	ft_strlen(const char *str)
{
	unsigned int	counter;

	counter = 0;
	while (*str)
	{
		counter++;
		str++;
	}
	return (counter);
}
