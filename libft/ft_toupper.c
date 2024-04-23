#include "libft.h"

int	ft_islower(int c)
{
	if (c > 96 && c < 123)
		return (1);
	return (0);
}

int	ft_toupper(int c)
{
	int	is_lower;

	is_lower = ft_islower(c);
	if (is_lower)
		return (c - 32);
	return (c);
}
