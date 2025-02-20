/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   compute_cost_to_push.c                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: cyglardo <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/17 16:07:08 by cyglardo       #+#    #+#                */
/*   Updated: 2025/02/17 16:07:09 by cyglardo       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_bottom(t_node **head, int size)
{
	t_node	*bottom;

	bottom = *head;
	while (size > 1)
	{
		bottom = bottom->next;
		size --;
	}
	return (bottom);
}

void	set_target(t_node *current_a, t_node **b, int ref, int size_b)
{
	int		i;
	t_node	*current_b;
	t_node	*bottom_b;

	current_b = *b;
	bottom_b = find_bottom(b, size_b);
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

void	set_cost_to_push(t_node *current_a, t_node **b)
{
	int		ref;
	int		i;
	int		size_b;

	ref = current_a->data;
	size_b = get_stack_size(b);
	i = size_b;
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
		set_target(current_a, b, ref, size_b);
}
