#include "push_swap.h"

void    rev_rotate_to_top(node_t **head, char stack, int n)
{
	while (n > 0)
	{
		rev_rotate(head, stack);
		n --;
	}
}

void    rotate_to_top(node_t **head, char stack, int n)
{
	while (n > 0)
	{
		rotate(head, stack);
		n --;
	}
}

void    swap_to_top(node_t **a, node_t **b, int elem_a, int elem_b)
{
	if (elem_a == 1 && elem_b == 1)
		return;
	else if (elem_a == 1)
		s(a, 'a');
	else if (elem_b == 1)
		s(b,'b');
}

void	put_to_top(node_t **head, char stack, int elem)
{
	int		size;

	size = get_stack_size(head);
	if (elem <= size / 2)
	{
		while (elem)
		{
			rotate(head, stack);
			elem --;
		}
	}
	else
	{
		while (size - elem)
		{
			rev_rotate(head, stack);
			elem ++;
		}
	}
}