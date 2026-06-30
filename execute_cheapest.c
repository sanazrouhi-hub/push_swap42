#include "push_swap.h"

static void rotate_both(t_stack *a, t_stack *b, int *cost_a, int *cost_b)
{
    while (*cost_a > 0 && *cost_b > 0)
    {
        rr(a, b);
        (*cost_a)--;
        (*cost_b)--;
    }
    while (*cost_a < 0 && *cost_b < 0)
    {
        rrr(a, b);
        (*cost_a)++;
        (*cost_b)++;
    }
}

static void rotate_remaining(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
    while (cost_a > 0)
    {
        ra(a);
        cost_a--;
    }
    while (cost_a < 0)
    {
        rra(a);
        cost_a++;
    }
    while (cost_b > 0)
    {
        rb(b);
        cost_b--;
    }
    while (cost_b < 0)
    {
        rrb(b);
        cost_b++;
    }
}

void execute_move(t_stack *a, t_stack *b, t_node *b_node)
{
    t_node *target;
    int cost_a;
    int cost_b;

    target = find_target(a, b_node->value);
    cost_a = cost_to_top(a, target);
    cost_b = cost_to_top(b, b_node);
    rotate_both(a, b, &cost_a, &cost_b);
    rotate_remaining(a, b, cost_a, cost_b);
    pa(a, b);
}

t_node *find_cheapest(t_stack *a, t_stack *b)
{
    t_node *current;
    t_node *cheapest;
    int min_cost;
    int cost;

    current = b->top;
    cheapest = NULL;
    min_cost = INT_MAX;
    while (current)
    {
        cost = total_cost(a, b, current);
        if (cost < 0)
            cost = -cost;
        if (cost < min_cost)
        {
            min_cost = cost;
            cheapest = current;
        }
        current = current->next;
    }
    return (cheapest);
}