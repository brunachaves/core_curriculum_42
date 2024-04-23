#include "libft.h"

void ft_strcpy(char *dest, char *src)
{
    int i;

    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

char    *ft_strdup(const char *src)
{
    char    *dest;
    size_t size;

    size = ft_strlen(src) + 1;
    dest = (char *)malloc(sizeof(char) * size);
    ft_strcpy(dest, src);
    return (dest);
}