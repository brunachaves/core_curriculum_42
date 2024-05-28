/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chrstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:21:22 by brchaves          #+#    #+#             */
/*   Updated: 2024/05/28 13:42:48 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_c(int num)
{
	char	c;

	c = num;
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_printf_s(char *str)
{
	int	count;

	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	else if (!*str)
	{
		return (0);
	}
	else
	{
		ft_putstr_fd(str, 1);
		count = ft_strlen(str);
	}
	return (count);
}

int	ft_printf_sign(char sign)
{
	ft_putchar_fd(sign, 1);
	return (1);
}
