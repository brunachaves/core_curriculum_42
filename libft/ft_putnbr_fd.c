#include "libft.h"
#include <unistd.h>

int ft_digits(int nb)
{
    int digits;
    int aux_nb;

    aux_nb = nb;
    digits = 0;
    if (nb == 0)
        return(1);
    while(aux_nb)
    {
        aux_nb /= 10;
        digits++;
    }
    return (digits);
}

int ft_power(int digits)
{
    int power;
    int aux_dig;

    power = 1;
    aux_dig = digits;
    if (aux_dig ==  1)
        return (1);
    while (aux_dig > 1)
    {
        power *= 10;
        aux_dig--;
    }
    return (power);
}

void    ft_putnbr_fd(int n, int fd)
{
    char    c;
    int power;
    int digits;

    digits = ft_digits(nb);
    power = ft_power(digits);
    if (nb == -2147483648)
            write(fd, "-2147483648", 11);
    else if (nb < 0)
    {
        write(fd, "-", 1);
        nb *= -1;
    }
    if (nb >= 0)
    {
        while(digits)
        {
            c = nb / power + '0';
            write(fd, &c, 1);
            nb %= power;
            power /= 10;
            digits--;
        }
    }
}

