/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhi <srouhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 15:03:49 by srouhi            #+#    #+#             */
/*   Updated: 2026/07/10 16:44:42 by srouhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stacks(t_stack *a, t_stack *b)
{
	a->top = NULL;
	a->size = 0;
	b->top = NULL;
	b->size = 0;
}

static int	is_valid_flag(char *arg)
{
	if (ft_strcmp(arg, "--simple") == 0)
		return (1);
	if (ft_strcmp(arg, "--medium") == 0)
		return (1);
	if (ft_strcmp(arg, "--complex") == 0)
		return (1);
	if (ft_strcmp(arg, "--adaptive") == 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	*flag;
	int		start;

	if (argc < 2)
		return (0);
	init_stacks(&stack_a, &stack_b);
	flag = NULL;
	start = 1 + is_valid_flag(argv[1]);
	if (start == 2)
		flag = argv[1];
	if (start == 2 && argc == 2)
		return (0);
	if (!parse_and_fill_stack(&stack_a, argc, argv, start))
		return (free_stack(&stack_a), write(2, "Error\n", 6), 1);
	if (is_sorted(&stack_a))
		return (free_stack(&stack_a), 0);
	run_sort(&stack_a, &stack_b, flag);
	return (free_stack(&stack_a), free_stack(&stack_b), 0);
}
