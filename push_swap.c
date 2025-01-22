#include "push_swap.h"

void	display_list(node_t *a, node_t *b)
{
	node_t	*current_a;
	node_t	*current_b;

	current_a = a;
	current_b = b;
	printf("\n");
	while (current_a->next != NULL && current_b->next != NULL)
	{
		printf(" %d\t\t\t %d\n", current_a->data, current_b->data);
		current_a = current_a->next;
		current_b = current_b->next;
	}
	printf(" %d\t\t\t %d\n", current_a->data, current_b->data);
	printf("---\t\t\t---\n a\t\t\t b\n");
}

/*t_list	sort(t_list **a, t_list **b)
{
	
}*/

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
			current->precedent = current;
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

int	get_nelem(char *str) 
{
	int	n;
	int	temp;
	int	nelem;

	n = atoi(str);
	temp = n;
	nelem = 0;
	if (n < 0)
	{
		if (n == -2147483648)
			temp ++; 
		temp = temp * -1;
		nelem ++;
	}
	while (temp > 0)
	{
		temp = temp / 10;
		nelem ++;
	}
	return (nelem);
}

char	**cpy_tab(int nelem, char **a)
{
	int		i;
	char	**b;

	b = (char **)malloc((nelem + 1) * sizeof(char*));
	if (b == NULL)
		return (NULL);
	i = 0;
	while (i < nelem)
	{
		b[i] = (char *)malloc((get_nelem(a[i]) +1) * sizeof(char));
		if (b[i] == NULL)
			return(free(b), NULL);
		i ++;
	}
	b[i] = 0;
	/*i = 0;
	while (b[i])
	{
		b[i] = " ";
		i ++;
	}*/
	return (b);
}

int	main(int argc, char **argv)
{
	char	**b;
	node_t	*list_a;
	node_t	*list_b;

	char	*action;

	//action = ["sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"];
	if (argc > 1)
	{
		action = (char *)malloc((3 +1) * sizeof(char));
		if (action == NULL)
			return (0);
		if (check_error(argc, argv) == 1)
			return (0);
		b = cpy_tab(argc, argv);
		if (b == NULL)
			return (0);
		list_a = make_list(argc, argv);
		list_b = make_list(argc, b);
		display_list(list_a, list_b);
		ra(list_a);
		display_list(list_a, list_b);
		//sort(list_a, list_b);
		/*action = "sa";
		if (strcmp(action, "sa") == 0)
			argv = sa(argv);
		display_action(argc, argv, b, action);*/
	}
}