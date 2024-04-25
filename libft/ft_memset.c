/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:49:36 by brchaves          #+#    #+#             */
/*   Updated: 2024/04/25 10:39:13 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*char_s;

	i = 0;
	char_s = s;
	while (i < n)
	{
		char_s[i] = c;
		i++;
	}
	return (s);
}
