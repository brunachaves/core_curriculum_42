/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:49:30 by brchaves          #+#    #+#             */
/*   Updated: 2024/05/22 09:57:43 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*s;
	char	*d;
	size_t	i;

	if (!src && !dest)
		return (NULL);
	d = (char *)dest;
	s = (char *)src;
	if (s < d)
	{
		while (len -- > 0)
		{
			d[len] = s[len];
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			d[i] = s[i];
			i ++;
		}
	}
	return (dest);
}
