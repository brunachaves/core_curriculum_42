/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chrstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:21:22 by brchaves          #+#    #+#             */
/*   Updated: 2024/07/01 14:14:49 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int	ft_printf_c(int num)
{
	ft_putchar_fd(num, 1);
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
		return (0);
	else
	{
		ft_putstr_fd(str, 1);
		count = ft_strlen(str);
	}
	return (count);
}
