/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:48:35 by brchaves          #+#    #+#             */
/*   Updated: 2024/04/24 12:30:01 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	is_alpha;
	int	is_digit;

	is_alpha = ft_isalpha(c);
	is_digit = ft_isdigit(c);
	if (is_alpha || is_digit)
		return (1);
	return (0);
}
