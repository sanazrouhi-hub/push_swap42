#include "push_swap.h"
#include <stdio.h>

static int ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

static void print_stack(t_stack *stack, char *name)
{
	t_node *current;

	current = stack->top;
	printf("%s: ", name);
	if (!current)
	{
		printf("EMPTY\n");
		return;
	}
	while (current)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}

static void run_sort(t_stack *a, t_stack *b, char *flag)
{
	int size;

	size = lst_size(a);
	if (size <= 1)
		return;
	if (size == 2)
	{
		sa(a);
		return;
	}
	if (size == 3)
	{
		sort_three(&a);
		return;
	}
	if (size <= 5)
	{
		sort_four_five(&a, &b);
		return;
	}
	if (ft_strcmp(flag, "-simple") == 0)
		big_sort(a, b);
	else if (ft_strcmp(flag, "-medium") == 0)
		big_sort(a, b);
	else if (ft_strcmp(flag, "-complex") == 0)
		radix_sort(a, b);
	else if (ft_strcmp(flag, "-adaptive") == 0)
		big_sort(a, b);
	else
		big_sort(a, b);
}

int main(int argc, char **argv)
{
	t_stack stack_a;
	t_stack stack_b;
	char *flag;
	int start;

	if (argc < 2)
		return (0);
	stack_a.top = NULL;
	stack_a.size = 0;
	stack_b.top = NULL;
	stack_b.size = 0;
	flag = "-simple";
	start = 1;
	if (argv[1][0] == '-')
	{
		flag = argv[1];
		start = 2;
	}
	if (!parse_and_fill_stack(&stack_a, argc, argv, start))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	printf("--- BEFORE ---\n");
	print_stack(&stack_a, "A");
	print_stack(&stack_b, "B");
	printf("--------------\n");
	run_sort(&stack_a, &stack_b, flag);
	printf("\n--- AFTER ---\n");
	print_stack(&stack_a, "A");
	print_stack(&stack_b, "B");
	printf("-------------\n");
	// free_stack(&(stack_a.top));
	// free_stack(&(stack_b.top));
	return (0);
}