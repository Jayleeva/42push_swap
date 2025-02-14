#include "push_swap.h"

int	is_greater_than_all(node_t **head, int ref, int size)
{
	node_t  *current;
	
	current = *head;
	size = get_stack_size(head);
	while (size > 0)
	{
		if (ref > current->data)
			current = current->next;
		else
			break;
		size --;
	}
	if (size == 0)
		return (1);
	return (0);
}

int	is_smaller_than_all(node_t **head, int ref, int size)
{
	node_t  *current;

	current = *head;
	while (size > 0)
	{
		if (ref < current->data)
			current = current->next;
		else
			break;
		size --;
	}
	if (size == 0)
		return (1);
	return (0);
}

int is_greater_or_smaller_than_all(node_t **head, int ref)
{

	int     size;

	size = get_stack_size(head);
	if (is_smaller_than_all(head, ref, size))
		return (1);
	if (is_greater_than_all(head, ref, size))
		return (1);
	return (0);
}