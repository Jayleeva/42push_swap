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
		else if (stack == 'b')
		{
			if (current->data < current->next->data)
				return (0);
		}
		current = current->next;
	}
	return (1);
}

void    sort_2(node_t **head, char stack)
{
	if (is_sorted(head, stack) == 1)
		return;
	s(head, stack);
	return;
}

void    sort_3(node_t **head, char stack)
{
	node_t  *current;

	current = *head;
	if (is_sorted(head, stack) == 1)
		return;
	if (stack == 'a')
	{
		if (current->data > current->next->data)
		{
			if (current->next->data > current->next->next->data)
			{
				s(head, stack);
				rev_rotate(head, stack); 
			}
			else
			{
				if (current->data > current->next->next->data)
					rotate(head, stack); 
				else
					s(head, stack); 
			}
		}
		else
		{
			rev_rotate(head, stack);
			current = *head;
			if (current->data > current->next->data)
				s(head, stack); 
		}
	}
	if (stack == 'b')
	{
		if (current->data < current->next->data)
		{
			if (current->next->data < current->next->next->data)
			{
				s(head, stack);
				rev_rotate(head, stack); 
			}
			else
			{
				if (current->data < current->next->next->data)
					rotate(head, stack); 
				else
					s(head, stack); 
			}
		}
		else
		{
			rev_rotate(head, stack);
			current = *head;
			if (current->data < current->next->data)
				s(head, stack); 
		}
	}
}

int find_max(node_t **head, int size)
{
	node_t  *current;
	int     max;
	int		i;
	int     j;

	current = *head;
	max = current->data;
	i = 0;
	j = 0;
	while (i < size)
	{
		if (current->data > max)
		{
			max = current->data;
			j = i;
		}
		current = current->next;
		i ++;
	}
	return (j);
}

int find_min(node_t **head)
{
	node_t  *current;
	node_t  *bottom;
	int     min;
	int		i;
	int     j;

	current = *head;
	bottom = *head;
	while (bottom->next)
		bottom = bottom->next;
	min = current->data;
	i = 0;
	j = 0;
	while (current != bottom)
	{
		if (current->data < min)
		{
			min = current->data;
			j = i;
		}
		current = current->next;
		i ++;
	}
	if (bottom->data < min)
		j = i + 1;
	return (j);
}

void    rev_rotate_to_top(node_t **head, char stack, int n)
{
	while (n > 0)
	{
		rev_rotate(head, stack);
		n --;
	}
}

void    rotate_to_top(node_t **head, char stack, int n)
{
	while (n > 0)
	{
		rotate(head, stack);
		n --;
	}
}

void    swap_to_top(node_t **a, node_t **b, int elem_a, int elem_b)
{
	if (elem_a == 1 && elem_b == 1)
		return;
	else if (elem_a == 1)
		s(a, 'a');
	else if (elem_b == 1)
		s(b,'b');
}

void    move_together(node_t **a, node_t **b, int elem_a, int elem_b)
{
	int	min;
	int size_a;
	int size_b;
	int	size;
	node_t	*stack;

	size_a = get_stack_size(a);
	size_b = get_stack_size(b);
	if (elem_a <= elem_b)
	{
		stack = *a;
		min = elem_a;
	}
	else if (elem_b < elem_a)
	{	
		stack = *b;
		min = elem_b;
	}
	if (elem_a <= size_a / 2 && elem_b <= size_b  / 2)
	{
		while (min)
		{
			rr(a, b);
			min --;
		}
	}
	else if (elem_a > size_a / 2 && elem_b > size_b / 2)
	{
		size = get_stack_size(&stack);
		while (size - min)
		{
			rrr(a, b);
			min ++;
		}
	}
}

void    put_to_top_and_push(node_t **a, node_t **b, int elem_a, int elem_b)
{
	int size_a;
	int size_b;

	size_a = get_stack_size(a);
	size_b = get_stack_size(b);
	if (elem_a == 0 && elem_b == 0)
	{
		pb(a, b);
		return;
	}
	else if ((elem_a <= size_a / 2 && elem_b <= size_a / 2) || (elem_a > size_a / 2 && elem_b > size_a / 2))
	{
		if (elem_a > 0 && elem_b > 0)
		{
			move_together(a, b, elem_a, elem_b);
			pb(a, b);
			return;
		}
	}
	if (elem_a <= size_a / 2)
		rotate_to_top(a, 'a', elem_a);
	else if (elem_a > size_a / 2)
		rev_rotate_to_top(a, 'a', size_a - elem_a);
	if (elem_b <= size_b / 2)
		rotate_to_top(b, 'b', elem_b);
	else if (elem_b > size_b / 2)
		rev_rotate_to_top(b, 'b', size_b - elem_b);
	pb(a, b);
}

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
		put_min_to_top(a, 4);
		pb(a, b);
		//min = find_min(a);
		//put_to_top_and_push(a, b, min, 0);
		sort_3(a, 'a');
		finish(a, b, 4);
	}
	else if (size_a == 5)
	{
		//min = find_min(a);
		put_min_to_top(a, 5);
		pb(a, b);
		put_min_to_top(a, 4);
		pb(a, b);
		//put_to_top_and_push(a, b, min, 0);
		//min = find_min(a);
		//put_to_top_and_push(a, b, min, 0);
		sort_3(a, 'a');
		finish(a, b, 5);
	}
}

