/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:53:59 by brchaves          #+#    #+#             */
/*   Updated: 2024/05/21 14:35:48 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	d;

	i = 0;
	d = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == d)
			return ((char *)(s + i));
		i++;
	}
	if (d == 0)
		return ((char *)(s + i));
	return (NULL);
}
