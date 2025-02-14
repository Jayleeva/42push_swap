#include "push_swap.h"

int find_max(node_t **head)
{
	node_t  *current;
	int     max;
	int		i;
	int     j;
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

int find_min(node_t **head)
{
	node_t  *current;
	int     min;
	int		i;
	int     j;
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