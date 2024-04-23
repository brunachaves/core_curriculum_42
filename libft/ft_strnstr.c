/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:47:41 by brchaves          #+#    #+#             */
/*   Updated: 2024/04/23 13:47:42 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
    const char *ptr;
    int i;
    int j;

    i = 0;
    j = 0;
    if (*little == '\0')
        return ((char *)(big));
    while(big[i] && i < len)
    {

    }
    return ((char *)(ptr));
    return (NULL);
}