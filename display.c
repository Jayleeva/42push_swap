#include "push_swap.h"

void	display_list(node_t **a, node_t **b)
{
	node_t	*current_a;
	node_t	*current_b;

	current_a = *a;
	current_b = *b;
	if (current_a != NULL)
	{
		while (current_a->next != NULL)
		{
			printf(" %d\n", current_a->data);
			current_a = current_a->next;
		}
		printf(" %d\n", current_a->data);
	}
	printf("---\n a\n\n***\n\n");
	if (current_b != NULL)
	{
		//write(1, "* 1\n", 4);
		while (current_b->next != NULL)
		{
			//write(1, "* 2\n", 4);
			printf(" %d\n", current_b->data);
			current_b = current_b->next;
		}
		//write(1, "* 3\n", 4);
		printf(" %d\n", current_b->data);
	}
	printf("---\n b\n===========\n");
}