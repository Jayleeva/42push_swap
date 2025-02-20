/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   write_in_terminal.c                                 :+:    :+:           */
/*                                                      +:+                   */
/*   By: cyglardo <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/17 16:06:33 by cyglardo       #+#    #+#                */
/*   Updated: 2025/02/17 16:06:34 by cyglardo       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_swap(char stack)
{
	if (stack == 'a')
		write(1, "sa\n", 3);
	else if (stack == 'b')
		write(1, "sb\n", 3);
}

void	write_rotate(char stack)
{
	if (stack == 'a')
		write(1, "ra\n", 3);
	else if (stack == 'b')
		write(1, "rb\n", 3);
}

void	write_rev_rotate(char stack)
{
	if (stack == 'a')
		write(1, "rra\n", 4);
	else if (stack == 'b')
		write(1, "rrb\n", 4);
}

int	write_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}
