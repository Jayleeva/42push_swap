#include "push_swap.h"

void    finish(node_t **a, node_t **b, int size)
{
	int	i;

	i = size;
	while (i > 0)
	{
		pa(a, b);
		i --;
	}
}

void	rotate_and_push(node_t **a, node_t **b, int target)
{
	//int	t;
	int	size_a;

	//t = target;
	size_a = get_stack_size(a);	
	if (target <= size_a / 2)
	{	
		while (target > 0)
		{
			rotate(a, 'a');
			target --;
		}
	}
	else
	{	
		while (size_a - target)
		{
			rev_rotate(a, 'a');
			target ++;
		}
	}
	pa(a, b);
}

int	check_target(node_t **a, node_t **b)
{
	node_t	*current_a;
	node_t	*bottom_a;
	int		ref;
	int		target;

	current_a = *a;
	bottom_a = *a;
	while (bottom_a->next)
		bottom_a = bottom_a->next;
	ref = (*b)->data;
	target = 0;
	if (is_greater_or_smaller_than_all(a, ref))
		return (target = find_min(a));
	if ((ref < current_a->data && ref > bottom_a->data))
		return (target);
	while (!(ref > current_a->data && ref < current_a->next->data))
	{
		target ++;
		current_a = current_a->next;
	}
	return (target + 1);
}