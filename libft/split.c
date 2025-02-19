#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*copy;

	copy = (char *) malloc((ft_strlen(src) +1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i ++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	result = (char *)malloc((len +1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = start;
	j = 0;
	while (i < start + len)
	{
		result[j] = s[i];
		j ++;
		i ++;
	}
	result[j] = '\0';
	return (result);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i ++;
	}
	free(tab);
}

static char	*fill_tab(const char *array, char c)
{
	int		i;
	char	*s;

	i = 0;
	while (array[i] != c && array[i])
		i++;
	s = ft_substr(array, 0, i);
	return (s);
}

static int	get_nelem(char const *s, char c)
{
	int	nelem;
	int	i;

	i = 0;
	nelem = 0;
	while (s[i])
	{
		if ((i == 0 || s[i -1] == c) && s[i] != c)
			nelem ++;
		i ++;
	}
	return (nelem);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	tab = (char **)malloc((get_nelem(s, c) + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < get_nelem(s, c) && s[j])
	{
		if (s[j] != c)
		{
			tab[i] = fill_tab(s + j, c);
			if (tab[i] == NULL)
				return (free_tab(tab), NULL);
			j = j + ft_strlen(tab[i]);
			i ++;
		}
		else
			j++;
	}
	tab[i] = NULL;
	return (tab);
}
