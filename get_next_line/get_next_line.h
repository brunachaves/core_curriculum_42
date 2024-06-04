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
int len_new_line(char *str, ssize_t bytes_read);
int check_new_line(char *str, ssize_t bytes_read);
void *ft_calloc(size_t nmemb, size_t size);
char *ft_strjoin(char *s1, char *s2, size_t len2);
size_t ft_strlen(const char *str);

#endif