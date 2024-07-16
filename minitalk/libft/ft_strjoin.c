/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:54:08 by brchaves          #+#    #+#             */
/*   Updated: 2024/05/03 11:50:53 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcpy_join(char *dest, const char *src, int index_dest)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[index_dest] = src[i];
		i++;
		index_dest++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	len1;
	size_t	len2;
	size_t	size;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	size = len1 + len2 + 1;
	new_str = (char *)malloc(size * (sizeof(char)));
	if (new_str == NULL)
		return (NULL);
	ft_strcpy_join(new_str, s1, 0);
	ft_strcpy_join(new_str, s2, len1);
	new_str[len1 + len2] = '\0';
	return (new_str);
}
