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

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    static ssize_t buffer_size;
    static ssize_t buffer_pos = 0;
    char *line;
    char *temp;
	int len;

	buffer_size = 0;
	buffer_pos = 0;
	line = (char *)ft_calloc(1, 1);
    if (fd < 0 || BUFFER_SIZE <= 0 || !line)
    {
        free (line);
        return (NULL);
    }
    while (1)
    {
        if (buffer_pos >= buffer_size)
        {
            buffer_size = read(fd, buffer, BUFFER_SIZE);
            buffer_pos = 0;
            if (buffer_size <= 0)
                break ;
        }
        len = len_new_line(buffer + buffer_pos, buffer_size - buffer_pos);
        temp = ft_strjoin(line, buffer + buffer_pos, len);
		if (!temp)
        {
            free(line);
            return NULL;
        }
        free (line);
        line = temp;
        buffer_pos += len;
        if (check_new_line(buffer + buffer_pos - len, len))
            return (line);
    }
    if (line[0] != '\0')
        return line;
    free(line);
    return NULL;
}
