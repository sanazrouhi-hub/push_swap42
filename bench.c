/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhi <srouhi@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 14:36:15 by srouhi            #+#    #+#             */
/*   Updated: 2026/07/13 14:37:02 by srouhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_inversions(t_stack *a)
{
	t_node	*i;
	t_node	*j;
	int		inv;

	inv = 0;
	i = a->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value > j->value)
				inv++;
			j = j->next;
		}
		i = i->next;
	}
	return (inv);
}

double	measure_disorder(t_stack *a)
{
	double	total;

	if (a->size <= 1)
		return (0.0);
	total = (double)a->size * (a->size - 1) / 2.0;
	return ((double)count_inversions(a) / total);
}

void	bench_init(t_bench *bench)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		bench->count[i] = 0;
		i++;
	}
	bench->on = 0;
	bench->disorder = 0.0;
	bench->name = "none";
	bench->complexity = "-";
}

void	bench_attach(t_bench *bench, t_stack *a, t_stack *b)
{
	if (!bench->on)
		return ;
	bench->disorder = measure_disorder(a);
	a->bench = bench;
	b->bench = bench;
}

void	bench_add(t_bench *bench, t_op op)
{
	if (bench)
		bench->count[op]++;
}
