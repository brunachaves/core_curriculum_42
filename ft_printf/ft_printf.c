/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:20:50 by brchaves          #+#    #+#             */
/*   Updated: 2024/05/31 14:47:54 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list			ap;
	static int		count;
	static int		i;

	if (!format)
		return (0);
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (ft_is_specifier(format[i + 1]))
				count += ft_convert(ap, format[i + 1]);
			else if (!format[i + 1])
				break ;
			else
				count += write (1, "%%", 1);
			i += 2;
		}
		else
			count += write(1, &format[i++], 1);
	}
	va_end(ap);
	return (count);
}
