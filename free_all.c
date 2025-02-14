#include "push_swap.h"

void	free_all(node_t **list)
{
	node_t	*copy;
	node_t	*current;

	copy = *list;
	while (copy != NULL)
	{
		free(copy);
		current = copy->next;
		copy = current;
	}
}