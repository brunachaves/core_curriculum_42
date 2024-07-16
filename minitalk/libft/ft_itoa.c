/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:53:45 by brchaves          #+#    #+#             */
/*   Updated: 2024/05/22 10:00:14 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen(int nb)
{
	int	len_number;
	int	aux_nb;

	aux_nb = nb;
	len_number = 0;
	if (!nb)
		return (1);
	if (nb < 0)
	{
		len_number = 1;
		aux_nb *= (-1);
	}
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

	i = ft_nbrlen(n) - 1;
	n *= -1;
	str[i + 1] = '\0';
	while (i > 0)
	{
		c = (n % 10) + 48;
		str[i] = c;
		i--;
		n /= 10;
	}
	str[0] = '-';
}

void	itoa_positive(char *str, int n)
{
	int		i;
	char	c;

	i = ft_nbrlen(n) - 1;
	str[i + 1] = '\0';
	while (i >= 0)
	{
		c = (n % 10) + 48;
		str[i] = c;
		i--;
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	size_t		len_number;
	char		*str;

	len_number = ft_nbrlen(n);
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(len_number * (sizeof(char)) + 1);
	if (!str)
		return (NULL);
	else if (n < 0)
	{
		itoa_negative(str, n);
		return (str);
	}
	else
	{
		itoa_positive(str, n);
		return (str);
	}
}
