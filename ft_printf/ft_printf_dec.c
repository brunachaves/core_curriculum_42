#include "ft_printf.h"

int ft_printf_d(int num)
{
    ft_putnbr_fd(num, 1);
    return (ft_nbrlen(num));
}

int ft_printf_u(unsigned int num)
{
    int count;

    count = ft_printf_d(num);
    return (count);
}