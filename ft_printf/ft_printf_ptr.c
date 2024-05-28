/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:20:49 by brchaves          #+#    #+#             */
/*   Updated: 2024/05/28 11:35:46 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr_fd(uintptr_t ptr, int fd)
{
	char	*hex_digits;
	char	hex_str[16];
	int		i;

	hex_digits = "0123456789abcdef";
	if (ptr == 0)
	{
		write(fd, "(nil)", 5);
		return;
	}
	i = 0;
	while (ptr)
	{
		hex_str[i++] = hex_digits[ptr % 16];
		ptr /= 16;
	}
	write(fd, "0x", 2);
	while (--i >= 0)
		write(fd, &hex_str[i], 1);
}

int	ft_printf_p(void *ptr)
{
	uintptr_t address;
	int count;

	address = (uintptr_t)ptr;
	if (address == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putptr_fd(address, 1);
	count = 2;
	while (address)
	{
		address /= 16;
		count++;
	}
	return (count);
}
