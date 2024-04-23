#include "libft.h"

void    *ft_memset(void *s, int c, size_t n)
{
    size_t i;
    unsigned char *p;

    i = 0;
    p = s;
    while (i < n)
    {
        p[i] = c;
        i++;
    }
    return (s);
}