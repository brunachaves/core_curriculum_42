#include "libft.h"

int ft_is_space(int n)
{
    if ((n > 6 && n < 14) || n == 32)
        return (1);
    return (0);
}

int ft_atoi(const char *str)
{
    int signal;
    int result;

    signal = 1;
    result = 0;
    while (ft_is_space(*str))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            signal *= -1;
        str++;
    }  
    while ((*str > 47 && *str < 58))
    {
        result = result * 10 + (*str - 48);
        str++;
    }
    return (signal * result);
}
