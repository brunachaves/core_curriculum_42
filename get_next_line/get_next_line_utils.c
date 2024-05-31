/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:00:47 by brchaves          #+#    #+#             */
/*   Updated: 2024/05/31 13:55:45 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (!nmemb || !size)
	{
		ptr = malloc(0);
		return (ptr);
	}
	if (size > SIZE_MAX / nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr)
		ft_bzero(ptr, nmemb * size);
	return (ptr);
}

int	check_new_line(char *str)
{
	while (*str)
	{
		if( *str == '\n')
			return (1);
		str++;
	}
	return (0);
}

int	len_new_line(char *str)
{
	int	len;

	len = 0;
	while(*str && *str != '\n')
	{
		len++;
		str++;
	}
	len++;
	return(len);
}

void	ft_strcpy_join(char *dest, char *src, int index_dest)
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

char	*ft_strjoin(char *s1, char *s2, size_t len2)
{
	char	*new_str;
	size_t	len1;
	size_t	size;

	len1 = ft_strlen(s1);
	size = len1 + len2 + 1;
	new_str = (char *)malloc(size * (sizeof(char)));
	if (new_str == NULL)
		return (NULL);
	ft_strcpy_join(new_str, s1, 0);
	ft_strcpy_join(new_str, s2, len1);
	new_str[len1 + len2] = '\0';
	return (new_str);
}

size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	while (*str)
	{
		counter++;
		str++;
	}
	return (counter);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*char_s;

	i = 0;
	char_s = s;
	while (i < n)
	{
		char_s[i] = '\0';
		i++;
	}
}