/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_stack_size.c                                    :+:    :+:           */
/*                                                      +:+                   */
/*   By: cyglardo <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/17 16:08:52 by cyglardo       #+#    #+#                */
/*   Updated: 2025/02/17 16:08:53 by cyglardo       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(t_node **list)
{
	t_node	*current;
	int		i;

	i = 1;
	current = *list;
	while (current->next != NULL)
	{
		current = current->next;
		i ++;
	}
	return (i);
}
