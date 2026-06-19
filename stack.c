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

void    push_to_stack(t_stack *stack, int value)
{
    t_node  *new;

    new = malloc(sizeof(t_node));
    if (!new)
        return;
    new->value = value;
    new->next = stack->top;
    stack->top = new;
    stack->size++;
}

int    pop_to_stack(t_stack *stack)
{
    t_node  *temp;
    int value;

    if (!stack->top)
        return(0);
    temp = stack->top;
    value = temp->value;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return (value);
}