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
	a->bench = NULL;
	b->top = NULL;
	b->size = 0;
	b->bench = NULL;
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

static int	parse_flags(char **argv, char **flag, t_bench *bench)
{
	int	i;

	i = 1;
	while (argv[i] && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (ft_strcmp(argv[i], "--bench") == 0)
			bench->on = 1;
		else if (is_valid_flag(argv[i]))
			*flag = argv[i];
		else
			return (-1);
		i++;
	}
	return (i);
}

static int	handle_args(char **argv, t_stack *a, char **flag, t_bench *bench)
{
	int	argc;
	int	start;

	argc = 0;
	while (argv[argc])
		argc++;
	start = parse_flags(argv, flag, bench);
	if (start > 0 && !argv[start])
		return (0);
	if (start < 0 || !parse_and_fill_stack(a, argc, argv, start))
		return (-1);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_bench	bench;
	char	*flag;
	int		status;

	if (argc < 2)
		return (0);
	init_stacks(&stack_a, &stack_b);
	bench_init(&bench);
	flag = NULL;
	status = handle_args(argv, &stack_a, &flag, &bench);
	if (status == -1)
		return (free_stack(&stack_a), write(2, "Error\n", 6), 1);
	if (status == 0)
		return (free_stack(&stack_a), 0);
	bench_attach(&bench, &stack_a, &stack_b);
	if (!is_sorted(&stack_a))
		run_sort(&stack_a, &stack_b, flag);
	print_bench(&bench);
	return (free_stack(&stack_a), free_stack(&stack_b), 0);
}
