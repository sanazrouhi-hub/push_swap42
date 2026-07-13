/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bench_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhi <srouhi@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 14:28:17 by srouhi            #+#    #+#             */
/*   Updated: 2026/07/13 14:28:37 by srouhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bench_set(t_bench *bench, char *name, char *complexity)
{
	if (!bench || !bench->on)
		return ;
	bench->name = name;
	bench->complexity = complexity;
}

static void	put_line(char *label, int n)
{
	put_str("[bench] ");
	put_str(label);
	put_str(": ");
	put_nbr(n);
	put_str("\n");
}

static void	put_disorder(double d)
{
	int	p;

	p = (int)(d * 10000.0 + 0.5);
	put_str("[bench] Disorder: ");
	put_nbr(p / 100);
	put_str(".");
	if (p % 100 < 10)
		put_str("0");
	put_nbr(p % 100);
	put_str("%\n");
}

static void	put_counts(t_bench *b)
{
	put_line("sa", b->count[OP_SA]);
	put_line("sb", b->count[OP_SB]);
	put_line("ss", b->count[OP_SS]);
	put_line("pa", b->count[OP_PA]);
	put_line("pb", b->count[OP_PB]);
	put_line("ra", b->count[OP_RA]);
	put_line("rb", b->count[OP_RB]);
	put_line("rr", b->count[OP_RR]);
	put_line("rra", b->count[OP_RRA]);
	put_line("rrb", b->count[OP_RRB]);
	put_line("rrr", b->count[OP_RRR]);
}

void	print_bench(t_bench *b)
{
	int	total;
	int	i;

	if (!b->on)
		return ;
	total = 0;
	i = 0;
	while (i < 11)
	{
		total += b->count[i];
		i++;
	}
	put_disorder(b->disorder);
	put_str("[bench] Strategy: ");
	put_str(b->name);
	put_str(" ");
	put_str(b->complexity);
	put_str("\n");
	put_line("Total operations", total);
	put_counts(b);
}
