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

int	has_space(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			return (1);
		i ++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	**tab;
	int	nelem;
	int	must_free;

	tab = argv;
	nelem = argc;
	must_free = 0;
	if (argc > 1)
	{
		while (nelem)
		{
			tab = "";
			if (has_space(argv[nelem + 1])
			{
				must_free = 1;
				tab = ft_strjoin(tab, ft_split(argv[1], ' '));
				argc = count_elem(tab);
			}
			nelem --;
		}
		if (argc == 1)
		{
			if (must_free)
				return (free_tab(tab), 0);
			else
				return (0);
		}
		if (has_error(argc, tab, 0))
		{
			if (must_free)
				return (free_tab(tab), 0);
			else
				return (0);
		}
		if (must_free)
		{
			treat(argc, tab, 0);
			free_tab(tab);
		}
		else
			treat(argc, tab, 1);
	}
}
