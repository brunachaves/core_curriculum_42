#include <ft_printf.h>

int ft_printf_char(int num)
{
    ft_putchar_fd(num, 1);
    return (1);
}

int ft_printf_str(char *str)
{
    ft_putstr_fd(str, 1);
    return (ft_strlen(str));
}

int ft_print_sign(char sign)
{
    ft_putchar_fd(sign, 1);
    return (1);
}