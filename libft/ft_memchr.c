/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:49:15 by brchaves          #+#    #+#             */
/*   Updated: 2024/04/23 13:49:16 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
    char *char_s;
    int i;

    i = 0;
    char_s = s;
    while (char_s[i] && i < n)
    {
        if (char_s[i] == c)
            return (s+i);
        i++;
    }
    return (NULL);
}