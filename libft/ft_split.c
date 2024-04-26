/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:53:56 by brchaves          #+#    #+#             */
/*   Updated: 2024/04/26 13:20:37 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_array_size(const char *s, char c)
{
	int	arr_size;

	arr_size = 0;
	while (*s)
	{
		if(*s != c)
			arr_size++;
		s++;
	}
	return (arr_size);
}

int	ft_lenword(const char *s, char c)
{
	int len;

	len = 0;
	while(*s && (*s != c))
	{
		len++;
		s++;
	}
	return (len);
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	int		i;
	int		j;
	size_t arr_size;

	arr_size = ft_array_size(s, c);
	array = (char **)malloc(sizeof(s));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		j = 0;
		array[i] = (char *)malloc(ft_lenword((s + i), c) * sizeof(char));
		while (*s != c)
		{
			array[i][j] = *s;
			j++;
			s++;
		}
		i++;
	}
	array[i][j] = '\0';
	return (array);
}
