#include "push_swap.h"

void	s(node_t **head, char stack)
{
	node_t		*top;
	node_t		*second;

	top = *head;
	second = (*head)->next;
	top->next = (*head)->next->next;
	second->next = top;
	*head = second;
	if (stack != 'c')
		write_swap(stack);
}

void	ss(node_t **head_a, node_t **head_b)
{
	s(head_a, 'c');
	s(head_b, 'c');
	write(1, "ss\n", 3);
}

void	pa(node_t **head_a, node_t **head_b)
{
	node_t	*top_a;
	node_t	*top_b;

	top_b = *head_b;
	if (top_b == NULL)
		return;

	*head_b = (*head_b)->next;
	top_a = *head_a;
	*head_a = top_b;
	(*head_a)->next = top_a;
	write(1, "pa\n", 3);
}

void	pb(node_t **head_a, node_t **head_b)
{
	node_t	*top_a;
	node_t	*top_b;
	node_t	*temp;

	top_a = *head_a;
	if (top_a == NULL)
		return;
	temp = *head_a;
	*head_a = top_a->next;
	top_b = *head_b;
	*head_b = temp;
	(*head_b)->next = top_b;
	write(1, "pb\n", 3);
}

void	rotate(node_t **head, char stack)
{
	node_t		*top;
	node_t		*current;

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

void	rr(node_t **head_a, node_t **head_b)
{	
	rotate(head_a, 'c');
	rotate(head_b, 'c');
	write(1, "rr\n", 3);
}

void	rev_rotate(node_t **head, char stack)
{
	node_t		*top;
	node_t		*bottom;
	node_t		*current;

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

void	rrr(node_t **head_a, node_t **head_b)
{
	rev_rotate(head_a, 'c');
	rev_rotate(head_b, 'c');
	write(1, "rrr\n", 4);
}