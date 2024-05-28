/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chrstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:21:22 by brchaves          #+#    #+#             */
/*   Updated: 2024/05/28 10:23:24 by brchaves         ###   ########.fr       */
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
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_printf_sign(char sign)
{
	ft_putchar_fd(sign, 1);
	return (1);
}
