#include <ft_printf.h>

int ft_printf(const char *format, ...)
{
    va_list ap;
    int     count;
    int     i;

    va_start(ap, format);
    count = 0;
    i = 0;
    while (format[i])
    {
        if (format[i] == '%')
        {
            if (ft_is_specifier(format[i + 1]))
                count += ft_convert(ap, ft_is_specifier(format[i + 1]));
        }
        count += write(1, format + i, 1);
        i++;
    }
    count += write(1, '\0', 1);
    va_end(ap);
    return (count);
}
