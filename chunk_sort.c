/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhi <srouhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 14:01:46 by srouhi            #+#    #+#             */
/*   Updated: 2026/07/03 15:37:58 by srouhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_index(t_stack *stack, int value)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	current = stack->top;
	index = 0;
	while (current)
	{
		compare = stack-> top;
		while (compare)
		{
			if (current->value > compare->value)
				index++;
			compare = compare->next;
		}
		if (current->value == value)
			return (index);
		index = 0;
		current = current->next;
	}
	return (0);
}

static void	move_max_to_top(t_stack *b)
{
	t_node	*curr;
	t_node	*max_node;
	int		max_pos;
	int		pos;

	curr = b->top;
	max_node = b->top;
	pos = 0;
	max_pos = 0;
	while (curr)
	{
		if (curr->value > max_node->value && (max_pos == pos))
			max_node = curr;
		pos++;
		curr = curr->next;
	}
	while (b->top != max_node)
	{
		if (max_pos <= b->size / 2)
			rb(b);
		else
			rrb(b);
	}
}

static int	init_chunk(t_stack *a)
{
	int	chunk_size;

	chunk_size = 1;
	while ((chunk_size * chunk_size) <= a->size)
		chunk_size++;
	return (chunk_size * 1.5);
}

void	chunk_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	chunk_size;

	chunk_size = init_chunk(a);
	i = 0;
	while (a->top)
	{
		if (get_chunk_index(a, a->top->value) <= i && ++i)
			pb(a, b);
		else if (get_chunk_index(a, a->top->value) <= i + chunk_size && ++i)
		{
			pb(a, b);
			rb(b);
		}
		else
			ra(a);
	}
	while (b->top)
	{
		move_max_to_top(b);
		pa(a, b);
	}
}
