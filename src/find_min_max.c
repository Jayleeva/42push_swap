/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   find_min_max.c                                      :+:    :+:           */
/*                                                      +:+                   */
/*   By: cyglardo <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/20 13:27:46 by cyglardo       #+#    #+#                */
/*   Updated: 2025/02/20 13:27:47 by cyglardo       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_node **head)
{
	t_node	*current;
	int		max;
	int		i;
	int		j;
	int		size;

	current = *head;
	max = current->data;
	size = get_stack_size(head);
	i = 0;
	j = 0;
	while (size > 0)
	{
		if (current->data > max)
		{
			max = current->data;
			j = i;
		}
		current = current->next;
		i ++;
		size --;
	}
	return (j);
}

int	find_min(t_node **head)
{
	t_node	*current;
	int		min;
	int		i;
	int		j;
	int		size;

	current = *head;
	min = current->data;
	size = get_stack_size(head);
	i = 0;
	j = 0;
	while (size > 0)
	{
		if (current->data < min)
		{
			min = current->data;
			j = i;
		}
		current = current->next;
		i ++;
		size --;
	}
	return (j);
}
