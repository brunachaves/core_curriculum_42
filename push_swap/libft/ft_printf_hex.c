/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:21:12 by brchaves          #+#    #+#             */
/*   Updated: 2024/07/01 14:14:43 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_lowx(unsigned int num)
{
	char	*hexadecimal;
	int		count;

	hexadecimal = "0123456789abcdef";
	count = ft_puthex_fd(num, hexadecimal);
	return (count);
}

int	ft_printf_uppx(unsigned int num)
{
	char	*hexadecimal;
	int		count;

	hexadecimal = "0123456789ABCDEF";
	count = ft_puthex_fd(num, hexadecimal);
	return (count);
}

int	ft_hexlen(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num /= 16;
		len++;
	}
	return (len);
}

int	ft_puthex_fd(unsigned int num, char *hex_str)
{
	char	str[9];
	int		len;
	int		i;

	len = ft_hexlen(num);
	str[len] = '\0';
	i = len - 1;
	if (num == 0)
		str[0] = hex_str[0];
	while (num)
	{
		str[i] = hex_str[num % 16];
		num /= 16;
		i--;
	}
	ft_putstr_fd(str, 1);
	return (len);
}
