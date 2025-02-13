#include "push_swap.h"
#include "check_errors.c"
#include "actions.c"
#include "write_actions.c"
#include "display.c"
#include "sort.c"

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
			//current->precedent = current;
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

	tab = argv;
	//(void)argv;
	/*argc = 10;
	tab = (char **)malloc((argc + 1) *sizeof(char*));*/
	/*tab[1] = "2";
	tab[2] = "9";
	tab[3] = "8";
	tab[4] = "5";
	tab[5] = "4";
	tab[6] = "12";
	tab[7] = "7";*/
	/*tab[1] = "6";
	tab[2] = "18";
	tab[3] = "22";
	tab[4] = "3";
	tab[5] = "56";*/
	/*tab[1] = "4";
	tab[2] = "12";
	tab[3] = "22";
	tab[4] = "3";
	tab[5] = "5";
	tab[6] = "6";
	tab[7] = "71";
	tab[8] = "1";*/
	/*tab[1] = "5";
	tab[2] = "2";
	tab[3] = "7";
	tab[4] = "1";
	tab[5] = "6";
	tab[6] = "3";
	tab[7] = "9";
	tab[8] = "4";
	tab[9] = "8";*/
	

	//4 12 22 3 5 6 71 1
	//2 1 3 6 5 8
	if (argc > 1)
	{
		//ATTENTION PRENDRE EN COMPTE SI MIS ENTRE GUILLEMETS, CHANGER LES STRING EN INT (attention aux espaces + utiliser atoi)
		if (check_error(argc, tab) == 1)
			return (0);
		list_a = make_list(argc, tab);
		list_b = NULL;
		sort(&list_a, &list_b);
	}
}