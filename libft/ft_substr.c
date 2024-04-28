/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:54:31 by brchaves          #+#    #+#             */
/*   Updated: 2024/04/26 13:55:53 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str_result;
/* 	size_t	i;; */

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str_result = (char *)malloc(len * (sizeof(char)) + 1);
	if (str_result == NULL)
		return (NULL);
	ft_strlcpy(str_result, (s + start), (len + 1));
	str_result[len] = '\0';
	return (str_result);
}
