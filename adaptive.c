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

static int	count_inversion(t_stack *a)
{
	t_node	*i;
	t_node	*j;
	int		inversion;

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

static double	measure_disorder(t_stack *a)
{
	int		inversion;
	int		n;
	double	total;

	n = a->size;
	if (n <= 1)
		return (0.0);
	inversion = count_inversion(a);
	total = (double)(n * (n - 1)) / 2.0;
	return ((double)inversion / total);
}

void	adaptive(t_stack *a, t_stack *b)
{
	int		size;
	double	disorder;

	size = a->size;
	disorder = measure_disorder(a);
	if (size <= 5)
	{
		if (size == 2)
		{
			if (a->top->value > a->top->next->value)
				sa(a);
			return ;
		}
		else if (size == 3)
			sort_three(&a);
		else
			sort_four_five(&a, &b);
		return ;
	}
	if (disorder < 0.2)
		big_sort(a, b);
	else if (disorder < 0.5)
		chunk_sort(a, b);
	else
		radix_sort(a, b);
}
