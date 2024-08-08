#include "push_swap.h"

void	sort_three_a(t_stack **stack)
{
	int first;
	int middle;
	int last;

	first = (*stack)->value;
	middle = (*stack)->next->value;
	last = (*stack)->next->next->value;
	if (first < middle && first < last)
	{
		if (last < middle)
		{
			rotate_a(stack);
			swap_a(*stack);
			rotate_reverse_a(stack);
		}
	}	
	else if (middle < first && middle < last)
	{
		if (first < last)
			swap_a(*stack);
		else
		{
			rotate_reverse_a(stack);
			rotate_reverse_a(stack);
		}
	}
	else if (last < first && last < middle)
	{
		if(first < middle)
			rotate_reverse_a(stack);
		else
		{
			swap_a(*stack);
			rotate_reverse_a(stack);
		}
	}
}

void	sort_small(t_stack **a_stack, t_stack **b_stack)
{
	int size_a;
	int num1;
	int num2;
	int num3;
	int	rot_counter;

	size_a = stack_size(*a_stack);
	rot_counter = 0;
	while (size_a > 3)
	{
		push_b(a_stack, b_stack);
		size_a--;;
	}
	sort_three_a(a_stack);
	while(*b_stack)
	{
		num1 = (*a_stack)->value;
		num2 = (stack_find_last(*a_stack))->value;
		num3 = (*b_stack)->value;
		if(num3 < num1)
			push_a(a_stack, b_stack);
		else if (num3 > num2)
		{
			push_a(a_stack, b_stack);
			rotate_a(a_stack);
		}
		else
		{
			while(num3 > num1)
			{
				rot_counter++;
				rotate_a(a_stack);
				num1 = (*a_stack)->value;
			}
			push_a(a_stack, b_stack);
			while (rot_counter--)
				rotate_reverse_a(a_stack);
		}
	}
}
