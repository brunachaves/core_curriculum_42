/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:21:49 by brchaves          #+#    #+#             */
/*   Updated: 2024/07/24 11:21:54 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		is_integer(char c);
int		check_is_num(char **array);
int		check_is_int(char **array);
int		check_duplicates(char **array);
void	check_error(char **array);
t_list  *populate_list_a(char **str);
t_list	*init_list_b();
void    dealloc(t_list **list);
void	swap_a(t_list	*a_list, int simultaneous);
void	swap_b(t_list	*b_list, int simultaneous);
void	swap_s(t_list	*a_list, t_list *b_list);
void	push_a(t_list	**a_list, t_list **b_list);
void	push_b(t_list	**a_list, t_list **b_list);
void    rotate_a(t_list **a_list, int simultaneous);
void    rotate_b(t_list **b_list, int simultaneous);
void    rotate_r(t_list **a_list, t_list **b_list);
void    rotate_reverse_a(t_list **a_list, int simultaneous);
void    rotate_reverse_b(t_list **b_list, int simultaneous);
void    rotate_reverse_r(t_list **a_list, t_list **b_list);

#endif