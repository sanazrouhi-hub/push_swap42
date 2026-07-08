/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhi <srouhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 15:42:01 by srouhi            #+#    #+#             */
/*   Updated: 2026/07/08 15:48:27 by srouhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

#include "push_swap.h"

static void	run_sort(t_stack *a, t_stack *b)
{
	int	size;

	size = lst_size(a);
	if (size <= 1)
		return ;
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(&a);
	else if (size <= 5)
		sort_four_five(&a, &b);
	else
		chunk_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
		return (0);
	stack_a = (t_stack){NULL, 0};
	stack_b = (t_stack){NULL, 0};
	if (!parse_and_fill_stack(&stack_a, argc, argv, 1))
	{
		write(2, "Error\n", 6);
		free_stack(&stack_a);
		return (1); 
	}
	run_sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
