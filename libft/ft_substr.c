#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *str_result;
    size_t i_strlcpy;

    str_result = (char *)malloc(len * (sizeof(char)) + 1);
    i_strlcpy = ft_strlcpy(str_result, (s + start), (len + 1));
    str_result[len] = '\0';
    return (str_result);
}
