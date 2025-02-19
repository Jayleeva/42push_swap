/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   action_swap.c                                       :+:    :+:           */
/*                                                      +:+                   */
/*   By: cyglardo <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/17 16:07:33 by cyglardo       #+#    #+#                */
/*   Updated: 2025/02/17 16:07:34 by cyglardo       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_node **head, char stack)
{
	t_node		*top;
	t_node		*second;

	top = *head;
	second = (*head)->next;
	top->next = (*head)->next->next;
	second->next = top;
	*head = second;
	if (stack != 'c')
		write_swap(stack);
}

void	ss(t_node **head_a, t_node **head_b)
{
	s(head_a, 'c');
	s(head_b, 'c');
	write(1, "ss\n", 3);
}
