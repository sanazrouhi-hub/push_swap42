#include "push_swap.h"

static int count_inversion(t_stack *a)
{
    t_node *i;
    t_node *j;
    int inversion;

    inversion = 0;
    i = a->top;
    while (i)
    {
        j = i->next;
        while (j)
        {
            if (i->value > j->value)
                inversion++;
            j = j->next;
        }
        i = i->next;
    }
    return (inversion);
}

static double measure_disorder(t_stack *a)
{
    int inversion;
    int n;
    double total;

    n = a->size;
    if (n <= 1)
        return (0.0);
    inversion = count_inversion(a);
    total = (double)(n * (n - 1)) / 2.0;
    return ((double)inversion / total);
}

void adaptive(t_stack *a, t_stack *b)
{
    double disorder;
    int size;

    size = a->size;
    disorder = measure_disorder(a);
    if (size <= 5)
    {
        if (size == 2)
            sa(a);
        else if (size == 3)
            sort_three(&a);
        else
            sort_four_five(&a, &b);
        return;
    }
    if (disorder < 2.0)
        big_sort(&a, &b);
    else if (disorder < 5.0)
        chunk_sort(&a, &b);
    else
        radix_sort(&a, &b);
}