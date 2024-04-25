/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:53:56 by brchaves          #+#    #+#             */
/*   Updated: 2024/04/25 13:55:29 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		j;

	array = (char **)malloc(ft_strlen(s) * sizeof(char) + 1);
	if (array == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		j = 0;
		while (*s != c)
		{
			array[i][j] = c;
			j++;
			s++;
		}
		array[i][j] = '\0';
		s++;
		i++;
	}
	array[i][j] = '\0';
	return (array);
}
