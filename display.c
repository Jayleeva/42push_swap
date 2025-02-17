#include "push_swap.h"

void	display_list(t_node **a, t_node **b)
{
	t_node	*current_a;
	t_node	*current_b;

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
		while (current_b->next != NULL)
		{
			printf(" %d\n", current_b->data);
			current_b = current_b->next;
		}
		printf(" %d\n", current_b->data);
	}
	printf("---\n b\n===========\n");
}
