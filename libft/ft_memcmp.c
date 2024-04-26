/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:49:25 by brchaves          #+#    #+#             */
/*   Updated: 2024/04/26 10:44:46 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*c_s1;
	const char	*c_s2;

	c_s1 = s1;
	c_s2 = s2;
	if (n == 0)
		return (0);
	while (n)
	{
		if (*c_s1 != *c_s2)
			return (*c_s2 - *c_s1);
		c_s1++;
		c_s2++;
		n--;
	}
	return (0);
}
