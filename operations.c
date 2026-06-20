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

void sa(t_stack *a)
{
    int temp;
    t_node *top;

    if (!a->top || !a->top->next)
        return;
    top = a->top;
    temp = top->value;
    top->value = top->next->value;
    top->next->value = temp;
    write(1, "sa\n", 3);
}

void sb(t_stack *b)
{
    int temp;
    t_node *top;

    if (!b->top || !b->top->next)
        return;
    top = b->top;
    temp = top->value;
    top->value = top->next->value;
    top->next->value = temp;
    write(1, "sb\n", 3);
}

void ss(t_stack *a, t_stack *b)
{
    int temp;
    int swapped;

    swapped = 0;
    if (a->top && a->top->next)
    {
        temp = a->top->value;
        a->top->value = a->top->next->value;
        a->top->next->value = temp;
        swapped = 1;
    }
    if (b->top && b->top->next)
    {
        temp = b->top->value;
        b->top->value = b->top->next->value;
        b->top->next->value = temp;
        swapped = 1;
    }
    if (swapped)
        write(1, "ss\n", 3);
}

void pb(t_stack *a, t_stack *b)
{
    t_stack *moving;

    if (!a || !a->top)
        return;
    moving = a->top;
    a->top = a->top->next;
    a->size--;

    moving->next = b->top;
    b->top = moving;
    b->size++;
}