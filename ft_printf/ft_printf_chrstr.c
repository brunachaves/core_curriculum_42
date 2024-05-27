#include "ft_printf.h"

int ft_printf_c(int num)
{
    char c;

    c = num;
    ft_putchar_fd(c, 1);
    return (1);
}

int ft_printf_s(char *str)
{
    ft_putstr_fd(str, 1);
    return (ft_strlen(str));
}

int ft_printf_sign(char sign)
{
    ft_putchar_fd(sign, 1);
    return (1);
}