#include "push_swap.h"

static int	is_number(int nelem, char **tab)
{
	int	i;
	int	j;

	i = 1;
	while (i < nelem)
	{
		j = 0;
		if (tab[i][0] == '-')
			j ++;
		while (tab[i][j])
		{
			if (tab[i][j] < '0' || tab[i][j] > '9')
			{
				write(1, "Error: not a number\n", 20);
				return (1);
			}
			j ++;
		}
		i ++;
	}
	return (0);
}

/*static int	is_int(int nelem, char **tab) // atoi corrige en un int...
{
	int		i;
	int		j;
	int		k;
	char	*num;

	num = (char *)malloc((9 + 1) * sizeof(char));
	if (num == NULL)
		return (1);
	num = "214748364";
	i = 1;
	while (i < nelem)
	{
		k = 0;
		j = 0;
		while (tab[i][j])
			j ++;
		if (tab[i][0] == '-')
			k = 1;
		if ((k == 0 && j > 10) || (k == 1 && j > 11))
		{
			write(1, "ErrorA: not an int\n", 19);
			return (1);
		}
		else if ((k == 0 && j == 10) || (k == 1 && j == 11))
		{
			j = k;
			while (tab[i][j] == num[j - k] && num[j -k]) //si tab[i] - le dernier char est égal à num, 
				j ++;
			if ((k == 0 && j == 9) || (k == 1 && j == 10))
			{
				if ((k == 0 && tab[i][j] > '7') || (k == 1 && tab[i][j] > '8')) // vérifier le dernier chiffre,
				{
					write(1, "ErrorC: not an int\n", 19);
					return (1);
				}
			}
			else  //sinon les précédents, en partant du premier.
			{
				j = k;
				while (num[j - k])
				{
					if (tab[i][j] > num[j -k])
					{
						write(1, "ErrorB: not an int\n", 19);
						return (1);
					}
					else if (tab[i][j] < num[j -k])
						break;
					else if (tab[i][j] == num[j -k])
						j ++;
				}
			}
		}
		i ++;
	}
	return (0);
}*/

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
				write(1, "Error: duplicate\n", 17);
				return (1);
			}
			j ++;
		}
		i ++;
	}
	return (0);
}

int	check_error(int nelem, char **tab) // ATTENTION PRENDRE EN COMPTE SI MIS ENTRE GUILLEMETS!!
{
	if (is_number(nelem, tab) == 1)
		return (1);
	//if (is_int(nelem, tab) == 1)
	//	return (1);
	if (is_duplicate(nelem, tab) == 1)
		return (1);
	return (0);
}