/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:00:42 by brchaves          #+#    #+#             */
/*   Updated: 2024/05/31 14:16:45 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*line;
	char	*temp;
	ssize_t	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	line = ft_calloc(1, 1);
	if (bytes_read <= 0 || fd < 0 || BUFFER_SIZE <= 0 || !line)
	{
		free (line);
		return (NULL);
	}
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		if (check_new_line(buffer))
		{
			temp = ft_strjoin(line, buffer, len_new_line(buffer));
			free (line);
			line = temp;
			return (line);
		}
		temp = ft_strjoin(line, buffer, BUFFER_SIZE);
		free (line);
		line = temp;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	return (NULL);
}
