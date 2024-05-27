#include <ft_printf.h>

int ft_printf_d(int num)
{
    ft_putnbr_fd(num, 1);
    return (ft_nbrlen(num));
}

/* int ft_printf_i(int num)
{
    
} */

int ft_printf_u(int num)
{
    unsigned int result;
    int count;

    result = (unsigned int)num;
    count = ft_printf_d(result);
    return (count);
}