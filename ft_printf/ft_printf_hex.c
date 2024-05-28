/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:21:12 by brchaves          #+#    #+#             */
/*   Updated: 2024/05/28 11:30:23 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	char	*str;
	int		len;
	int		orig_len;

	len = ft_hexlen(num);
	orig_len = len;
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	while (len > 0)
	{
		str[--len] = hex_str[num % 16];
		num /= 16;
	}
	ft_putstr_fd(str, 1);
	len = orig_len;
	free(str);
	return (len);
}
