#include "get_next_line.h"
#include <stdlib.h>

int	found_newline(t_list *list)
{
	int	i;

	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str_buffer[i] && i < BUFFER_SIZE)
		{
			if (list->str_buffer[i] == '\n')
				return (1);
			++i;
		}
		list = list->next;
	}
	return (0);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_node;

	if (!lst)
		return (NULL);
	last_node = lst;
	while (last_node -> next)
		last_node = last_node -> next;
	return (last_node);
}


void	copy_str(t_list *list, char *str)
{
	int	i;
	int	k;

	if (!list)
		return ;
	k = 0;
	while (list)
	{
		i = 0;
		while (list->str_buffer[i])
		{
			if (list->str_buffer[i] == '\n')
			{
				str[k++] = '\n';
				str[k] = '\0';
				return ;
			}
			str[k++] = list->str_buffer[i++];
		}
		list = list->next;
	}
	str[k] = '\0';
}

int	len_to_newline(t_list *list)
{
	int	i;
	int	len;

	if (!list)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->str_buffer[i])
		{
			if (list->str_buffer[i] == '\n')
			{
				++len;
				return (len);
			}
			++i;
			++len;
		}
		list = list->next;
	}	
	return (len);
}

void	dealloc(t_list **list, t_list *clean_node, char *buffer)
{
	t_list	*tmp;

	if (!*list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->str_buffer);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clean_node->str_buffer[0])
		*list = clean_node;
	else
	{
		free(buffer);
		free(clean_node);
	}
}