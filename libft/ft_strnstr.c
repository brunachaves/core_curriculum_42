/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:47:41 by brchaves          #+#    #+#             */
/*   Updated: 2024/04/25 13:49:02 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*ptr;
	int			check;
	int			i;
	int			j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)(big));
	while (i < (int)len)
	{
		j = 0;
		check = 0;
		while (big[i] == little[j])
		{
			check = 1;
			i++;
			j++;
		}
		if (!(little[j]) && check == 1)
		{
			ptr = big + i - j;
			return ((char *)(ptr));
		}
		i += 1 - j;
	}
	return (NULL);
}
