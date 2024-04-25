/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:54:36 by brchaves          #+#    #+#             */
/*   Updated: 2024/04/24 13:01:15 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_islower(int c)
{
	if (c > 96 && c < 123)
		return (1);
	return (0);
}

int	ft_toupper(int c)
{
	int	is_lower;

	is_lower = ft_islower(c);
	if (is_lower)
		return (c - 32);
	return (c);
}
