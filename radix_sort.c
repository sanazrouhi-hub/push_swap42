/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhi <srouhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 14:47:31 by srouhi            #+#    #+#             */
/*   Updated: 2026/07/08 14:47:55 by srouhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	normalize(t_stack *a)
{
	t_node	*current;
	t_node	*min_node;
	int		index;
	int		assigned;

	index = 0;
	assigned = 0;
	while (assigned < a->size)
	{
		current = a->top;
		min_node = NULL;
		while (current)
		{
			if (current->index == -1)
			{
				if (!min_node || current->value < min_node->value)
					min_node = current;
			}
			current = current->next;
		}
		if (min_node)
			min_node->index = index;
		index++;
		assigned++;
	}
}

static int	get_max_bits(t_stack *a)
{
	t_node	*current;
	int		bits;
	int		max;

	current = a->top;
	max = 0;
	while (current)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	bits = 0;
	while ((1 << bits) <= max)
		bits++;
	return (bits);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	bit;
	int	max_bits;
	int	i;
	int	size;

	normalize(a);
	max_bits = get_max_bits(a);
	printf("max_bits=%d\n", max_bits);
	bit = 0;
	while (bit < max_bits)
	{
		size = a->size;
		i = 0;
		while (i < size)
		{
			if ((a->top->index >> bit) & 1)
				ra(a);
			else
				pb(a, b);
			i++;
		}
		while (b->size > 0)
			pa(a, b);
		bit++;
	}
}
