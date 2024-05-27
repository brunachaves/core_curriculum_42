#include <ft_printf.h>

int ft_hexlen(unsigned int num)
{
    char    *hexadecimal;
    int     len;
    int     remainder;

    hexadecimal = "0123456789abcdef";
    len = 0;
    remainder = num;
    if (num < 16)
        return (1);
    else
    {
        while (num)
        {
            remainder = num % 16;
            num = num / 16;
            len++;
        }
        return (len);
    }
}

int ft_printf_lowx(unsigned int num)
{
    char    *hexadecimal;
    char    *str;
    int     remainder;
    int     len;

    hexadecimal = "0123456789abcdef";
    len = ft_hexlen(num);
    str = (char *)malloc(len);
    if (!str)
        return (0);
    if (num < 16)
        write (1, hexadecimal + num, 1);
        return (1);
    while(num)
    {
        remainder = num % 16;
        str[len - 1] = remainder;
        num /= 16;
        len--;
    }
    ft_putstr_fd (str, 1);
    len = ft_strlen(str);
    free (str);
    return (len);
}

int ft_printf_uppx(unsigned int num)
{
    char    *hexadecimal;
    char    *str;
    int     remainder;
    int     len;

    hexadecimal = "0123456789ABCDEF";
    len = ft_hexlen(num);
    str = (char *)malloc(len);
    if (!str)
        return (0);
    if (num < 16)
        write (1, hexadecimal + num, 1);
        return (1);
    while(num)
    {
        remainder = num % 16;
        str[len - 1] = remainder;
        num /= 16;
        len--;
    }
    ft_putstr_fd (str, 1);
    len = ft_strlen(str);
    free (str);
    return (len);
}

int ft_printf_p(void *ptr)
{
    unsigned int hex;
    int count;

    hex = (unsigned int)ptr;
    count  = 0;
    count = ft_printf_lowx(hex);
    return (count);
}