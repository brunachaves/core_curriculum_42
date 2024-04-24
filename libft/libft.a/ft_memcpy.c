/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:49:21 by brchaves          #+#    #+#             */
/*   Updated: 2024/04/23 13:49:22 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    int i;
    char *c_dest;
    char *c_src;

    i = 0;
    c_dest = dest;
    c_src = src;
    if (!src && !dest)
        return (NULL);
    while (i < n)
    {
        c_dest[i] = c_src[i];
        i++;
    }
    return (dest);
}