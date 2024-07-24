/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:13:21 by brchaves          #+#    #+#             */
/*   Updated: 2024/07/17 11:53:13 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	found_newline(char *temp)
{
	if (!temp)
		return (0);
	while (*temp)
	{
		if (*temp == '\n')
			return (1);
		temp++;
	}
	return (0);
}

void	ft_strcpy(char *dst, char *src)
{
	while (*src)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
}

int	len_to_newline(char *temp)
{
	int	len;

	len = 0;
	while (temp[len] && temp[len] != '\n')
		len++;
	if (temp[len] == '\n')
		len++;
	return (len);
}

char	*update_remainder(char *temp)
{
	char	*remainder;
	int		i;

	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (!temp[i])
	{
		free(temp);
		return (NULL);
	}
	remainder = (char *)malloc(ft_strlen(temp + i + 1) + 1);
	if (!remainder)
		return (NULL);
	i++;
	ft_strcpy(remainder, (temp + i));
	free(temp);
	return (remainder);
}

char	*get_line(char *temp)
{
	int		len;
	int		i;
	char	*line;

	len = len_to_newline(temp);
	i = 0;
	line = (char *)malloc(len + 1);
	if (!line)
		return (NULL);
	while (i <= len)
	{
		line[i] = temp[i];
		i++;
	}
	line[len] = '\0';
	return (line);
}
