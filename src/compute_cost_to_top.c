/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   compute_cost_to_top.c                               :+:    :+:           */
/*                                                      +:+                   */
/*   By: cyglardo <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/20 13:27:20 by cyglardo       #+#    #+#                */
/*   Updated: 2025/02/20 13:27:22 by cyglardo       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_revrotate(t_node *current_a, int i, int size_a, int size_b)
{
	int	k;
	int	j;

	k = 0;
	j = current_a->target;
	if (size_a - i == size_b - j)
		k = size_a - i;
	else if (size_a - i < size_b - j)
	{
		k = size_a - i;
		current_a->cost_to_push = (size_b - j) - k;
	}
	else
	{
		k = size_b - j;
		current_a->cost_to_top = (size_a - i) - k;
	}
	return (k);
}

int	set_nrotate(t_node *current_a, int i)
{
	int	k;
	int	j;

	k = 0;
	j = current_a->target;
	if (i == j)
		k = i;
	else if (i < j)
	{
		k = i;
		current_a->cost_to_top = j - i;
	}
	else
	{
		k = j;
		current_a->cost_to_push = i - j;
	}
	return (k);
}

void	check_cost(t_node *current_a, int size_a, int size_b, int i)
{
	int	k;
	int	j;

	j = current_a->target;
	k = 0;
	if (i > 0 && j > 0)
	{
		if ((i <= size_a / 2 && j <= size_b / 2)
			|| (i > size_a / 2 && j > size_b / 2))
		{
			current_a->cost_to_top = 0;
			current_a->cost_to_push = 0;
			if (i <= size_a / 2 && j <= size_b / 2)
			{
				k = set_nrotate(current_a, i);
			}
			if (i > size_a / 2 && j > size_b / 2)
			{
				k = set_revrotate(current_a, i, size_a, size_b);
			}
		}
	}
	current_a->cost = k + current_a->cost_to_top + current_a->cost_to_push;
}

int	set_cost(t_node *current_a, t_node **b, int size_a, int i)
{
	int	size_b;

	size_b = get_stack_size(b);
	if (i <= size_a / 2)
		current_a->cost_to_top = i;
	else if (i > size_a / 2)
		current_a->cost_to_top = size_a - i;
	set_cost_to_push(current_a, b);
	check_cost(current_a, size_a, size_b, i);
	return (current_a->cost);
}
