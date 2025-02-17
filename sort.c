#include "push_swap.h"

int is_sorted(node_t **head, char stack)
{
	node_t  *current;

	current = *head;
	while (current->next != NULL)
	{
		if (stack == 'a')
		{
			if (current->data > current->next->data)
				return (0);
		}
		/*else if (stack == 'b')
		{
			if (current->data < current->next->data)
				return (0);
		}*/
		current = current->next;
	}
	return (1);
}

void    five_or_less(node_t **a, node_t **b, int size_a)
{
	if (size_a < 2)
		return;
	else if (size_a == 2)
		sort_2(a, 'a');
	else if (size_a == 3)
		sort_3(a, 'a');
	else if (size_a == 4)
	{
		put_to_top(a, 'a', find_min(a));
		pb(a, b);
		sort_3(a, 'a');
		finish(a, b, 4);
	}
	else if (size_a == 5)
	{
		put_to_top(a, 'a', find_min(a));
		pb(a, b);
		put_to_top(a, 'a', find_min(a));
		pb(a, b);
		sort_3(a, 'a');
		finish(a, b, 5);
	}
}

void    more_than_five(node_t **a, node_t **b, int size_a)
{
	int     cheapest;
	int     target;
	int     nelem;

	pb(a, b);
	pb(a, b);
	//display_list(a, b);
	nelem = size_a -2;
	while (nelem > 3)
	{
		cheapest = find_cheapest(a, b, nelem);
		target = find_target(a, cheapest);
		//printf("cheapest = %d, target = %d\n", cheapest, target);
		put_to_top_and_push(a, b, cheapest, target);
		//display_list(a, b);
		nelem --;
	}
	sort_3(a, 'a');
	//display_list(a, b);
	nelem = get_stack_size(b);
	while (nelem > 0)
	{
		target = check_target(a, b);
		rotate_and_push(a, b, target);
		//display_list(a, b);
		nelem --;
	}
	put_to_top(a, 'a', find_min(a));
}

void	sort(node_t **a, node_t **b)
{
	int size_a;

	size_a = get_stack_size(a);
	//display_list(a, b);
	if (is_sorted(a, 'a') == 1)
		return;
	if (size_a <= 5)
		five_or_less(a, b, size_a);
	else
		more_than_five(a, b, size_a);
	//display_list(a, b);
}
