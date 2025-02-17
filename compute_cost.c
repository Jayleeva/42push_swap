/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   compute_cost.c                                      :+:    :+:           */
/*                                                      +:+                   */
/*   By: cyglardo <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/17 16:07:08 by cyglardo       #+#    #+#                */
/*   Updated: 2025/02/17 16:07:09 by cyglardo       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cost_to_push(t_node *current_a, t_node **b)
{
	int		ref;
	int		i;
	int		size_b;
	t_node	*current_b;
	t_node	*bottom_b;

	ref = current_a->data;
	size_b = get_stack_size(b);
	i = size_b;
	current_b = *b;
	bottom_b = *b;
	while (i > 1)
	{
		bottom_b = bottom_b->next;
		i --;
	}
	if (is_greater_or_smaller_than_all(b, ref) == 1)
	{
		i = find_max(b);
		current_a->target = i;
		if (i <= size_b / 2)
			current_a->cost_to_push = i;
		else if (i > size_b / 2)
			current_a->cost_to_push = size_b - i;
	}
	else
	{
		if ((ref < bottom_b->data) && (ref > current_b->data))
		{
			current_a->cost_to_push = 0;
			current_a->target = 0;
			return ;
		}
		i = 1;
		while (!(ref < current_b->data && ref > current_b->next->data))
		{
			i ++;
			current_b = current_b->next;
		}
		current_a->target = i;
		if (i > size_b / 2)
			current_a->cost_to_push = size_b - i;
		else
			current_a->cost_to_push = i;
	}
}

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
