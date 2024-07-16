/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:53:56 by brchaves          #+#    #+#             */
/*   Updated: 2024/05/22 15:45:24 by brchaves         ###   ########.fr       */
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

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		len;
	int		words;

	words = ft_count_words(s, c);
	i = 0;
	result = (char **)ft_calloc((words + 1), sizeof(char *));
	if (!result)
		return (NULL);
	while (i < words)
	{
		while (*s == c)
			s++;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		result[i] = (char *)malloc((len + 1) * sizeof(char));
		if (!result[i])
			return (NULL);
		ft_strlcpy(result[i], s, len + 1);
		s += len;
		i++;
	}
	return (result);
}
