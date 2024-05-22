/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:47:41 by brchaves          #+#    #+#             */
/*   Updated: 2024/05/22 09:55:21 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_little;

	len_little = ft_strlen(little);
	if (!*little)
		return ((char *)big);
	while (*big && len_little <= len)
	{
		if (*big == *little && ft_strncmp(big, little, len_little) == 0)
			return ((char *)big);
		++big;
		--len;
	}
	return (NULL);
}
