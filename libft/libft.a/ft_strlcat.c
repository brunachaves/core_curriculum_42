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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t result_len;
    size_t max_append;

    result_len = ft_strlen(dst) + ft_strlen(src);
    max_append = size - ft_strlen(dst) - 1;
    if (max_append <= 0)
        return (result_len);
    while (*dst)
        dst++;
    while(*src && max_append)
    {
        *dst = *src;
        max_append--;
    }
    *dst = '\0';
    return (result_len);
}