int is_greater_or_smaller_than_all(node_t **head, int ref)
{
	node_t  *current;
	int     size;

	current = *head;
	size = get_stack_size(head);
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

void    set_cost_to_push(node_t *current_a, node_t **b)
{
	int     ref;
	int     i;
	int     size_b;
	node_t  *current_b;
	node_t  *bottom_b;

	ref = current_a->data;
	size_b = get_stack_size(b);
	i = size_b;
	current_b = *b;
	bottom_b = *b;
	while (i > 1)
	{
		bottom_b = bottom_b->next;
		i --;
	}
	if (is_greater_or_smaller_than_all(b, ref) == 1)
	{
		i = find_max(b, size_b);
		current_a->target = i;
		if (i <= size_b / 2)
			current_a->cost_to_push = i;
		else if (i > size_b / 2)
			current_a->cost_to_push = size_b - i;
	}
	else
	{
		if ((ref < bottom_b->data) && (ref > current_b->data))
		{
			current_a->cost_to_push = 0;
			current_a->target = 0;
			return;
		}
		i = 1;
		while (!(ref < current_b->data && ref > current_b->next->data))
		{
			i ++;
			current_b = current_b->next;
		}
		current_a->target = i;
		if (i > size_b / 2)
			current_a->cost_to_push = size_b - i;
		else
			current_a->cost_to_push = i;
	}

}

int set_cost(node_t *current_a, node_t **b, int size_a, int i)
{
	int size_b;
	int j;
	int k;

	size_b = get_stack_size(b);
	if (i <= size_a / 2)
		current_a->cost_to_top = i;
	else if (i > size_a / 2)
		current_a->cost_to_top = size_a - i;
	set_cost_to_push(current_a, b);
	j = current_a->target;
	k = 0;
	if (i > 0 && j > 0)
	{
		if ((i <= size_a / 2 && j <= size_b / 2) || (i > size_a / 2 && j > size_b / 2)) 
		{
			current_a->cost_to_top = 0;
			current_a->cost_to_push = 0;
			if (i <= size_a / 2 && j <= size_b / 2)
			{
				if (i == j)
					k = i;
				else if (i < j)
				{
					k = i;
					current_a->cost_to_top = j - i;
				}
				else if (j < i)
				{
					k = j;
					current_a->cost_to_push = i - j;
				}
			}
			if (i > size_a / 2 && j > size_b / 2)
			{
				if (size_a - i == size_b - j) 
					k = size_a - i;
				else if (size_a - i < size_b - j) 
				{
					k = size_a - i;
					current_a->cost_to_push = (size_b - j) - k;
				}
				else if (size_b - j < size_a - i)
				{
					k = size_b - j;
					current_a->cost_to_top = (size_a - i) - k;
				}
			}
		}
		/*else
		{
			if (i <= size_a / 2)
				current_a->cost_to_top = i;
			else if (i > size_a / 2)
				current_a->cost_to_top = size_a - i;
			if (j <= size_b / 2)
				current_a->cost_to_push = j;
			else if (j > size_b / 2)
				current_a->cost_to_push = size_b - j;
		}*/
	}
	current_a->cost = k + current_a->cost_to_top + current_a->cost_to_push;    
	return (current_a->cost); // le 8 a le bon cost mais provoque une boucle infinie.
}

int find_target(node_t **a, int cheapest)
{
	int target;
	int i;
	node_t  *top_a;

	top_a = *a;
	i = 0;
	while (i < cheapest)
	{
		top_a = top_a->next;
		i ++;
	}
	target = top_a->target;
	return (target);
}

int find_cheapest(node_t **a, node_t **b, int nelem)
{
	int cheapest;
	int cheapest_cost;
	int size_a;
	int i;
	node_t  *top_a;

	top_a = *a;
	i = 0;
	cheapest = 0;
	cheapest_cost = set_cost(top_a, b, nelem, 0);
	size_a = get_stack_size(a);
	while (size_a > 0)
	{
		if (cheapest_cost < 1) 
			break;
		if (set_cost(top_a, b, nelem, i) < cheapest_cost)
		{
			cheapest_cost = top_a->cost;
			cheapest = i;
		}
		top_a = top_a->next;
		i ++;
		size_a --;
	}
	return (cheapest);
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

void	put_min_to_top(node_t **a, int nelem)
{
	int	min;

	min = find_min(a);
	if (min <= nelem / 2)
	{
		while (min)
		{
			rotate(a, 'a');
			min --;
		}
	}
	else
	{
		while (nelem - min)
		{
			rev_rotate(a, 'a');
			min ++;
		}
	}
}

void    more_than_five(node_t **a, node_t **b, int size_a)
{
	int     cheapest;
	int     target;
	int     nelem;
	int     total;

	total = size_a;
	pb(a, b);
	pb(a, b);
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
	put_min_to_top(a, total);

	//finish(a, b, total);
}

void	sort(node_t **a, node_t **b)
{
	int size_a;

	size_a = get_stack_size(a);
	display_list(a, b);
	if (is_sorted(a, 'a') == 1)
		return;
	if (size_a <= 5)
		five_or_less(a, b, size_a);
	else
		more_than_five(a, b, size_a);
	display_list(a, b);
}
