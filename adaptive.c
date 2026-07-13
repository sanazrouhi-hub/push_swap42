/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhi <srouhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 16:16:13 by shkhadka          #+#    #+#             */
/*   Updated: 2026/07/10 15:01:43 by srouhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	adaptive_small(t_stack *a, t_stack *b, int size)
{
	bench_set(a->bench, "adaptive (small sort)", "O(1)");
	if (size == 2)
	{
		if (a->top->value > a->top->next->value)
			sa(a);
	}
	else if (size == 3)
		sort_three(&a);
	else
		sort_four_five(&a, &b);
}

void	adaptive(t_stack *a, t_stack *b)
{
	int		size;
	double	disorder;

	size = a->size;
	if (size <= 5)
	{
		adaptive_small(a, b, size);
		return ;
	}
	disorder = measure_disorder(a);
	if (disorder < 0.2)
	{
		bench_set(a->bench, "adaptive: greedy insertion", "O(n^2)");
		big_sort(a, b);
	}
	else if (disorder < 0.5)
	{
		bench_set(a->bench, "adaptive: chunk sort", "O(n*sqrt(n))");
		chunk_sort(a, b);
	}
	else
	{
		bench_set(a->bench, "adaptive: radix sort", "O(n*log(n))");
		radix_sort(a, b);
	}
}
