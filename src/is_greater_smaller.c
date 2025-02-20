/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   is_greater_smaller.c                                :+:    :+:           */
/*                                                      +:+                   */
/*   By: cyglardo <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/17 16:08:08 by cyglardo       #+#    #+#                */
/*   Updated: 2025/02/17 16:08:08 by cyglardo       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_greater_than_all(t_node **head, int ref, int size)
{
	t_node	*current;

	current = *head;
	size = get_stack_size(head);
	while (size > 0)
	{
		if (ref > current->data)
			current = current->next;
		else
			break ;
		size --;
	}
	if (size == 0)
		return (1);
	return (0);
}

int	is_smaller_than_all(t_node **head, int ref, int size)
{
	t_node	*current;

	current = *head;
	while (size > 0)
	{
		if (ref < current->data)
			current = current->next;
		else
			break ;
		size --;
	}
	if (size == 0)
		return (1);
	return (0);
}

int	is_greater_or_smaller_than_all(t_node **head, int ref)
{
	int	size;

	size = get_stack_size(head);
	if (is_smaller_than_all(head, ref, size))
		return (1);
	if (is_greater_than_all(head, ref, size))
		return (1);
	return (0);
}
