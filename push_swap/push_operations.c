#include "push_swap.h"

void	push_a(t_list **a_list, t_list **b_list)
{
	t_list	*aux;

	if (b_list && *b_list)
	{
		aux = *b_list;
		*b_list = aux->next;
		aux->next = NULL;
		ft_lstadd_front(a_list, aux);
		ft_printf("pa\n");
	}
}

void	push_b(t_list **a_list, t_list **b_list)
{
	t_list	*aux;

	if (a_list && *a_list)
	{
		aux = *a_list;
		*a_list = aux->next;
		aux->next = NULL;
		ft_lstadd_front(b_list, aux);
		ft_printf("pb\n");
	}
}
