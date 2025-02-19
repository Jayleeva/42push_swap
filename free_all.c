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
