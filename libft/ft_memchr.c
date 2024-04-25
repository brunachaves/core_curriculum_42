/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:49:15 by brchaves          #+#    #+#             */
/*   Updated: 2024/04/25 13:41:37 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memchr(const void *s, int c, size_t n)
{
	const char	*char_s;
	size_t		i;

	i = 0;
	char_s = s;
	while (char_s[i] && i < n)
	{
		if (char_s[i] == c)
			return ((void *)s+i);
		i++;
	}
	return (NULL);
}
