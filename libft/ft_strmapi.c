/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:54:19 by brchaves          #+#    #+#             */
/*   Updated: 2024/04/26 13:28:37 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			size;
	char			*new_str;
	unsigned int	i;

	size = ft_strlen(s) + 1;
	new_str = (char *)malloc(size * sizeof(char));
	i = 0;
	while (s[i])
	{
		new_str[i] = (*f)(i, (char)(s[i]));
		i++;
	}
	return (new_str);
}
