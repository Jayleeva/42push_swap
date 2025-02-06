#include "push_swap.h"

int is_sorted(node_t **head, char stack)
{
    node_t  *current;

    current = *head;
    while (current->next != NULL)
    {
        if (stack == 'a')
        {
            if (current->data > current->next->data)
                return (0);
        }
        else if (stack == 'b')
        {
            if (current->data < current->next->data)
                return (0);
        }
        current = current->next;
    }
    return (1);
}

void    sort_2(node_t **head, char stack)
{
    if (is_sorted(head, stack) == 1)
        return;
    s(head, stack);
    return;
}

void    sort_3(node_t **head, char stack)
{
    node_t  *current;

    current = *head;
    if (is_sorted(head, stack) == 1)
        return;
    if (current->data > current->next->data)
    {
        if (current->next->data > current->next->next->data)
        {
            s(head, stack);
            rev_rotate(head, stack); 
        }
        else
        {
            if (current->data > current->next->next->data)
                rotate(head, stack); 
            else
                s(head, stack); 
        }
    }
    else
    {
        rev_rotate(head, stack);
        current = *head;
        if (current->data > current->next->data)
            s(head, stack); 
    }
}


int find_max(node_t **head, int size)
{
    node_t  *current;
    int     max;
	int		i;
    int     j;

    current = *head;
    max = current->data;
	i = 0;
    j = 0;
    while (i < size)
    {
        if (current->data > max)
        {
            max = current->data;
            j = i;
        }
        current = current->next;
		i ++;
    }
    return (j);
}

int find_min(node_t **head, int size)
{
    node_t  *current;
    int     min;
	int		i;
    int     j;

    current = *head;
    min = current->data;
	i = 0;
    j = 0;
    while (i < size)
    {
        if (current->data < min)
        {
            min = current->data;
            j = i;
        }
        current = current->next;
		i ++;
    }
    return (j);
}


//void    push_min(node_t **a, node_t **b, int min)
void    rotate_to_top_and_push(node_t **a, node_t **b, int elem)
{
    //printf("MIN = %d\n", min);
    if (elem == 0)
    {
        pb(a, b);
        return;
    }
    if (elem == 1)
        s(a, 'a');
    else if (elem > get_stack_size(a) / 2)
    {
        while (get_stack_size(a) - elem)
        {
            rev_rotate(a, 'a');
            elem ++;
        }
    }
    else if (elem <= get_stack_size(a) / 2)
    {
        while (elem)
        {
            rotate(a, 'a');
            elem --;
        }
    }
    pb(a, b);
}

void    finish(node_t **a, node_t **b, int size)
{
    int     i;

    i = size;
    while (i > 0)
    {
        pa(a, b);
        i --;
    }
}

void    five_or_less(node_t **a, node_t **b, int size_a)
{
    int min;

    min = 0; 
    if (size_a < 2)
        return;
    else if (size_a == 2)
        sort_2(a, 'a');
    else if (size_a == 3)
        sort_3(a, 'a');
    else if (size_a == 4)
    {
        min = find_min(a, 4);
        //push_min(a, b, min);
        rotate_to_top_and_push(a, b, min);
        sort_3(a, 'a');
        finish(a, b, 4);
    }
    else if (size_a == 5)
    {
        min = find_min(a, 5);
        rotate_to_top_and_push(a, b, min);
        min = find_min(a, 4);
        rotate_to_top_and_push(a, b, min);
        sort_3(a, 'a');
        finish(a, b, 5);
    }
}

int is_greater_or_smaller_than_all_b(node_t **b, int ref)
{
    node_t  *current_b;
    int     size_b;

    current_b = *b;
    size_b = get_stack_size(b);
    while (size_b > 0)
    {
        if (ref < current_b->data)
            current_b = current_b->next;
        else
            break;
        size_b --;
    }
    //printf(" *1 size_b = %d\nref = %d\n", size_b, ref);
    if (size_b == 0)
        return (1);
    current_b = *b;
    size_b = get_stack_size(b);
    while (size_b > 0)
    {
        if (ref > current_b->data)
            current_b = current_b->next;
        else
            break;
        size_b --;
    }
    //printf(" *1 size_b = %d\nref = %d\n", size_b, ref);
    if (size_b == 0)
        return (1);
    return (0);
}

void    push_cheapest(node_t **a, node_t **b)
{
    int     size_b;
    int     ref;
    int     max;
    node_t  *current;

    size_b = get_stack_size(b);
    current = *a;
    ref = current->data;
    //printf(" * 0 ref = %d\n", ref);
    if (is_greater_or_smaller_than_all_b(b, ref) == 1)  // si plus petit ou plus grand que TOUS (hors range) : rotate B autant de fois que nécessaire pour que le plus grand soit en haut de B; puis push.
    {
        //write(1, "z\n", 2);
        max = find_max(b, size_b);
       // printf("max = %d\n", max);
        while (max > 0)
        {
            rotate(b, 'b');
            max --;
        }
    }
    else // sinon: compter jusqu'à précédent plus grand et next plus petit; rotate B autant de fois que nécessaire pour que le next soit au sommet de B puis push.
    {
        current = *b;
        while (!(ref > current->data) && !(ref < current->next->data))
        {
            //write(1, "x\n", 2);
            rotate(b, 'b');
            current = *b;
        }
    }
    pb(a, b);
}

int set_cost(node_t *top_a, node_t **b, int size, int elem)
{
    if (elem < 2)
        return (elem);
    else if (elem > size / 2)
        return ();
    else if (elem <= size / 2)
        return ();
}

void    more_than_five(node_t **a, node_t **b, int size_a)
{
    int     cheapest_cost;
    int     cheapest;
    int     i;
    int     nelem;
    node_t  *top_a;

    pb(a, b);
    pb(a, b);
    nelem = size_a -2;
    while (nelem > 0)
    {
        top_a = *a;
        cheapest_cost = set_cost(top_a, b, nelem, 0);
        cheapest = 0;
        i = 0;
        size_a = get_stack_size(a);
        while (size_a > 0)
        {
            if (cheapest_cost == 0)
                break;
            if (set_cost(top_a, b, size_a, i) < cheapest_cost)
            {
                cheapest_cost = set_cost(top_a, b, size_a, i);
                cheapest = i;
            }
            top_a = top_a->next;
            i ++;
            size_a --;
        }
        rotate_to_top_and_push(a, b, cheapest);
        nelem --;
    }
    while ((*b)->data < (*b)->next->data) // if suffit?
        rotate(b, 'b');
    finish(a, b, nelem);
}

void	sort(node_t **a, node_t **b)
{
    int size_a;

    size_a = get_stack_size(a);
    display_list(a, b);
    if (is_sorted(a, 'a') == 1)
        return;
    if (size_a <= 5)
        five_or_less(a, b, size_a);
    else
        more_than_five(a, b, size_a);
    display_list(a, b);
}