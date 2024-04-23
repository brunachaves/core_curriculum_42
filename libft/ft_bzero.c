#include "libft.h"

void    ft_bzero(void *s, size_t n)
{
    char null_char;

    null_char = '\0';
    ft_memset(s, null_char, n);
}