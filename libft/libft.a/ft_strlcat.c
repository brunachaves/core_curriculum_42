/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:54:10 by brchaves          #+#    #+#             */
/*   Updated: 2024/04/24 09:54:11 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int check_nullend(char *str)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(str);
    while(i <= len)
    {
        if(str[i] == '\0')
            return (1);
        i++;
    }
    return (0);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t result_len;
    int i;

    i = 0;
    if (size == 0)
        return (0);
    while (dst[i])
        i++;
    while (*src && (i < size))
    {
        dst[i] = *src;
        i++;
        src++;
    }
    if (i < size)
        dst[i] = '\0';
    return (result_len);
}