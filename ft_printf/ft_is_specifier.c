#include <ft_printf.h>

int ft_is_specifier(char *s)
{
    int num_case;

    num_case = 0;
    if (*s == '%')
    {
        s++;
        if (*s == 'c')
            num_case = 1;
        else if (*s == 's')
            num_case = 2;
        else if (*s == 'p')
            num_case = 3;
        else if (*s == 'd')
            num_case = 4;
        else if (*s == 'i')
            num_case = 5;
        else if (*s == 'u')
            num_case = 6;
        else if (*s == 'x')
            num_case = 7;
        else if (*s == 'X')
            num_case = 8;
        else if (*s == '%')
            num_case = 9;
    }
    return (num_case);
}

char    *ft_convert(va_list ap, int num_case)
{
    char *conv_str;

    if (num_case == 1)
        conv_str = ft_strdup((char *)va_arg(ap, char));
    else if (num_case == 2)
        conv_str = ft_strdup(va_arg(ap, char *));
    else if (num_case == 3)
        conv_str = 
    else if (num_case == 4)
        conv_str = ft_itoa(va_arg(ap, int));
    else if (num_case == 5)

    else if (num_case == 6)

    else if (num_case == 7)

    else if (num_case == 8)

    else if (num_case == 9)
        conv_str = ft_strdup('%')
    return (conv_str);
}