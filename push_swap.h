#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct node
{
	int		data;
	struct	node *next;
	struct 	node *precedent;
	
	/*t_list	*next;
	t_list	*precedent;*/
}			node_t;

int	check_error(int nelem, char **tab);
void	ra(node_t *list_a);

#endif