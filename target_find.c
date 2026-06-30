#include "push_swap.h"

t_node *find_target(t_stack *stack_a, int value)
{
    t_node *current;
    t_node *target;
    int best;

    current = stack_a->top;
    target = NULL;
    best = INT_MAX;
    while (current)
    {
        if (current->value > value && current->value < best)
        {
            best = current->value;
            target = current;
        }
        current = current->next;
    }
    if (target)
        return (target);
    current = stack_a->top;
    target = stack_a->top;
    while (current)
    {
        if (current->value < target->value)
            target = current;
        current = current->next;
    }
    return (target);
}