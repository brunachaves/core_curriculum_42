#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12 
# endif

# include <stdlib.h>
# include <unistd.h>
#include <stdint.h>

typedef struct s_list
{
	char			*str_buffer;
	struct s_list	*next;
}				t_list;

int		found_newline(t_list *list);
t_list	*ft_lstlast(t_list *lst);
char	*get_line(t_list *list);
void	copy_str(t_list *list, char *str);
int		len_to_newline(t_list *list);
void	update_list(t_list **list);
char	*get_next_line(int fd);
void	dealloc(t_list **list, t_list *clean_node, char *buffer);
void	create_list(t_list **list, int fd);

#endif