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

int	ft_wordcpy_and_indexplus(int i, const char *start, const char *s, char **array)
{
	int len;

	len = s - start;
	array[i] = (char *)ft_calloc((len + 1), sizeof(char));
	ft_strlcpy(array[i], start, len + 1);
	i++;
	return (i);
}

char	**ft_split(const char *s, char c)
{
	int			num_words;
	char		**array;
	int			i;
	const char	*start;

	num_words = ft_count_words(s, c);
	array = (char **)ft_calloc(num_words + 1, sizeof(char *));
	i = 0;
	start = s;
	while (*s)
	{
		if (*s == c)
		{
			if (s != start)
				i = ft_wordcpy_and_indexplus(i, start, s, array);
			start = s + 1;
		}
		s++;
	}
	if (s != start)
		i = ft_wordcpy_and_indexplus(i, start, s, array);
	return (array);
}
