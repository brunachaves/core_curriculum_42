#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	limit_cpy_char;
	size_t	i;

	limit_cpy_char = size - 1;
	i = 0;
	while (src[i] && limit_cpy_char)
	{
		dest[i] = src[i];
		i++;
		limit_cpy_char--;
	}
	dest[i] = '\0';
	return (i);
}
