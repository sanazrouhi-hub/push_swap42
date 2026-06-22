/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhi <srouhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 17:15:57 by srouhi            #+#    #+#             */
/*   Updated: 2026/06/22 17:16:32 by srouhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // فقط برای تست و چاپ موقت پشته (بعدا حذف شود)

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
