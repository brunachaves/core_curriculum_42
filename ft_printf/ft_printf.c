#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    va_list ap;
    int count;
    int i;

    va_start(ap, format);
    count = 0;
    i = 0;
    while (format[i])
    {
        if (format[i] == '%' && ft_is_specifier(format[i + 1]))
        {
            count += ft_convert(ap, format[i + 1]);
            i += 2;
        }
        else
        {
            count += write(1, &format[i], 1);
            i++;
        }
    }

    va_end(ap);
    return (count);
}
