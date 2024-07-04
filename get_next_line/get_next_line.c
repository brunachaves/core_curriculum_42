/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:38:02 by brchaves          #+#    #+#             */
/*   Updated: 2024/07/04 11:40:46 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*joined;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined = (char *)malloc(len1 + len2 + 1);
	if (!joined)
		return (NULL);
	ft_strcpy(joined, s1);
	ft_strcpy(joined + len1, s2);
	free(s1);
	return (joined);
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*initialize_aux(char *remainder)
{
	char	*aux;

	if (remainder)
	{
		aux = (char *)malloc(ft_strlen(remainder) + 1);
		if (!aux)
			return (NULL);
		ft_strcpy(aux, remainder);
		free(remainder);
	}
	else
	{
		aux = (char *)malloc(1);
		if (!aux)
			return (NULL);
		aux[0] = '\0';
	}
	return (aux);
}

char	*create_temp(char *remainder, int fd)
{
	char	*aux;
	char	*buffer;
	int		bytes_read;

	aux = initialize_aux(remainder);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!aux || !buffer)
		return (free(aux), free(buffer), NULL);
	while (!found_newline(aux))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(aux);
			free(buffer);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		aux = ft_strjoin(aux, buffer);
		if (!aux)
			return (free(buffer), NULL);
	}
	return (free(buffer), aux);
}

char	*get_next_line(int fd)
{
	static char	*remainder = NULL;
	char		*temp;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	temp = create_temp(remainder, fd);
	if (!temp || !*temp)
	{
		free(temp);
		return (NULL);
	}
	next_line = get_the_line(temp);
	remainder = update_remainder(temp);
	return (next_line);
}
