#include "libft.h"
#include <unistd.h>

void    ft_putstr_fd(char *s, int fd)
{
    int i;

    int = 0;
    while (s[i])
    {
        write (fd, s + i, 1);
        i++;
    }
}