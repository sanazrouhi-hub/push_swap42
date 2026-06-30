/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 17:15:57 by srouhi            #+#    #+#             */
/*   Updated: 2026/06/30 09:07:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>


void	free_stack(t_node **stack);


static void	print_stack(t_stack *stack, char *stack_name)
{
	t_node	*current;

	if (!stack || !stack->top)
	{
		printf("Stack %s is EMPTY\n", stack_name);
		return ;
	}
	printf("Stack %s: ", stack_name);
	current = stack->top;
	while (current)
	{
		printf("[%d] ", current->value);
		current = current->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_stack	*ptr_a;
	t_stack	*ptr_b;
	int		size;

	if (argc < 2)
		return (0);

	stack_a.top = NULL;
	stack_a.size = 0;
	stack_b.top = NULL;
	stack_b.size = 0;

	ptr_a = &stack_a;
	ptr_b = &stack_b;
	
	if (!parse_and_fill_stack(&stack_a, argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	printf("--- BEFORE SORTING ---\n");
	print_stack(&stack_a, "A");
	print_stack(&stack_b, "B");
	printf("----------------------\n\n");
	
	size = lst_size(&stack_a);
	if (size == 2)
		sa(&stack_a);
	else if (size == 3)
		sort_three(&ptr_a);
	else if (size == 4 || size == 5)
		sort_four_five(&ptr_a, &ptr_b);
	printf("\n--- AFTER SORTING ---\n");
	print_stack(&stack_a, "A");
	print_stack(&stack_b, "B");
	printf("---------------------\n");
	/* پاک‌سازی حافظه نودها */
	if (stack_a.top)
		free_stack(&(stack_a.top));
	if (stack_b.top)
		free_stack(&(stack_b.top));
	return (0);
}

/*
#include "push_swap.h"
#include <stdio.h>

void	print_stacks_test(t_stack *a, t_stack *b)
{
	t_node	*curr;

	printf("--- Stack A ---\n");
	curr = a->top;
	while (curr)
	{
		printf("%d\n", curr->value);
		curr = curr->next;
	}
	printf("--- Stack B ---\n");
	curr = b->top;
	while (curr)
	{
		printf("%d\n", curr->value);
		curr = curr->next;
	}
	printf("===============\n");
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
	return (0);
	stack_a.top = NULL;
	stack_a.size = 0;
	stack_b.top = NULL;
	stack_b.size = 0;
	if (!parse_and_fill_stack(&stack_a, argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	printf("Initial state:\n");
	print_stacks_test(&stack_a, &stack_b);
	
	//test for operations
	printf("\nExecuting pb and sa:\n");
	pb(&stack_a, &stack_b);
	sa(&stack_a);
	print_stacks_test(&stack_a, &stack_b);
	
	return (0);
}
*/

