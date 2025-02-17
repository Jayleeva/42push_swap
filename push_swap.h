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

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);

int		check_error(int nelem, char **tab, int start);
void	sort(node_t **a, node_t **b);
int 	is_sorted(node_t **head, char stack);
void    five_or_less(node_t **a, node_t **b, int size_a);
void    more_than_five(node_t **a, node_t **b, int size_a);

void    sort_2(node_t **head, char stack);
void    sort_3(node_t **head, char stack);

void    move_together(node_t **a, node_t **b, int elem_a, int elem_b);
void    put_to_top_and_push(node_t **a, node_t **b, int elem_a, int elem_b);
int 	find_cheapest(node_t **a, node_t **b, int nelem);
int 	find_target(node_t **a, int cheapest);

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

void    finish(node_t **a, node_t **b, int size);
void	rotate_and_push(node_t **a, node_t **b, int target);
int		check_target(node_t **a, node_t **b);

void    set_cost_to_push(node_t *current_a, node_t **b);
int 	set_cost(node_t *current_a, node_t **b, int size_a, int i);

int		is_greater_than_all(node_t **head, int ref, int size);
int		is_smaller_than_all(node_t **head, int ref, int size);
int 	is_greater_or_smaller_than_all(node_t **head, int ref);

int 	find_max(node_t **head);
int 	find_min(node_t **head);

void    rev_rotate_to_top(node_t **head, char stack, int n);
void    rotate_to_top(node_t **head, char stack, int n);
void    swap_to_top(node_t **a, node_t **b, int elem_a, int elem_b);
void	put_to_top(node_t **head, char stack, int elem);

void	free_all(node_t *list);
#endif