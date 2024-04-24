/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:48:21 by brchaves          #+#    #+#             */
/*   Updated: 2024/04/24 10:05:49 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_calloc(size_t nmemb, size_t size)
{
    char    *ptr;
    int i;

    i = 0;    
    if (nmemb == 0 || size == 0)
        return (NULL);
    if (nmemb * size > INT_MAX || nmemb * size < INT_MIN)
        return (NULL);
    ptr = (char *)malloc(nmemb * size);
    while (i < nmemb)
    {
        ptr[i] = 0;
        i++;
    }
    return ((void *)(ptr));    
}