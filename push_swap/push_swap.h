/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:21:49 by brchaves          #+#    #+#             */
/*   Updated: 2024/07/30 13:42:38 by brchaves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				position;
	int				final_index;
	int				push_price;
	int				above_median;
	int				cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;	

int		is_integer(char c);
int		check_is_num(char **array);
int		check_is_int(char **array);
int		check_duplicates(char **array);
void	check_error(char **array);

void	free_stack(t_stack **stack);
void	free_array(char **array);

t_stack	*populate_stack_a(char **str);

void	swap_lst(t_stack *lst);
void	swap_a(t_stack	*a_stack);
void	swap_b(t_stack	*b_stack);
void	swap_s(t_stack	*a_stack, t_stack *b_stack);

void	push_a(t_stack	**a_stack, t_stack **b_stack);
void	push_b(t_stack	**a_stack, t_stack **b_stack);

void	rotate_lst(t_stack **stack);
void	rotate_a(t_stack **a_stack);
void	rotate_b(t_stack **b_stack);
void	rotate_r(t_stack **a_stack, t_stack **b_stack);

void	rotate_reverse_lst(t_stack **stack);
void	rotate_reverse_a(t_stack **a_stack);
void	rotate_reverse_b(t_stack **b_stack);
void	rotate_reverse_r(t_stack **a_stack, t_stack **b_stack);

int		is_a_sorted(t_stack *a_stack);
int		is_b_sorted(t_stack *b_stack);
void	sort_three_a(t_stack **stack);
void	sort_small(t_stack **a_stack, t_stack **b_stack);
void	sort_stack(t_stack **a_stack);

t_stack	*stack_find_last(t_stack *stack);
void	stack_append(t_stack **stack, int nbr);
void	stack_add_up(t_stack **stack, t_stack *new);
int		stack_size(t_stack *stack);

#endif