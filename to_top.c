/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   to_top.c                                            :+:    :+:           */
/*                                                      +:+                   */
/*   By: cyglardo <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/17 16:06:56 by cyglardo       #+#    #+#                */
/*   Updated: 2025/02/17 16:06:57 by cyglardo       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_to_top(t_node **head, char stack, int n)
{
	while (n > 0)
	{
		rev_rotate(head, stack);
		n --;
	}
}

void	rotate_to_top(t_node **head, char stack, int n)
{
	while (n > 0)
	{
		rotate(head, stack);
		n --;
	}
}

void	swap_to_top(t_node **a, t_node **b, int elem_a, int elem_b)
{
	if (elem_a == 1 && elem_b == 1)
		return ;
	else if (elem_a == 1)
		s(a, 'a');
	else if (elem_b == 1)
		s(b, 'b');
}

void	put_to_top(t_node **head, char stack, int elem)
{
	int		size;

	size = get_stack_size(head);
	if (elem <= size / 2)
	{
		while (elem)
		{
			rotate(head, stack);
			elem --;
		}
	}
	else
	{
		while (size - elem)
		{
			rev_rotate(head, stack);
			elem ++;
		}
	}
}
