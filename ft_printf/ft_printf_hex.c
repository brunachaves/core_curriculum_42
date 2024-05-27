#include "ft_printf.h"

int ft_hexlen(unsigned int num)
{
    int len;

    len = 0;
    if (num == 0)
        return 1;
    while (num)
    {
        num /= 16;
        len++;
    }
    return len;
}


int ft_printf_lowx(unsigned int num)
{
    char *hexadecimal;
    int len;
    char *str;

    hexadecimal = "0123456789abcdef";
    len = ft_hexlen(num);
    str = = (char *)malloc(len + 1);
    if (!str)
        return 0;
    str[len] = '\0';
    len--;
    while (len > 0)
    {
        str[len] = hexadecimal[num % 16];
        num /= 16;
        len--;
    }
    ft_putstr_fd(str, 1);
    len = ft_strlen(str);
    free(str);
    return len;
}

int ft_printf_lowx(unsigned int num)
{
    char *hexadecimal;
    int len;
    char *str;

    hexadecimal = "0123456789ABCDEF";
    len = ft_hexlen(num);
    str = = (char *)malloc(len + 1);
    if (!str)
        return 0;
    str[len] = '\0';
    len--;
    while (len > 0)
    {
        str[len] = hexadecimal[num % 16];
        num /= 16;
        len--;
    }
    ft_putstr_fd(str, 1);
    len = ft_strlen(str);
    free(str);
    return len;
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