#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int ft_printf (const char*, ...);
int ft_is_specifier(char *s);
char    *ft_convert(int num_case)

#endif