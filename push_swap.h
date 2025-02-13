#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

typedef struct node
{
	int		data;
	struct	node *next;
	int		target;
	int		cost_to_top;
	int		cost_to_push;
	int		cost;
}			node_t;

int		check_error(int nelem, char **tab);
void	put_min_to_top(node_t **a, int nelem);
void	display_list(node_t **a, node_t **b);
int		get_stack_size(node_t **list);
void	s(node_t **head, char stack);
void	sa(node_t **head_a);
void	sb(node_t **head_b);
void	ss(node_t **head_a,node_t **head_b);
void	pa(node_t **head_a,node_t **head_b);
void	pb(node_t **head_a,node_t **head_b);
void	rotate(node_t **head, char stack);
void	ra(node_t **head_a);
void	rb(node_t **head_a);
void	rr(node_t **head_a, node_t **head_b);
void	rev_rotate(node_t **head, char stack);
void	rra(node_t **head_a);
void	rrb(node_t **head_a);
void	rrr(node_t **head_a, node_t **head_b);
void	sort(node_t **a, node_t **b);
void    write_swap(char stack);
void    write_rotate(char stack);
void    write_rev_rotate(char stack);

#endif