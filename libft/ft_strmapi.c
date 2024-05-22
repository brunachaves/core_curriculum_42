/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:54:19 by brchaves          #+#    #+#             */
/*   Updated: 2024/05/22 10:44:34 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len_newstr;
	char			*new_str;
	unsigned int	i;

	len_newstr = ft_strlen(s);
	new_str = (char *)malloc(len_newstr * sizeof(char) + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = (*f)(i, (char)(s[i]));
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
