/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:57:51 by brchaves          #+#    #+#             */
/*   Updated: 2024/05/31 13:48:21 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
#include <stdint.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 12
#endif

char    *get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
int		check_new_line(char *str);
int		len_new_line(char *str);
char	*ft_strjoin(char *s1, char *s2, size_t len2);
void	ft_strcpy_join(char *dest, char *src, int index_dest);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);

#endif