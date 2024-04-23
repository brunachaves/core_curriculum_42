#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    int i;
    char *c_dest;
    char *c_src;

    i = 0;
    c_dest = dest;
    c_src = src;
    while (i < n)
    {
        c_dest[i] = c_src[i];
        i++;
    }
    return (dest);
}