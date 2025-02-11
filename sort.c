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
    if (stack == 'a')
    {
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
    if (stack == 'b')
    {
        if (current->data < current->next->data)
        {
            if (current->next->data < current->next->next->data)
            {
                s(head, stack);
                rev_rotate(head, stack); 
            }
            else
            {
                if (current->data < current->next->next->data)
                    rotate(head, stack); 
                else
                    s(head, stack); 
            }
        }
        else
        {
            rev_rotate(head, stack);
            current = *head;
            if (current->data < current->next->data)
                s(head, stack); 
        }
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

void    rev_rotate_to_top(node_t **a, node_t **b, int elem_a, int elem_b)
{
    if (elem_a > elem_b)
    {
        while (elem_a - elem_b)
        {
            rev_rotate(a, 'a');
            elem_a --;
        }
    }
    else if (elem_b > elem_a)
    {
        while (elem_b - elem_a)
        {
            rotate(b, 'b');
            elem_b --;
        }
    }
}
void    rotate_to_top(node_t **a, node_t **b, int elem_a, int elem_b)
{
    if (elem_a > elem_b)
    {
        while (elem_a - elem_b)
        {
            rotate(a, 'a');
            elem_a --;
        }
    }
    else if (elem_b > elem_a)
    {
        while (elem_b - elem_a)
        {
            rotate(b, 'b');
            elem_b --;
        }
    }
}

void    swap_to_top(node_t **a, node_t **b, int elem_a, int elem_b)
{
    if (elem_a == 1 && elem_b == 1)
        return;
    else if (elem_a == 1)
        s(a, 'a');
    else if (elem_b == 1)
        s(b,'b');
}

void    move_together(node_t **a, node_t **b, int elem_a, int elem_b)
{
    int size_a;
    int size_b;

    size_a = get_stack_size(a);
    size_b = get_stack_size(b);
    //if (elem_a == 1 && elem_b == 1)
    //    ss(a, b);
    if (elem_a <= size_a / 2 && elem_b <= size_b  / 2)
    {
        while (elem_a && elem_b)
        {
            rr(a, b);
            elem_a --;
            elem_b --;
        }
    }
    else if (elem_a > size_a / 2 && elem_b > size_b / 2)
    {
        while (get_stack_size(a) - elem_a && get_stack_size(b) - elem_b)
        {
            rrr(a, b);
            elem_a ++;
            elem_b ++;
        }
    }
}

//void    push_min(node_t **a, node_t **b, int min)
void    put_to_top_and_push(node_t **a, node_t **b, int elem_a, int elem_b)
{
    int size_a;
    int size_b;
    int swapped;

    size_a = get_stack_size(a);
    size_b = get_stack_size(b);
    //printf("MIN = %d\n", min);
    if (elem_a == 0 && elem_b == 0)
    {
        pb(a, b);
        return;
    }
    move_together(a, b, elem_a, elem_b);
    if (elem_a != elem_b)
    {
        /*if (elem_a == 1 || elem_b == 1)
        {
            if (elem_a == 1)
                s(a, 'a');
            else if (elem_b == 1)
                s(b, 'b');
        }*/
        if (elem_a <= size_a / 2 || elem_b <= size_b)
            rotate_to_top(a, b, elem_a, elem_b);
        else if (elem_a > size_a / 2 || elem_b > size_b)
            rev_rotate_to_top(a, b, elem_a, elem_b);
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
        put_to_top_and_push(a, b, min, 0);
        sort_3(a, 'a');
        finish(a, b, 4);
    }
    else if (size_a == 5)
    {
        min = find_min(a, 5);
        put_to_top_and_push(a, b, min, 0);
        min = find_min(a, 4);
        put_to_top_and_push(a, b, min, 0);
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

void    set_cost_to_push(node_t *current_a, node_t **b)
{
    int     ref;
    int     i;
    int     size_b;
    node_t  *current_b;
    node_t  *bottom_b;

    ref = current_a->data;
    size_b = get_stack_size(b);
    i = size_b;
    current_b = *b;
    bottom_b = *b;
    while (i > 1)
    {
        bottom_b = bottom_b->next;
        i --;
    }
    if (is_greater_or_smaller_than_all_b(b, ref) == 1)
    {
        i = find_max(b, size_b);
        if (i <= size_b / 2)
            current_a->cost_to_push = i;
        else if (i > size_b / 2)
            current_a->cost_to_push = size_b - i;
    }
    else
    {
        if ((ref < bottom_b->data) && (ref > current_b->data))
        {
            current_a->cost_to_push = 0;
            return;
        }
        i = 1;
        while (!(ref < current_b->data) && !(ref > current_b->next->data)) // MARCHE PAS!!
        {
            i ++;
            current_b = current_b->next;
        }
        current_a->cost_to_push = i;
        /*if (i > size_b / 2)
            current_a->cost_to_push = size_b - i;
        else
            current_a->cost_to_push = i;*/
    }
}

int set_cost(node_t *top_a, node_t **b, int size_a, int i)
{
    if (i <= size_a / 2)
        top_a->cost_to_the_top = i;
    else if (i > size_a / 2)
        top_a->cost_to_the_top = size_a - i;
    set_cost_to_push(top_a, b);
    top_a->cost = top_a->cost_to_the_top + top_a->cost_to_push;
    return (top_a->cost);
}

int find_target(node_t **a, node_t **b, int cheapest)
{
    int target;
    int i;
    node_t  *top_a;

    top_a = *a;
    i = 0;
    while (i < cheapest)
    {
        top_a = top_a->next;
        i ++;
    }
    target = top_a->cost_to_push;
    return (target);
}

int find_cheapest(node_t **a, node_t **b, int nelem)
{
    int cheapest;
    int cheapest_cost;
    int size_a;
    int i;
    node_t  *top_a;

    top_a = *a;
    i = 0;
    cheapest = 0;
    cheapest_cost = set_cost(top_a, b, nelem, 0);
    size_a = get_stack_size(a);
    while (size_a > 0)
    {
        if (cheapest_cost < 1) //1 + i?
            break;
        if (set_cost(top_a, b, nelem, i) < cheapest_cost)
        {
            cheapest_cost = top_a->cost;
            cheapest = i;
        }
        top_a = top_a->next;
        i ++;
        size_a --;
    }
    return (cheapest);
}

void    more_than_five(node_t **a, node_t **b, int size_a)
{
    int     cheapest;
    int     target;
    int     nelem;
    int     total;
    node_t  *top_a;

    total = size_a;
    pb(a, b);
    pb(a, b);
    nelem = size_a -2;
    while (nelem > 0)
    {
        cheapest = find_cheapest(a, b, nelem);
        target = find_target(a, b, cheapest);
        put_to_top_and_push(a, b, cheapest, target);
        printf("cheapest = %d, target = %d\n", cheapest, target);
        display_list(a, b);
        nelem --;
    }
    //sort_3(a, 'a');
    //if ((*b)->data < (*b)->next->data)
    //    rotate(b, 'b');
    finish(a, b, total);
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
