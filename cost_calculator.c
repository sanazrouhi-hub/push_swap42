#include "push_swap.h"

void position_update(t_stack *stack)
{
    t_node *current;
    int i;

    i = 0;
    current = stack->top;
    while (current)
    {
        current->pos = i;
        current = current->next;
        i++;
    }
}

int cost_to_top(t_stack *stack, t_node *node)
{
    if (node->pos <= stack->size / 2) // this is for ra and rb which is forward
        return (node->pos);
    return (-(stack->size - node->pos)); // this is for rra and rrb which is backward
}

int total_cost(t_stack *stack_a, t_stack *stack_b, t_node *b_node)
{
    t_node *target;
    int cost_a;
    int cost_b;

    target = find_target(stack_a, b_node->value);
    cost_a = cost_to_top(stack_a, target);
    cost_b = cost_to_top(stack_b, b_node);
    if (cost_a > 0 && cost_b > 0)
    {
        if (cost_a > cost_b)
            return (cost_a);
        else
            return (cost_b);
    }
    if (cost_a < 0 && cost_b < 0)
    {
        if (cost_a < cost_b)
            return (cost_a);
        else
            return (cost_b);
    }
    return (abs(cost_a) + abs(cost_b));
}