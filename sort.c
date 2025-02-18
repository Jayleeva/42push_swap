/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   sort.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: cyglardo <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/17 16:06:11 by cyglardo       #+#    #+#                */
/*   Updated: 2025/02/17 16:06:12 by cyglardo       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node **head, char stack)
{
	t_node	*current;

	current = *head;
	while (current->next != NULL)
	{
		if (stack == 'a')
		{
			if (current->data > current->next->data)
				return (0);
		}
		current = current->next;
	}
	return (1);
}

void	five_or_less(t_node **a, t_node **b, int size_a)
{
	if (size_a < 2)
		return ;
	else if (size_a == 2)
		sort_2(a, 'a');
	else if (size_a == 3)
		sort_3(a, 'a');
	else if (size_a == 4)
	{
		put_to_top(a, 'a', find_min(a));
		pb(a, b);
		sort_3(a, 'a');
		finish(a, b, 4);
	}
	else if (size_a == 5)
	{
		put_to_top(a, 'a', find_min(a));
		pb(a, b);
		put_to_top(a, 'a', find_min(a));
		pb(a, b);
		sort_3(a, 'a');
		finish(a, b, 5);
	}
}

void	more_than_five(t_node **a, t_node **b, int size_a)
{
	int	cheapest;
	int	target;
	int	nelem;

	pb(a, b);
	pb(a, b);
	//display_list(a, b);
	nelem = get_stack_size(a);
	while (nelem > 3)
	{
		cheapest = find_cheapest(a, b, nelem);
		target = find_target(a, cheapest);
		put_to_top_and_push(a, b, cheapest, target);
		//display_list(a, b);
		nelem = get_stack_size(a);
	}
	sort_3(a, 'a');
	//display_list(a, b);
	nelem = get_stack_size(b);
	while (nelem > 0)
	{
		target = check_target(a, b);
		rotate_and_push(a, b, target);
		//display_list(a, b);
		nelem --;
	}
	put_to_top(a, 'a', find_min(a));
}

void	sort(t_node **a, t_node **b)
{
	int	size_a;

	size_a = get_stack_size(a);
	//display_list(a, b);
	if (is_sorted(a, 'a') == 1)
		return ;
	if (size_a <= 5)
		five_or_less(a, b, size_a);
	else
		more_than_five(a, b, size_a);
	//display_list(a, b);
}
