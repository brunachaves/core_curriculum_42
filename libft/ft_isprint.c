#include "libft.h"

int	ft_isprint(int c)
{
	if ((c >= 0 && c < 32) || c == 127)
		return (0);
	return (1);
}
