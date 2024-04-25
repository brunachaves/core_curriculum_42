/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:53:45 by brchaves          #+#    #+#             */
/*   Updated: 2024/04/25 12:28:23 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_digits(int nb)
{
	int	digits;
	int	aux_nb;

	aux_nb = nb;
	digits = 0;
	if (nb == 0)
		return (1);
	while (aux_nb)
	{
		aux_nb /= 10;
		digits++;
	}
	return (digits);
}

void	itoa_negative(char *str, int n)
{
	int		i;
	char	c;

	i = ft_digits(n);
	n *= -1;
	while (i > 0)
	{
		c = (n % 10) + 48;
		str[i] = c;
		i--;
		n /= 10;
	}
	str[0] = '-';
}

char	*ft_itoa(int n)
{
	int		digits;
	int		i;
	char	*str;
	char	c;

	digits = ft_digits(n);
	str = (char *)malloc(digits * (sizeof(int)) + 1);
	i = digits - 1;
	if (str == NULL)
		return (NULL);
	if (n == -2147483648)
		return ("-2147483648");
	else if (n < 0)
	{
		itoa_negative(str, n);
		return (str);
	}
	while (i >= 0)
	{
		c = (n % 10) + 48;
		str[i] = c;
		i--;
		n /= 10;
	}
	return (str);
}
