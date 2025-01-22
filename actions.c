#include "push_swap.h"

void	sa(node_t *list_a)
{
	int	temp;
	//ne fait rien si moins de 2 elements
	temp = list_a->data;
	list_a->data = list_a->next->data;
	list_a->next->data = temp;
}

void	sb(node_t *list_b)
{
	int	temp;
	//ne fait rien si moins de 2 elements
	temp = list_b->data;
	list_b->data = list_b->next->data;
	list_b->next->data = temp;
}

void	ss(node_t *list_a, node_t *list_b)
{
	sa(list_a);
	sb(list_b);
}

void	pa(node_t *list_a, node_t *list_b)
{
	//si b est vide, ne rien faire
	node_t	*top;

	top =(node_t *)malloc(sizeof(node_t));
	if (top == NULL)
		return;
	top->data = list_b->data;
	list_a->precedent = top;
}

void	pb(node_t *list_a, node_t *list_b)
{
	//si a est vide, ne rien faire
	node_t	*top;

	top =(node_t *)malloc(sizeof(node_t));
	if (top == NULL)
		return;
	top->data = list_a->data;
	list_b->precedent = top;
}

void	ra(node_t *list_a)
{
	int		bottom;
	int		temp;

	bottom = list_a->data;
	while (list_a->next != NULL)
	{
		temp = list_a->data;
		list_a->data = list_a->next->data;
		list_a->next->data = temp;
		list_a = list_a->next;
	}
	list_a->data = bottom;
}

void	rb(node_t *list_b)
{
	int		bottom;
	int		temp;

	bottom = list_b->data;
	while (list_b->next != NULL)
	{
		temp = list_b->data;
		list_b->data = list_b->next->data;
		list_b->next->data = temp;
		list_b = list_b->next;
	}
	list_b->data = bottom;
}

void	rr(node_t *list_a, node_t *list_b)
{
	ra(list_a);
	rb(list_b);
}

void	rra(node_t *list_a)
{
	int		bottom;
	int		temp;

	bottom = list_a->data;
	while (list_a->next != NULL)
	{
		temp = list_a->data;
		list_a->data = list_a->next->data;
		list_a->next->data = temp;
		list_a = list_a->next;
	}
	list_a->data = bottom;
}