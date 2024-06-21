#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

char	*get_next_line(int fd);
void	ft_strcpy(char *dst, char *src);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
char	*create_temp(char *remainder, int fd);
char	*initialize_aux(char *remainder);
char	*get_line(char *temp);
char	*update_remainder(char *temp);
int		len_to_newline(char *temp);
int		found_newline(char *temp);

#endif