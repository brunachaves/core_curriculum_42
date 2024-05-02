/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:48:21 by brchaves          #+#    #+#             */
/*   Updated: 2024/05/02 13:38:03 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_ptr(void *s)
{
	if (s == NULL)
		return ;
	free(s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_size;
	void	*error;

	error = malloc(1);
	ft_bzero(error, 1);
	total_size = nmemb * size;
	if (nmemb == 0 || size == 0)
		return (error);
	ft_free_ptr(error);
	if ((int)nmemb < 0 || (int)size < 0)
		return (NULL);
	ptr = malloc(total_size);
	if (ptr != NULL)
		ft_bzero(ptr, total_size);
	return (ptr);
}
