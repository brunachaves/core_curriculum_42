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

	char_dest = dest;
	char_src = src;
	if (!src && !dest)
		return (NULL);
	while (n)
	{
		*aux = *char_src;
		*char_dest = *aux;
		n--;
		char_src++;
		char_dest++;
		aux++;
	}
	return (dest);
}
