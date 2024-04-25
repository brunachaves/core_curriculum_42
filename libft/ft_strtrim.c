/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:54:29 by brchaves          #+#    #+#             */
/*   Updated: 2024/04/25 13:47:19 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start_index;
	int		end_index;
	int		size_newstr;
	int		i;

	start_index = ft_start_index(s1, set);
	end_index = ft_end_index(s1, set);
	size_newstr = end_index - start_index + 1;
	str = (char *)malloc(size_newstr * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (start_index <= end_index)
	{
		str[i] = s1[start_index];
		i++;
		start_index++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_start_index(char const *s1, char const *set)
{
	int	start_index;
	int	j;
	int	check_times;

	start_index = 0;
	check_times = ft_strlen(set);
	while (s1[start_index] && check_times)
	{
		j = 0;
		while (set[j])
		{
			if (s1[start_index] == set[j])
				start_index++;
			j++;
		}
		check_times--;
	}
	return (start_index);
}

int	ft_end_index(char const *s1, char const *set)
{
	int	end_index;
	int	j;
	int	check_times;

	end_index = ft_strlen(s1) - 1;
	check_times = ft_strlen(set);
	while (s1[end_index] && check_times)
	{
		j = 0;
		while (set[j])
		{
			if (s1[end_index] == set[j])
				end_index--;
			j++;
		}
		check_times--; 
	}
	return (end_index);
}
