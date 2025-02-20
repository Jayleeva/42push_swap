/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   find_cheapest_target.c                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: cyglardo <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/17 16:36:13 by cyglardo       #+#    #+#                */
/*   Updated: 2025/02/17 16:36:14 by cyglardo       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_target(t_node **a, int cheapest)
{
	int		target;
	int		i;
	t_node	*top_a;

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

int	find_cheapest(t_node **a, t_node **b, int nelem)
{
	int		cheapest;
	int		cheapest_cost;
	int		size_a;
	int		i;
	t_node	*top_a;

	top_a = *a;
	i = 0;
	cheapest = 0;
	cheapest_cost = set_cost(top_a, b, nelem, 0);
	size_a = get_stack_size(a);
	while (size_a > 0)
	{
		if (cheapest_cost < 1)
			break ;
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
