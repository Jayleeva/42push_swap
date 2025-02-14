#include "push_swap.h"

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
	//if (stack == 'a')
	//{
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
	/*if (stack == 'b')
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
	}*/

