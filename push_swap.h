/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   push_swap.h                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: cyglardo <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/17 16:05:54 by cyglardo       #+#    #+#                */
/*   Updated: 2025/02/17 16:05:55 by cyglardo       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"

typedef struct node
{
	int			data;
	struct node	*next;
	int			target;
	int			cost_to_top;
	int			cost_to_push;
	int			cost;
}				t_node;

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);

int		has_error(int nelem, char **tab, int start);
void	sort(t_node **a, t_node **b);
int		is_sorted(t_node **head, char stack);
void	five_or_less(t_node **a, t_node **b, int size_a);
void	more_than_five(t_node **a, t_node **b);

void	sort_2(t_node **head, char stack);
void	sort_3(t_node **head, char stack);

void	move_(t_node **a, t_node **b, int action, int min);
void	move_together(t_node **a, t_node **b, int *elem_a, int *elem_b);
void	put_to_top_and_push(t_node **a, t_node **b, int elem_a, int elem_b);
int		find_cheapest(t_node **a, t_node **b, int nelem);
int		find_target(t_node **a, int cheapest);

void	put_min_to_top(t_node **a, int nelem);
void	display_list(t_node **a, t_node **b);
int		get_stack_size(t_node **list);
void	s(t_node **head, char stack);
void	sa(t_node **head_a);
void	sb(t_node **head_b);
void	ss(t_node **head_a, t_node **head_b);
void	pa(t_node **head_a, t_node **head_b);
void	pb(t_node **head_a, t_node **head_b);
void	rotate(t_node **head, char stack);
void	ra(t_node **head_a);
void	rb(t_node **head_a);
void	rr(t_node **head_a, t_node **head_b);
void	rev_rotate(t_node **head, char stack);
void	rra(t_node **head_a);
void	rrb(t_node **head_a);
void	rrr(t_node **head_a, t_node **head_b);
void	sort(t_node **a, t_node **b);
void	write_swap(char stack);
void	write_rotate(char stack);
void	write_rev_rotate(char stack);
int		write_error();

void	finish(t_node **a, t_node **b, int size);
void	rotate_and_push(t_node **a, t_node **b, int target);
int		check_target(t_node **a, t_node **b);

void	set_cost_to_push(t_node *current_a, t_node **b);
int		set_cost(t_node *current_a, t_node **b, int size_a, int i);

int		is_greater_than_all(t_node **head, int ref, int size);
int		is_smaller_than_all(t_node **head, int ref, int size);
int		is_greater_or_smaller_than_all(t_node **head, int ref);

int		find_max(t_node **head);
int		find_min(t_node **head);

void	rev_rotate_to_top(t_node **head, char stack, int n);
void	rotate_to_top(t_node **head, char stack, int n);
void	swap_to_top(t_node **a, t_node **b, int elem_a, int elem_b);
void	put_to_top(t_node **head, char stack, int elem);

void	free_list(t_node *list);
#endif
