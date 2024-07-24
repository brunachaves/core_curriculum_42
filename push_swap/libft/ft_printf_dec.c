/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:21:27 by brchaves          #+#    #+#             */
/*   Updated: 2024/07/17 11:54:23 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_d(int num)
{
	ft_putnbr_fd(num, 1);
	return (ft_nbrlen(num));
}

int	ft_printf_u(unsigned int num)
{
	ft_putnbr_u_fd(num, 1);
	return (ft_unbrlen(num));
}

void	ft_putnbr_u_fd(unsigned int n, int fd)
{
	char			c;
	unsigned int	base;
	int				digits;

	digits = 1;
	base = 1;
	while (n / base >= 10)
	{
		base *= 10;
		digits++;
	}
	while (base > 0)
	{
		c = (n / base) % 10 + '0';
		write(fd, &c, 1);
		base /= 10;
	}
}

int	ft_unbrlen(unsigned int nb)
{
	int	len_number;

	len_number = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		len_number++;
	}
	return (len_number);
}
