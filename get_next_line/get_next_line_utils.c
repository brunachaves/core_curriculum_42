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

size_t ft_strlen(const char *str)
{
    size_t counter;

	counter = 0;
    while (str[counter] && str[counter] != '\n')
        counter++;
    if (str[counter] == '\n')
        counter++;
    return (counter);
}

char *ft_strjoin(char *s1, char *s2, size_t len2)
{
    char *new_str;
    size_t len1;
    size_t size;
	size_t i;
	size_t j;

    len1 = ft_strlen(s1);
    size = len1 + len2 + 1;
    new_str = (char *)malloc(size * sizeof(char));
	i = 0;
	j = 0;
    if (new_str == NULL)
        return (NULL);
    while (i < len1)
	{
		new_str[i] = s1[i];
		i++;
	}
    while (j < len2)
	{
		new_str[i] = s2[j];
		i++;
		j++;
	}
    new_str[i] = '\0';
    return (new_str);
}

void *ft_calloc(size_t nmemb, size_t size)
{
    void *ptr;
    size_t i;
    char *char_s;

	i = 0;
    if (nmemb == 0 || size == 0)
        return malloc(0);
    if (size > SIZE_MAX / nmemb)
        return NULL;
    ptr = malloc(nmemb * size);
    if (ptr)
    {
        char_s = (char *)ptr;
        while (i < nmemb * size)
            char_s[i++] = '\0';
    }
    return (ptr);
}

int check_new_line(char *str, ssize_t bytes_read)
{
	int	i;

	i = 0;
    while (i < bytes_read)
    {
        if (str[i] == '\n')
            return (1);
		i++;
    }
    return (0);
}

int len_new_line(char *str, ssize_t bytes_read)
{
    int len;

	len = 0;
    while (len < bytes_read && str[len] != '\n')
        len++;
    if (len < bytes_read && str[len] == '\n')
        len++;
    return (len);
}
