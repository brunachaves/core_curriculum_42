/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:53:45 by brchaves          #+#    #+#             */
/*   Updated: 2024/04/24 09:53:46 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    if (str == NULL)
        return (NULL);
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