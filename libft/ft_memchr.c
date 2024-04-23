#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
    char *char_s;
    int i;

    i = 0;
    char_s = s;
    while (char_s[i] && i < n)
    {
        if (char_s[i] = c)
            return (s+i);
        i++;
    }
    return (NULL);
}