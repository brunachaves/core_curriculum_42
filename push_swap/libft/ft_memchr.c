/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:49:15 by brchaves          #+#    #+#             */
/*   Updated: 2024/05/22 09:58:12 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*char_s;
	size_t			i;
	unsigned char	d;

	char_s = (unsigned char *)s;
	d = (unsigned char)c;
	i = 0;
	if (!n)
		return (NULL);
	while (i < n)
	{
		if (char_s[i] == d)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
