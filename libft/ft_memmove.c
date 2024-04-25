/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:49:30 by brchaves          #+#    #+#             */
/*   Updated: 2024/04/25 13:55:55 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*char_dest;
	const char	*char_src;
	char		*aux;
	size_t		i;

	char_dest = dest;
	char_src = src;
	i = 0;
	if (!src && !dest)
		return (NULL);
	while (i < n)
	{
		aux[i] = *char_src;
		*char_dest = aux[i];
		i++;
		char_src++;
		char_dest++;
	}
	return (dest);
}
