#include "libft.h"

int	ft_isupper(int c)
{
	if (c > 64 && c < 91)
		return (1);
	return (0);
}

int	ft_tolower(int c)
{
	int	is_upper;

	is_upper = ft_isupper(c);
	if (is_upper)
		return (c + 32);
	return (c);
}
