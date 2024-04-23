#include "libft.h"

void    ft_appendchar(char *str, int index, char c)
{
    str[index] = c;
}

char *ft_itoa(int n)
{
    int digits;
    int i;
    char *str;
    char c;

    digits = ft_digits(n);
    str = (char *)malloc(digits * (sizeof(int)) + 1);
    i = digits -1;
    if (n == -2147483648)
            str = "-2147483648";
    else if (n < 0)
    {
        ft_appendchar(str, 0, '-');
        n *= -1;
    }
    if (n >= 0)
    {
        while (i >= 0)
        {
            c = (n % 10) + 48;
            ft_appendchar(str, i, c);
            i--;
            n /= 10;
        }
    }
   return (str);
}