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

node_t	*make_list(int argc, char **argv)
{
	node_t	*head;
	node_t	*current;
	int		i;

//définir une fin avec head->next (head = 1er élément): allouer l'espace pour head, donner la valeur à head->data avec atoi, nullifier head->next.
	head = (node_t *)malloc(sizeof(node_t));
	if (head == NULL)
		return (NULL);
	head->data = atoi(argv[1]);
	head->next = NULL;
//assigner toutes les ->data: grâce à ma fin-repère définie tout à l'heure, je peux remonter la chaîne: je vais jusqu'au dernier et lui alloue l'espace, puis assigne avec atoi, et je nullifie le ->next, pour que la prochaine itération remonte un cran.
	i = 2;
	current = head;
	while (i < argc)
	{
		while (current->next != NULL)
		{
			current->cost = 0;
			current = current->next;
		}
		current->next = (node_t *)malloc(sizeof(node_t));
		if(current->next == NULL)
			return (NULL);
		current->next->data = atoi(argv[i]);
		current->next->next = NULL;
		i ++;
	}
	return (head);
}

int	main(int argc, char **argv)
{
	node_t	*list_a;
	node_t	*list_b;
	char	**tab;
	char	**new_tab;

	tab = argv;
	if (argc > 1)
	{
		//ATTENTION PRENDRE EN COMPTE SI MIS ENTRE GUILLEMETS, CHANGER LES STRING EN INT (attention aux espaces + utiliser atoi)
		if (argc == 2)
			new_tab = ft_split(argv[1], ' ');
		else
			new_tab = tab;
		if (check_error(argc, new_tab) == 1)
			return (0);
		list_a = make_list(argc, new_tab);
		list_b = NULL;
		sort(&list_a, &list_b);
		free_all(list_a);
		//list_a = NULL;
	}
}