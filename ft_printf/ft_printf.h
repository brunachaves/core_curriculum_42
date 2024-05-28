/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:21:39 by brchaves          #+#    #+#             */
/*   Updated: 2024/05/28 11:29:05 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_is_specifier(char c);
int	ft_convert(va_list ap, char specifier);
int	ft_printf_c(int num);
int	ft_printf_s(char *str);
int	ft_printf_p(unsigned long int num);
int	ft_printf_d(int num);
int	ft_printf_u(unsigned int num);
int	ft_printf_lowx(unsigned int num);
int	ft_printf_uppx(unsigned int num);
int	ft_printf_sign(char sign);
int	ft_hexlen(unsigned int num);
int	ft_puthex_fd(unsigned long int num, char *hex_str);

#endif