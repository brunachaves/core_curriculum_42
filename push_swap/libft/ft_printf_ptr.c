/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:20:49 by brchaves          #+#    #+#             */
/*   Updated: 2024/07/17 11:54:09 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptr_fd(unsigned long int ptr, int fd)
{
	char	*hex_digits;
	char	hex_str[16];
	int		i;

	hex_digits = "0123456789abcdef";
	i = 0;
	while (ptr)
	{
		hex_str[i] = hex_digits[ptr % 16];
		ptr /= 16;
		i++;
	}
	write(fd, "0x", 2);
	i--;
	while (i >= 0)
	{
		write(fd, &hex_str[i], 1);
		i--;
	}
}

int	ft_printf_p(void *ptr)
{
	unsigned long int	address;
	int					count;

	address = (unsigned long int)ptr;
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
