/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:48:03 by brchaves          #+#    #+#             */
/*   Updated: 2024/05/22 09:57:14 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_digits(int nb)
{
	int	digits;
	int	aux_nb;

	aux_nb = nb;
	digits = 0;
	if (!nb)
		return (1);
	while (aux_nb)
	{
		aux_nb /= 10;
		digits++;
	}
	return (digits);
}

int	ft_base(int digits)
{
	int	base;
	int	aux_dig;

	base = 1;
	aux_dig = digits;
	if (aux_dig == 1)
		return (1);
	while (aux_dig > 1)
	{
		base *= 10;
		aux_dig--;
	}
	return (base);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		base;
	int		digits;

	digits = ft_digits(n);
	base = ft_base(digits);
	if (n == INT_MIN)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n >= 0)
	{
		while (digits)
		{
			c = n / base + '0';
			write(fd, &c, 1);
			n %= base;
			base /= 10;
			digits--;
		}
	}
}
