/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:53:56 by brchaves          #+#    #+#             */
/*   Updated: 2024/04/24 10:47:54 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    **ft_split(char const *s, char c)
{
    char **array;
    char *str1;
    char *str2;

    array = (char **)malloc(ft_strlen(s) * sizeof(char) + 2);
    if (array == NULL)
        return (NULL);
    
    
}