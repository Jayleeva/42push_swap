#include "push_swap.h"

void    move_together(node_t **a, node_t **b, int elem_a, int elem_b)
{
	int	min;
	int size_a;
	int size_b;
	int	size;
	node_t	*stack;

	size_a = get_stack_size(a);
	size_b = get_stack_size(b);
	if (elem_a <= elem_b)
	{
		stack = *a;
		min = elem_a;
	}
	else if (elem_b < elem_a)
	{	
		stack = *b;
		min = elem_b;
	}
	if (elem_a <= size_a / 2 && elem_b <= size_b  / 2)
	{
		while (min)
		{
			rr(a, b);
			min --;
		}
	}
	else if (elem_a > size_a / 2 && elem_b > size_b / 2)
	{
		size = get_stack_size(&stack);
		while (size - min)
		{
			rrr(a, b);
			min ++;
		}
	}
}

void    put_to_top_and_push(node_t **a, node_t **b, int elem_a, int elem_b)
{
	int size_a;
	int size_b;

	size_a = get_stack_size(a);
	size_b = get_stack_size(b);
	if (elem_a == 0 && elem_b == 0)
	{
		pb(a, b);
		return;
	}
	else if ((elem_a <= size_a / 2 && elem_b <= size_a / 2) || (elem_a > size_a / 2 && elem_b > size_a / 2))
	{
		if (elem_a > 0 && elem_b > 0)
		{
			move_together(a, b, elem_a, elem_b);
			pb(a, b);
			return;
		}
	}
	if (elem_a <= size_a / 2)
		rotate_to_top(a, 'a', elem_a);
	else if (elem_a > size_a / 2)
		rev_rotate_to_top(a, 'a', size_a - elem_a);
	if (elem_b <= size_b / 2)
		rotate_to_top(b, 'b', elem_b);
	else if (elem_b > size_b / 2)
		rev_rotate_to_top(b, 'b', size_b - elem_b);
	pb(a, b);
}

int find_target(node_t **a, int cheapest)
{
	int target;
	int i;
	node_t  *top_a;

	top_a = *a;
	i = 0;
	while (i < cheapest)
	{
		top_a = top_a->next;
		i ++;
	}
	target = top_a->target;
	return (target);
}

int find_cheapest(node_t **a, node_t **b, int nelem)
{
	int cheapest;
	int cheapest_cost;
	int size_a;
	int i;
	node_t  *top_a;

	top_a = *a;
	i = 0;
	cheapest = 0;
	cheapest_cost = set_cost(top_a, b, nelem, 0);
	size_a = get_stack_size(a);
	while (size_a > 0)
	{
		if (cheapest_cost < 1) 
			break;
		if (set_cost(top_a, b, nelem, i) < cheapest_cost)
		{
			cheapest_cost = top_a->cost;
			cheapest = i;
		}
		top_a = top_a->next;
		i ++;
		size_a --;
	}
	return (cheapest);
}