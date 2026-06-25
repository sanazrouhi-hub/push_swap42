#include "push_swap.h"

t_node *find_target(t_stack *stack_a, int value)
{
    t_node *current;
    t_node *target;
    int best;

    current = stack_a->top;
    target = NULL;
    best = INT_MIN;
    while (current)
    {
        if (current->value < value && current->value > best)
        {
            best = current->value;
            target = current;
        }
        current = current->next;
    }
    while (!target)
    {
        while (current)
        {
            current = stack_a->top;
            if (!target || current->value > target->value)
                current = target;
            current = current->next;
        }
    }
    return (target);
}