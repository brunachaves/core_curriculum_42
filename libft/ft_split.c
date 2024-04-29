/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:53:56 by brchaves          #+#    #+#             */
/*   Updated: 2024/04/29 10:06:54 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(const char *s, char c)
{
	int	counter;
	int	in_word;

	counter = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
		{
			if (in_word)
			{
				counter++;
				in_word = 0;
			}
		}
		else
		{
			if (!in_word)
				in_word = 1;
		}
		s++;
	}
	if (in_word)
		counter++;
	return (counter);
}

char	**ft_split(const char *s, char c)
{
	int			num_words;
	char		**array;
	int			i;
	const char	*start;
	int			len;

	num_words = ft_count_words(s, c);
	array = (char **)malloc((num_words + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	i = 0;
	start = s;
	while (*s)
	{
		if (*s == c)
		{
			if (s != start)
			{
				len = s - start;
				array[i] = (char *)malloc((len + 1) * sizeof(char));
				if (array[i] == NULL)
					return (NULL);
				ft_strlcpy(array[i], start, len + 1);
				i++;
			}
			start = s + 1;
		}
		s++;
	}
	if (s != start)
	{
		len = s - start;
		array[i] = (char *)malloc((len + 1) * sizeof(char));
		if (array[i] == NULL)
			return (NULL);
		ft_strlcpy(array[i], start, len + 1);
		i++;
	}
	array[i] = NULL;
	return (array);
}
