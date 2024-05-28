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

int	ft_puthex_fd(unsigned long int num, char *hex_str)
{
	char	*str;
	int		len;

	len = ft_hexlen(num);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	len--;
	while (len > 0)
	{
		str[len] = hex_str[num % 16];
		num /= 16;
		len--;
	}
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free (str);
	return (len);
}
