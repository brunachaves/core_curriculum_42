/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:53:20 by brchaves          #+#    #+#             */
/*   Updated: 2024/06/12 10:16:24 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12 
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

typedef struct s_list
{
	char			*buffer_content;
	struct s_list	*next;
}				t_list;

int		found_newline(t_list *list);
t_list	*ft_lstlast(t_list *lst);
char	*build_line(t_list *list);
void	copy_to_line(t_list *list, char *str);
int		len_to_newline(t_list *list);
void	update_list(t_list **list);
char	*get_next_line(int fd);
void	dealloc(t_list **list, t_list *clean_node, char *buffer);
void	create_list(t_list **list, int fd);

#endif