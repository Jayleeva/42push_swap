/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   free_all.c                                          :+:    :+:           */
/*                                                      +:+                   */
/*   By: cyglardo <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/20 13:28:00 by cyglardo       #+#    #+#                */
/*   Updated: 2025/02/20 13:28:01 by cyglardo       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_node *list)
{
	t_node	*copy;
	t_node	*current;

	copy = list;
	while (copy != NULL)
	{
		current = copy->next;
		free(copy);
		copy = current;
	}
}
