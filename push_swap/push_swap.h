/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brchaves <brchaves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:21:49 by brchaves          #+#    #+#             */
/*   Updated: 2024/09/06 12:26:39 by brchaves         ###   ########.fr       */
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
	int				push_price;
	int				above_median;
	int				cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;	

int				is_integer(char c);
int				check_is_num(char **array);
int				check_is_int(char **array);
int				check_duplicates(char **array);
void			check_error(char **array);

void			swap_lst(t_stack *lst);
void			swap_a(t_stack	*a_stack);
void			swap_b(t_stack	*b_stack);
void			swap_s(t_stack	*a_stack, t_stack *b_stack);

void			push_a(t_stack	**a_stack, t_stack **b_stack);
void			push_b(t_stack	**a_stack, t_stack **b_stack);

void			rotate_lst(t_stack **stack);
void			rotate_a(t_stack **a_stack);
void			rotate_b(t_stack **b_stack);
void			rotate_r(t_stack **a_stack, t_stack **b_stack);

void			rotate_reverse_lst(t_stack **stack);
void			rotate_reverse_a(t_stack **a_stack);
void			rotate_reverse_b(t_stack **b_stack);
void			rotate_reverse_r(t_stack **a_stack, t_stack **b_stack);

int				is_sorted(t_stack *stack);
void    		set_all_attributes(t_stack *a_stack, t_stack *b_stack);
void			push_swap(t_stack **a_stack, t_stack **b_stack);
void			sort_three(t_stack **stack);
void			sort_small(t_stack **a_stack);

t_stack			*stack_find_last(t_stack *stack);
void			stack_append(t_stack **stack, int nbr);
void			stack_add_up(t_stack **stack, t_stack *new);
unsigned int	stack_size(t_stack *stack);

t_stack			*populate_stack_a(char **array);
void			free_stack(t_stack **stack);
void			free_array(char **array);
void    		free_all(t_stack **stack, char **array);

t_stack 		*get_biggest(t_stack *stack);
t_stack 		*get_smallest(t_stack *stack);
t_stack 		*get_cheapest(t_stack *stack);
void			put_ascendent_order(t_stack **a_stack);

void    		set_position(t_stack *stack);
void    		set_above_median(t_stack *stack);
void    		set_push_price(t_stack *a_stack, t_stack *b_stack);
void    		set_cheapest(t_stack *b_stack);
void    		set_target_node(t_stack *a_stack, t_stack *b_stack);

void			move_cheapest_up(t_stack **b_stack, t_stack *cheapest_node);
void			move_target_up(t_stack  **a_stack, t_stack *target_node);
void			move_both_up(t_stack  **a_stack, t_stack **b_stack, t_stack *cheapest_node, t_stack *target_node);
void			move_nodes(t_stack  **a_stack, t_stack **b_stack, t_stack *cheapest_node);


#endif