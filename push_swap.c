#include "push_swap.h"
#include "check_errors.c"
#include "actions.c"
#include "write_actions.c"
#include "display.c"
#include "sort.c"
#include "sort_five_or_less.c"
#include "sort_more_than_five.c"
#include "push_back_to_a.c"
#include "compute_cost.c"
#include "is_greater_smaller.c"
#include "find_min_max.c"
#include "to_top.c"
#include "free_all.c"
#include "split.c"

int	get_stack_size(node_t **list)
{
	node_t	*current;
	int		i;
	i = 1;
	current = *list;
	while (current->next != NULL)
	{
		current = current->next;
		i ++;
	}
	return (i);
}

node_t	*make_list(int argc, char **argv, int start)
{
	node_t	*head;
	node_t	*current;
	int		i;

//définir une fin avec head->next (head = 1er élément): allouer l'espace pour head, donner la valeur à head->data avec atoi, nullifier head->next.
	head = (node_t *)malloc(sizeof(node_t));
	if (head == NULL)
		return (NULL);
	head->data = atoi(argv[start]);
	head->next = NULL;
//assigner toutes les ->data: grâce à ma fin-repère définie tout à l'heure, je peux remonter la chaîne: je vais jusqu'au dernier et lui alloue l'espace, puis assigne avec atoi, et je nullifie le ->next, pour que la prochaine itération remonte un cran.
	i = start + 1;
	current = head;
	while (i < argc)
	{
		while (current->next != NULL)
			current = current->next;
		current->next = (node_t *)malloc(sizeof(node_t));
		if(current->next == NULL)
			return (NULL);
		current->next->data = atoi(argv[i]);
		current->next->next = NULL;
		i ++;
	}
	return (head);
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

int	count_elem(char **tab)
{
	int	i;

	while (tab[i])
		i ++;
	return (i);
}

int	main(int argc, char **argv)
{
	node_t	*list_a;
	node_t	*list_b;
	char	**tab;
	int		start;

	tab = argv;
	//argc = 4;
	//tab = (char **)malloc((argc + 1) *sizeof(char*));
	/*tab[0] = "a.out";
	tab[1] = "33 2 4 55";*/
	/*tab[1] = "3";
	tab[2] = "2";
	tab[3] = "1";*/
	start = 1;
	if (argc > 1)
	{
		if (argc == 2)
		{
			if (has_space(tab[1]))
			{	
				start = 0;
				tab = ft_split(tab[1], ' ');
				argc = count_elem(tab);
				if (argc == 1)
					return (0);
			}
			else
				return (0);
		}
		if (check_error(argc, tab, start))
			return (0);
		list_a = make_list(argc, tab, start);
		list_b = NULL;
		sort(&list_a, &list_b);
		free_tab(tab);
		free_list(list_a);
	}
}