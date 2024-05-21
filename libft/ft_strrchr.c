/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:54:26 by brchaves          #+#    #+#             */
/*   Updated: 2024/05/21 14:40:24 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	const char		*ptr;
	unsigned char	d;

	i = 0;
	ptr = NULL;
	d = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == d)
			ptr = s + i;
		i++;
	}
	if (d == 0)
		return ((char *)(s + i));
	return ((char *)(ptr));
}
