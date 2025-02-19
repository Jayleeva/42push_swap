#include "push_swap.h"

int	set_nrevrotate(t_node *current_a, int i, int size_a, int size_b)
{
	int	j;
	int	k;

	j = current_a->target;
	k = 0;
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
	return (k);
}

int	set_nrotate(t_node *current_a, int i)
{
	int	j;
	int	k;

	j = current_a->target;
	k = 0;
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
	return (k);
}

void	check_cost(t_node *current_a, t_node **b, int size_a, int i)
{
	int	j;
	int	k;
	int	size_b;
	int	median_a;
	int	median_b;

	size_b = get_stack_size(b);
	median_a = size_a / 2;
	median_b = size_b / 2;
	j = current_a->target;
	k = 0;
	if (i > 0 && j > 0)
	{
		if ((i <= median_a && j <= median_b) ||
			(i > median_a && j > median_b))
		{
			current_a->cost_to_top = 0;
			current_a->cost_to_push = 0;
			if (i <= median_a && j <= median_b)
				k = set_nrotate(current_a, i);
			else if (i > median_a && j > median_b)
				k = set_nrevrotate(current_a, i, size_b, size_b);
		}
	}
	current_a->cost = k + current_a->cost_to_top + current_a->cost_to_push;
}

int	set_cost(t_node *current_a, t_node **b, int size_a, int i)
{
	if (i <= size_a / 2)
		current_a->cost_to_top = i;
	else if (i > size_a / 2)
		current_a->cost_to_top = size_a - i;
	set_cost_to_push(current_a, b);
	check_cost(current_a, b, size_a, i);
	return (current_a->cost);
}