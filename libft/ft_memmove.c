/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:49:30 by brchaves          #+#    #+#             */
/*   Updated: 2024/04/29 13:15:55 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*aux;

	aux = ft_calloc(1, n);
	ft_memcpy(aux, src, n);
	ft_memcpy(dest, aux, n);
	free(aux);
	return (dest);
}
