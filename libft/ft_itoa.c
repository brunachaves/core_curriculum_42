/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:53:45 by brchaves          #+#    #+#             */
/*   Updated: 2024/04/26 12:03:53 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen(int nb)
{
	int	len_number;
	int	aux_nb;

	aux_nb = nb;
	len_number = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		len_number = 1;
	while (aux_nb)
	{
		aux_nb /= 10;
		len_number++;
	}
	return (len_number);
}

void	itoa_negative(char *str, int n)
{
	int		i;
	char	c;

	i = ft_nbrlen(n);
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
	int		len_number;
	int		i;
	char	*str;
	char	c;

	len_number = ft_nbrlen(n);
	i = len_number - 1;
	if (n == -2147483648)
		return ("-2147483648");
	str = (char *)malloc(len_number * (sizeof(char)) + 1);
	if (str == NULL)
		return (NULL);
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
