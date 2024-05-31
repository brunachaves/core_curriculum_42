/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_specifier.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:20:56 by brchaves          #+#    #+#             */
/*   Updated: 2024/05/31 10:56:44 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p')
		return (1);
	else if (c == 'd' || c == 'i' || c == 'u')
		return (1);
	else if (c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_convert(va_list ap, char specifier)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count = ft_printf_c(va_arg(ap, int));
	else if (specifier == 's')
		count = ft_printf_s(va_arg(ap, char *));
	else if (specifier == 'p')
		count = ft_printf_p(va_arg(ap, void *));
	else if (specifier == 'd' || specifier == 'i')
		count = ft_printf_d(va_arg(ap, int));
	else if (specifier == 'u')
		count = ft_printf_u(va_arg(ap, unsigned int));
	else if (specifier == 'x')
		count = ft_printf_lowx(va_arg(ap, unsigned int));
	else if (specifier == 'X')
		count = ft_printf_uppx(va_arg(ap, unsigned int));
	else if (specifier == '%')
		count = ft_printf_c('%');
	return (count);
}
