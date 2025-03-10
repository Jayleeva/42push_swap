/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   sort_more_than_five.c                               :+:    :+:           */
/*                                                      +:+                   */
/*   By: cyglardo <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/20 13:28:14 by cyglardo       #+#    #+#                */
/*   Updated: 2025/02/20 13:28:15 by cyglardo       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_together_util(t_node **a, t_node **b, int action, int nactions)
{
	if (action == 0)
	{
		while (nactions)
		{
			rr(a, b);
			nactions --;
		}
		return ;
	}
	while (nactions)
	{
		rrr(a, b);
		nactions --;
	}
}

static int	find_min_stack(int *elem_a, int *elem_b)
{
	int	min_stack;

	if (*elem_a <= *elem_b)
		min_stack = *elem_a;
	else
		min_stack = *elem_b;
	return (min_stack);
}

void	move_together(t_node **a, t_node **b, int *elem_a, int *elem_b)
{
	int		action;
	int		size_a;
	int		size_b;
	int		nactions;

	size_a = get_stack_size(a);
	size_b = get_stack_size(b);
	nactions = find_min_stack(elem_a, elem_b);
	if (*elem_a <= (size_a / 2) && *elem_b <= (size_b / 2))
	{
		action = 0;
		*elem_a -= nactions;
		*elem_b -= nactions;
	}
	else
	{
		action = 1;
		if ((size_a - *elem_a) <= (size_b - *elem_b))
			nactions = size_a - *elem_a;
		else
			nactions = size_b - *elem_b;
		*elem_a += nactions;
		*elem_b += nactions;
	}
	move_together_util(a, b, action, nactions);
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
	else if ((elem_a <= (size_a / 2) && elem_b <= (size_b / 2))
		|| (elem_a > (size_a / 2) && elem_b > (size_b / 2)))
	{
		if (elem_a > 0 && elem_b > 0)
			move_together(a, b, &elem_a, &elem_b);
	}
	if (elem_a <= (size_a / 2))
		rotate_to_top(a, 'a', elem_a);
	else
		rev_rotate_to_top(a, 'a', size_a - elem_a);
	if (elem_b <= size_b / 2)
		rotate_to_top(b, 'b', elem_b);
	else
		rev_rotate_to_top(b, 'b', size_b - elem_b);
	pb(a, b);
}
