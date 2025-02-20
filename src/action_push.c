/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   action_push.c                                       :+:    :+:           */
/*                                                      +:+                   */
/*   By: cyglardo <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/20 13:26:30 by cyglardo       #+#    #+#                */
/*   Updated: 2025/02/20 13:26:43 by cyglardo       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **head_a, t_node **head_b)
{
	t_node	*top_a;
	t_node	*top_b;

	top_b = *head_b;
	if (top_b == NULL)
		return ;
	*head_b = (*head_b)->next;
	top_a = *head_a;
	*head_a = top_b;
	(*head_a)->next = top_a;
	write(1, "pa\n", 3);
}

void	pb(t_node **head_a, t_node **head_b)
{
	t_node	*top_a;
	t_node	*top_b;
	t_node	*temp;

	top_a = *head_a;
	if (top_a == NULL)
		return ;
	temp = *head_a;
	*head_a = top_a->next;
	top_b = *head_b;
	*head_b = temp;
	(*head_b)->next = top_b;
	write(1, "pb\n", 3);
}
