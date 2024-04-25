/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:54:02 by brchaves          #+#    #+#             */
/*   Updated: 2024/04/25 13:54:45 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	size;

	size = ft_strlen(src) + 1;
	dest = (char *)malloc(sizeof(char) * size);
	ft_strcpy(dest, ((char *)(src)));
	return (dest);
}
