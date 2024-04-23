#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    int i;
    const char *ptr;

    i = 0;
    ptr = NULL;
    while (s[i])
    {
        if (s[i] == c)
            ptr = s + i;
        i++;
    }
    if (c == 0)
        return ((char *)(s + i));
    return ((char *)(ptr));
}