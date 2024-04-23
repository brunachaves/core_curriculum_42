#include "libft.h"

int	ft_isalnum(int c)
{
	int	is_alpha;
	int	is_digit;

	is_alpha = ft_isalpha(c);
	is_digit = ft_isdigit(c);
	if (is_alpha || is_digit)
		return (1);
	return (0);
}
