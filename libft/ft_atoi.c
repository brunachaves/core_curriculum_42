/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:47:57 by brchaves          #+#    #+#             */
/*   Updated: 2024/04/25 12:01:11 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	signal;
	int	result;

	signal = 1;
	result = 0;
	while ((*str > 6 && *str < 14) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signal *= -1;
		str++;
	}
	while ((*str > 47 && *str < 58))
	{
		result = result * 10 + (*str - 48);
		str++;
	}
	return (signal * result);
}
