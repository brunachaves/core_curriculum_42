/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:21:27 by brchaves          #+#    #+#             */
/*   Updated: 2024/05/28 10:23:47 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_d(int num)
{
	ft_putnbr_fd(num, 1);
	return (ft_nbrlen(num));
}

int	ft_printf_u(unsigned int num)
{
	int	count;

	count = ft_printf_d(num);
	return (count);
}
