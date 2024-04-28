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

int	ft_isset(char c, const char *set)
{
	while (*set)
	{
		if(c == *set)
			return (1);
		set++;
	}
	return(0);
}

size_t	ft_start_index(char const *s1, const char *set)
{
	size_t	start_index;
	size_t i;

	i = 0;
	start_index = 0;
	while (s1[i] && start_index == 0)
	{
		while(ft_isset(s1[i], set))
			i++;
		start_index = i;
	}
	return (start_index);
}

size_t	ft_end_index(char const *s1, char const *set)
{
	size_t	end_index;
	size_t	i;

	i = 0;
	end_index = 0;
	while (s1[i] && end_index == 0)
	{
		while(ft_isset(s1[i], set))
			i--;
		end_index = i;
	}
	return (end_index);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t		start_index;
	size_t		end_index;
	size_t		size_newstr;
	size_t		i;

	start_index = ft_start_index(s1, set);
	end_index = ft_end_index(s1, set);
	if (start_index >= end_index)
		return (NULL);
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
/* 	str = ft_memcpy(str, s1, size_newstr); */
	str[size_newstr] = '\0';
	return (str);
}

