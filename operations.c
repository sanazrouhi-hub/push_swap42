#include <unistd.h>
typedef struct s_node
{
    int value;
    struct s_node *next;
} t_node;
typedef struct s_stack
{
    t_node *top;
    int size;
} t_stack;

void sa(t_stack *stack_a)
{
    int temp;
    t_node *top;

    if (!stack_a->top || !stack_a->top->next)
        return;
    top = stack_a->top;
    temp = top->value;
    top->value = top->next->value;
    top->next->value = temp;
    write(1, "sa\n", 3);
}

void sb(t_stack *stack_b)
{
    int temp;
    t_node *top;

    if (!stack_b->top || !stack_b->top->next)
        return;
    top = stack_b->top;
    temp = top->value;
    top->value = top->next->value;
    top->next->value = temp;
    write(1, "sb\n", 3);
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
    int temp;
    int swapped;

    swapped = 0;
    if (stack_a->top && stack_a->top->next)
    {
        temp = stack_a->top->value;
        stack_a->top->value = stack_a->top->next->value;
        stack_a->top->next->value = temp;
        swapped = 1;
    }
    if (stack_b->top && stack_b->top->next)
    {
        temp = stack_b->top->value;
        stack_b->top->value = stack_b->top->next->value;
        stack_b->top->next->value = temp;
        swapped = 1;
    }
    if (swapped)
        write(1, "ss\n", 3);
}

void pb(t_stack *stack_a, t_stack *stack_b)
{
    int value;

    if (!stack_a->top)
        return;
    value = pop_to_stack(stack_a);
    push_to_stack(stack_b, value);
    write(1, "pb\n", 3);
}

void pa(t_stack *stack_a, t_stack *stack_b)
{
    int value;

    if (!stack_b->top)
        return;
    value = pop_to_stack(stack_b);
    push_to_stack(stack_a, value);
    write(1, "pa\n", 3);
}

void ra(t_stack *stack_a)
{
    t_node *temp;
    t_node *last;

    if (!stack_a->top || !stack_a->top->next)
        return;
    temp = stack_a->top;
    stack_a->top = stack_a->top->next;
    temp->next = NULL;
    last = stack_a->top;
    while (last->next)
        last = last->next;
    last->next = temp;
    write(1, "ra\n", 3);
}

void pb(t_stack *stack_b)
{
    t_node *temp;
    t_node *last;

    if (!stack_b->top || !stack_b->top->next)
        return;
    temp = stack_b->top;
    stack_b->top = stack_b->top->next;
    temp->next = NULL;
    last = stack_b->top;
    while (last->next)
        last = last->next;
    last->next = temp;
    write(1, "rb\n", 3);
}

void rr(t_stack *stack_a, t_stack *stack_b)
{
    t_node *temp;
    t_node *last;

    if (stack_a->top && stack_a->top->next)
    {
        temp = stack_a->top;
        stack_a->top = stack_a->top->next;
        temp->next = NULL;
        last = stack_a->top;
        while (last->next)
            last = last->next;
        last->next = temp;
    }
    if (stack_b->top && stack_b->top->next)
    {
        temp = stack_b->top;
        stack_b->top = stack_b->top->next;
        temp->next = NULL;
        last = stack_b->top;
        while (last->next)
            last = last->next;
        last->next = temp;
    }
    write(1, "rr\n", 3);
}

void rra(t_stack *stack_a)
{
    t_node *prev;
    t_node *last;

    if (!stack_a->top || !stack_a->top->next)
        return;
    prev = NULL;
    last = stack_a->top;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = stack_a->top;
    stack_a->top = last;
    write(1, "rra\n", 4);
}

void rrb(t_stack *stack_b)
{
    t_node *prev;
    t_node *last;

    if (!stack_b->top || !stack_b->top->next)
        return;
    prev = NULL;
    last = stack_b->top;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = stack_b->top;
    stack_b->top = last;
    write(1, "rrb\n", 4);
}

void rrr(t_stack *stack_a, t_stack *stack_b)
{
    t_node *prev;
    t_node *last;

    if (stack_a->top && stack_a->top->next)
    {
        prev = NULL;
        last = stack_a->top;
        while (last->next)
        {
            prev = last;
            last = last->next;
        }
        prev->next = NULL;
        last->next = stack_a->top;
        stack_a->top = last;
    }
    if (stack_b->top && stack_b->top->next)
    {
        prev = NULL;
        last = stack_b->top;
        while (last->next)
        {
            prev = last;
            last = last->next;
        }
        prev->next = NULL;
        last->next = stack_b->top;
        stack_b->top = last;
    }
    write(1, "rrr\n", 4);
}