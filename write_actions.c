#include "push_swap.h"

void    write_swap(char stack)
{
    if (stack == 'a')
        write(1, "sa\n", 3);
    else if (stack == 'b')
        write(1, "sb\n", 3);
}

void    write_rotate(char stack)
{
    if (stack == 'a')
        write(1, "ra\n", 3);
    else if (stack == 'b')
        write(1, "rb\n", 3);
}

void    write_rev_rotate(char stack)
{
    if (stack == 'a')
        write(1, "rra\n", 4);
    else if (stack == 'b')
        write(1, "rrb\n", 4);
}