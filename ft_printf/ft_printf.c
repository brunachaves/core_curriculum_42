#include <ft_printf.h>

int ft_printf(const char *s, ...)
{
    va_list ap;
    int i;
    int total_len;
    char *buffer;
    char *full_str;

    va_start(ap, s);
    i = 0;
    while (s[i])
    {
        if (s[i] == '%')
        {
            if (ft_is_specifier(s + i))
            {
                buffer = ft_convert(ft_is_specifier(s + i));
                full_str = ft_strjoin(full_str, buffer);
                free (buffer);
                i += 2;
            }
            full_str = ft_strjoin(full_str, '%');
            i++;
        }
        buffer = ft_strtrim(s + i, '%');
        full_str = ft_strjoin(full_str, buffer);
        i += ft_strlen(buffer);
        free (buffer);
    }
    total_len = ft_strlen(full_str);
    ft_putstr_fd(full_str, 1);
    free (full_str);
    va_end(ap);
    return (total_len);
}
