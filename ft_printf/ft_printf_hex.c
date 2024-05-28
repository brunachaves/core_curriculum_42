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

int	ft_printf_p(unsigned long int num)
{
	char	*hexadecimal;
	int		count;

	hexadecimal = "0123456789abcdef";
	count = ft_puthex_fd(num, hexadecimal);
	return (count);
}
