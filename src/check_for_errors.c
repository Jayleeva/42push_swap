/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   check_for_errors.c                                  :+:    :+:           */
/*                                                      +:+                   */
/*   By: cyglardo <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/20 13:26:58 by cyglardo       #+#    #+#                */
/*   Updated: 2025/02/20 13:27:00 by cyglardo       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_number(int nelem, char **tab, int start)
{
	int	i;
	int	j;

	i = start;
	while (i < nelem)
	{
		j = 0;
		if ((tab[i][0] == '-' || tab[i][0] == '+') && !tab[i][1])
			return (write_error());
		if (tab[i][0] == '-' || tab[i][0] == '+')
			j ++;
		while (tab[i][j])
		{
			if (tab[i][j] < '0' || tab[i][j] > '9')
				return (write_error());
			j ++;
		}
		i ++;
	}
	return (0);
}

static int	is_bigger_than_int(int k, int j, char *s, char *num)
{
	j = k;
	while (s[j] == num[j - k] && num[j - k])
		j ++;
	if ((k == 0 && j == 9) || (k == 1 && j == 10))
	{
		if ((k == 0 && s[j] > '7') || (k == 1 && s[j] > '8'))
			return (write_error());
	}
	else
	{
		while (num[j - k])
		{
			if (s[j] > num[j - k])
				return (write_error());
			else if (s[j] < num[j - k])
				break ;
			else if (s[j] == num[j - k])
				j ++;
		}
	}
	return (0);
}

static int	is_int(int nelem, char **tab, int start)
{
	int		j;
	int		k;
	char	*num;

	num = "214748364";
	while (start < nelem)
	{
		k = 0;
		if (tab[start][0] == '-')
			k = 1;
		j = 0;
		while (tab[start][j])
			j ++;
		if ((k == 0 && j > 10) || (k == 1 && j > 11))
			return (write_error());
		else if ((k == 0 && j == 10) || (k == 1 && j == 11))
			if (is_bigger_than_int(k, j, tab[start], num))
				return (1);
		start ++;
	}
	return (0);
}

static int	is_duplicate(int nelem, char **tab, int start)
{
	int	i;
	int	j;
	int	n;
	int	n2;

	i = start;
	while (i < nelem -1)
	{
		j = i +1;
		while (j < nelem)
		{
			n = atoi(tab[i]);
			n2 = atoi(tab[j]);
			if (n == n2)
				return (write_error());
			j ++;
		}
		i ++;
	}
	return (0);
}

int	has_error(int nelem, char **tab, int start)
{
	if (nelem == 0)
		return (write_error());
	if (is_number(nelem, tab, start) == 1)
		return (1);
	if (is_int(nelem, tab, start) == 1)
		return (1);
	if (is_duplicate(nelem, tab, start) == 1)
		return (1);
	return (0);
}
