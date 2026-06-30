#include "push_swap.h"

void push_to_b(t_stack *a, t_stack *b)
{
    int i;

    i = a->size;
    while (i > 3)
    {
        pb(a, b);
        i--;
    }
}

void move_min_to_top(t_stack *a)
{
    t_node *current;
    t_node *min_node;

    current = a->top;
    min_node = a->top;
    while (current)
    {
        if (current->value < min_node->value)
            min_node = current;
        current = current->next;
    }
    while (a->top != min_node)
    {
        position_update(a);
        if (min_node->pos <= a->size / 2)
            ra(a);
        else
            rra(a);
    }
}

void print_stack(t_stack *a, char *label)
{
    t_node *current;

    printf("%s: ", label);
    current = a->top;
    while (current)
    {
        printf("[%d] ", current->value);
        current = current->next;
    }
    printf("\n");
}

void big_sort(t_stack *a, t_stack *b)
{
    t_node *cheapest;

    push_to_b(a, b);
    sort_three(&a);
    while (b->size > 0)
    {
        position_update(a);
        position_update(b);
        cheapest = find_cheapest(a, b);
        execute_move(a, b, cheapest);
    }
    move_min_to_top(a);
}