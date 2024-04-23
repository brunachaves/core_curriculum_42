/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:49:25 by brchaves          #+#    #+#             */
/*   Updated: 2024/04/23 13:49:26 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    char *c_s1;
    char *c_s2;
    int i;

    i = 0;
    if (n == 0)
		return (0);
	while (i < n && (*c_s1 == *c_s2))
	{
		c_s1++;
		c_s2++;
		i++;
	}
	return (*c_s1 - *c_s2);
}