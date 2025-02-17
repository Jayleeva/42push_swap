/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   action_rotate.c                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: cyglardo <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/17 16:07:39 by cyglardo       #+#    #+#                */
/*   Updated: 2025/02/17 16:07:40 by cyglardo       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **head, char stack)
{
	t_node		*top;
	t_node		*current;

	top = *head;
	current = *head;
	while (current->next != NULL)
		current = current->next;
	*head = (*head)->next;
	current->next = top;
	top->next = NULL;
	if (stack != 'c')
		write_rotate(stack);
}

void	rr(t_node **head_a, t_node **head_b)
{	
	rotate(head_a, 'c');
	rotate(head_b, 'c');
	write(1, "rr\n", 3);
}

void	rev_rotate(t_node **head, char stack)
{
	t_node		*top;
	t_node		*bottom;
	t_node		*current;

	top = *head;
	current = *head;
	while (current->next->next != NULL)
		current = current->next;
	bottom = current->next;
	bottom->next = top;
	current->next = NULL;
	*head = bottom;
	if (stack != 'c')
		write_rev_rotate(stack);
}

void	rrr(t_node **head_a, t_node **head_b)
{
	rev_rotate(head_a, 'c');
	rev_rotate(head_b, 'c');
	write(1, "rrr\n", 4);
}
