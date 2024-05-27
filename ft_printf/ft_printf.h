#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int ft_printf (const char *format, ...);
int ft_is_specifier(char c);
int ft_convert(va_list ap, char specifier);
int ft_printf_c(int num);
int ft_printf_s(char *str);
int ft_printf_p(void *);
int ft_printf_d(int num);
/* int ft_printf_i(int num); */
int ft_printf_u(int num);
int ft_printf_lowx(unsigned int num);
int ft_printf_uppx(unsigned int num);
int ft_print_sign(char sign);
int ft_hexlen(unsigned int num);

#endif