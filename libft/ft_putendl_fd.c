#include "libft.h"

void    ft_putendl_fd(char *s, int fd)
{
    char new_line;

    new_line = '\n';
    ft_putstr_fd(s, fd);
    ft_putchar_fd(new_line, fd);
}