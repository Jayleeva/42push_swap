/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   sort_five_or_less.c                                 :+:    :+:           */
/*                                                      +:+                   */
/*   By: cyglardo <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/17 16:09:20 by cyglardo       #+#    #+#                */
/*   Updated: 2025/02/17 16:09:21 by cyglardo       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_node **head, char stack)
{
	if (is_sorted(head, stack) == 1)
		return ;
	s(head, stack);
	return ;
}

void	sort_3_util(t_node **head, char stack)
{
	t_node	*current;

	rev_rotate(head, stack);
	current = *head;
	if (current->data > current->next->data)
		s(head, stack);
}

void	sort_3(t_node **head, char stack)
{
	t_node	*current;

	current = *head;
	if (is_sorted(head, stack) == 1)
		return ;
	if (current->data > current->next->data)
	{
		if (current->next->data > current->next->next->data)
		{
			s(head, stack);
			rev_rotate(head, stack);
		}
		else
		{
			if (current->data > current->next->next->data)
				rotate(head, stack);
			else
				s(head, stack);
		}
	}
	else
		sort_3_util(head, stack);
}
