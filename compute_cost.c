#include "push_swap.h"

int	set_cost(t_node *current_a, t_node **b, int size_a, int i)
{
	int	size_b;
	int	j;
	int	k;

	size_b = get_stack_size(b);
	if (i <= size_a / 2)
		current_a->cost_to_top = i;
	else if (i > size_a / 2)
		current_a->cost_to_top = size_a - i;
	set_cost_to_push(current_a, b);
	j = current_a->target;
	k = 0;
	if (i > 0 && j > 0)
	{
		if ((i <= size_a / 2 && j <= size_b / 2) ||
			(i > size_a / 2 && j > size_b / 2))
		{
			current_a->cost_to_top = 0;
			current_a->cost_to_push = 0;
			if (i <= size_a / 2 && j <= size_b / 2)
			{
				if (i == j)
					k = i;
				else if (i < j)
				{
					k = i;
					current_a->cost_to_top = j - i;
				}
				else if (j < i)
				{
					k = j;
					current_a->cost_to_push = i - j;
				}
			}
			if (i > size_a / 2 && j > size_b / 2)
			{
				if (size_a - i == size_b - j)
					k = size_a - i;
				else if (size_a - i < size_b - j)
				{
					k = size_a - i;
					current_a->cost_to_push = (size_b - j) - k;
				}
				else if (size_b - j < size_a - i)
				{
					k = size_b - j;
					current_a->cost_to_top = (size_a - i) - k;
				}
			}
		}
	}
	current_a->cost = k + current_a->cost_to_top + current_a->cost_to_push;
	return (current_a->cost);
}