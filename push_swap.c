/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   push_swap.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: cyglardo <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/17 16:05:46 by cyglardo       #+#    #+#                */
/*   Updated: 2025/02/17 16:05:48 by cyglardo       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*//#include "../libft/split.c"
#include "write_output.c"
#include "check_for_errors.c"
#include "action_swap.c"
#include "action_push.c"
#include "action_rotate.c"
#include "sort.c"
#include "sort_five_or_less.c"
#include "sort_more_than_five.c"
#include "get_stack_size.c"
#include "is_greater_smaller.c"
#include "find_min_max.c"
#include "compute_cost_to_top.c"
#include "compute_cost_to_push.c"
#include "find_cheapest_target.c"
#include "to_top.c"
#include "push_back_to_a.c"
#include "free_all.c"*/

static t_node	*make_list(int argc, char **argv, int start)
{
	t_node	*head;
	t_node	*current;
	int		i;

	head = (t_node *)malloc(sizeof(t_node));
	if (head == NULL)
		return (NULL);
	head->data = atoi(argv[start]);
	head->next = NULL;
	i = start + 1;
	current = head;
	while (i < argc)
	{
		while (current->next != NULL)
			current = current->next;
		current->next = (t_node *)malloc(sizeof(t_node));
		if (current->next == NULL)
			return (NULL);
		current->next->data = atoi(argv[i]);
		current->next->next = NULL;
		i ++;
	}
	return (head);
}

static int	count_elem(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i ++;
	return (i);
}

static void	treat(int argc, char **tab, int start)
{
	t_node	*list_a;
	t_node	*list_b;

	if (has_error(argc, tab, start))
		return ;
	list_a = make_list(argc, tab, start);
	list_b = NULL;
	sort(&list_a, &list_b);
	free_list(list_a);
}

int	main(int argc, char **argv)
{
	char	**tab;

	tab = argv;
	if (argc > 1)
	{
		if (argc == 2)
		{
			tab = ft_split(tab[1], ' ');
			argc = count_elem(tab);
			if (has_error(argc, tab, 0))
				return (0);
			if (argc == 1)
				return (0);
			treat(argc, tab, 0);
			free_tab(tab);
		}
		else
			treat(argc, tab, 1);
	}
}
