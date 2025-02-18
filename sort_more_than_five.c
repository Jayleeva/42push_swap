#include "push_swap.h"

void	move_(t_node **a, t_node **b, int action, int min)
{
	int		size;

	if (action == 0)
	{
		while (min)
		{
			rr(a, b);
			min --;
		}
		return ;
	}
	else if (action == 1)
		size = get_stack_size(a);
	else
		size = get_stack_size(b);
	while (size - min)
	{
		rrr(a, b);
		min ++;
	}
}

void	move_together(t_node **a, t_node **b, int *elem_a, int *elem_b)
{
	int		min;
	int		action;
	int		size_a;
	int		size_b;

	size_a = get_stack_size(a);
	size_b = get_stack_size(b);
	if (*elem_a <= *elem_b)
		min = *elem_a;
	else
		min = *elem_b;
	if (*elem_a <= (size_a / 2) && *elem_b <= (size_b / 2))
		action = 0;
	else
	{
		if (min == *elem_a)
			action = 1;
		if (min == *elem_b)
			action = 2;
	}
	*elem_a -= min;
	*elem_b -= min;
	move_(a, b, action, min);
}

void	put_to_top_and_push(t_node **a, t_node **b, int elem_a, int elem_b)
{
	int	size_a;
	int	size_b;

	size_a = get_stack_size(a);
	size_b = get_stack_size(b);
	if (elem_a == 0 && elem_b == 0)
	{
		pb(a, b);
		return ;
	}
	else if ((elem_a <= (size_a / 2) && elem_b <= (size_b / 2)) ||
		(elem_a > (size_a / 2) && elem_b > (size_b / 2)))
	{
		if (elem_a > 0 && elem_b > 0)
		{
			move_together(a, b, &elem_a, &elem_b);
			while (elem_a > 0)
			{
				if (elem_a <= (size_a / 2) && elem_b <= (size_b / 2))
					rotate(a, 'a');
				else
					rev_rotate(a, 'a');
				elem_a--;
			}
			while (elem_b > 0)
			{
				if (elem_a <= (size_a / 2) && elem_b <= (size_b / 2))
					rotate(b, 'b');
				else
					rev_rotate(b, 'b');
				elem_b--;
			}
			pb(a, b);
			return ;
		}
	}
	if (elem_a <= (size_a / 2))
		rotate_to_top(a, 'a', elem_a);
	else if (elem_a > size_a / 2)
		rev_rotate_to_top(a, 'a', size_a - elem_a);
	if (elem_b <= size_b / 2)
		rotate_to_top(b, 'b', elem_b);
	else if (elem_b > size_b / 2)
		rev_rotate_to_top(b, 'b', size_b - elem_b);
	pb(a, b);
}
