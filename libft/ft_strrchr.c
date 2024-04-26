/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:54:26 by brchaves          #+#    #+#             */
/*   Updated: 2024/04/26 10:23:29 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*ptr;

	i = 0;
	ptr = NULL;
	if (c > 255)
		c = c % 256;
	while (s[i])
	{
		if (s[i] == c)
			ptr = s + i;
		i++;
	}
	if (c == 0)
		return ((char *)(s + i));
	return ((char *)(ptr));
}
