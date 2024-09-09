#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	*biggest;

	biggest = get_biggest(*stack);
	if ((*stack)->value == biggest->value)
		rotate_a(stack);
	else if ((*stack)->next->value == biggest->value)
		rotate_reverse_a(stack);
	if ((*stack)->value > (*stack)->next->value)
		swap_a(*stack);
}

void	sort_bubble_alg(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;
	int		temp;
	int		swapped;

	if (!stack || !(*stack))
		return ;
	swapped = 0;
	current = *stack;
	while (swapped)
	{
		swapped = 0;
		current = *stack;
		while (current->next)
		{
			next = current->next;
			if (current->value > next->value)
			{
				temp = current->value;
				current->value = next->value;
				next->value = temp;
				swapped = 1;
			}
			current = current->next;
		}
	}
}

void	sort_small(t_stack **stack)
{
	int	size;

	size = stack_size(*stack);
	if (size <= 1)
		return ;
	if (size == 2)
	{
		if ((*stack)->value > (*stack)->next->value)
			swap_a(*stack);
	}
	else if (size <= 5)
		sort_bubble_alg(stack);
}
