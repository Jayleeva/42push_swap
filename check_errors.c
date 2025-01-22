#include "push_swap.h"

static int	is_number(int nelem, char **tab)
{
	int	i;
	int	j;

	i = 1;
	while (i < nelem)
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][0] == '-') //se fait plus d'une fois 
			{
				//write(1, "HEY", 3);
				j ++;
			}
			if (tab[i][j] < '0' || tab[i][j] > '9') // entre dans la condition quand n est composé de plus de 10 char, méme si c'est des chiffres
			{
				write(1, "Error: not numbers\n", 18);
				return (1);
			}
			j ++;
		}
		i ++;
	}
	return (0);
}

static int	is_int(int nelem, char **tab) //marche pas, le atoi corrige en un int...
{
	int	i;
	int	n;

	i = 1;
	while (i < nelem)
	{
		n = atoi(tab[i]);
		if (n < -2147483648 || n > 2147483647)
		{
			write(1, "Error: not an int\n", 18);
			return (1);
		}
		i ++;
	}
	return (0);
}

static int	is_duplicate(int nelem, char **tab)
{
	int	i;
	int	j;
	int	n;
	int	n2;

	i = 1;
	while (i < nelem -1)
	{
		j = i +1;
		while (j < nelem)
		{
			n = atoi(tab[i]);
			n2 = atoi(tab[j]);
			if (n == n2)
			{
				write(1, "Error: duplicates\n", 18);
				return (1);
			}
			j ++;
		}
		i ++;
	}
	return (0);
}

int	check_error(int nelem, char **tab)
{
	if (is_number(nelem, tab) == 1)
		return (1);
	if (is_int(nelem, tab) == 1)
		return (1);
	if (is_duplicate(nelem, tab) == 1)
		return (1);
	return (0);
}
