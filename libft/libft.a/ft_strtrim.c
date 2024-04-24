/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:54:29 by brchaves          #+#    #+#             */
/*   Updated: 2024/04/24 10:42:22 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strtrim(char const *s1, char const *set)
{
    char    *str;
    int size;
    int index_end;

    size = ft_strlen(s1) - 2 * (ft_strlen(set) + 1);
    str =  (char *)malloc(size * sizeof(char));
/*     index_end = ft_strlen(s1) - 2 * (ft_strlen(set)) - 1;
    while(*s1)
    {
        while (*s1 == *set)
        {
            s1++;
            set++;
        }
        if (!(*set))
        {
            while(*s1 && *s1 != s1[index_end])
            *str = *s1;
        }
    } */
    
}
