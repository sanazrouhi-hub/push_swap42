/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhi <srouhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 16:16:26 by shkhadka          #+#    #+#             */
/*   Updated: 2026/07/10 20:42:03 by srouhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign_ranks(t_stack *a)
{
	t_node	*current;
	t_node	*compare;
	int		rank;

	current = a->top;
	while (current)
	{
		rank = 0;
		compare = a->top;
		while (compare)
		{
			if (compare->value < current->value)
				rank++;
			compare = compare->next;
		}
		current->index = rank;
		current = current->next;
	}
}

static void	move_max_to_top(t_stack *b)
{
	t_node	*curr;
	t_node	*max_node;

	if (!b || !b->top)
		return ;
	position_update(b);
	curr = b->top;
	max_node = b->top;
	while (curr)
	{
		if (curr->index > max_node->index)
			max_node = curr;
		curr = curr->next;
	}
	while (b->top != max_node)
	{
		if (max_node->pos <= b->size / 2)
			rb(b);
		else
			rrb(b);
	}
}

static int	get_chunk_size(t_stack *a)
{
	if (a->size <= 100)
		return (20);
	return (45);
}

void	chunk_sort(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	pushed;

	assign_ranks(a);
	chunk_size = get_chunk_size(a);
	pushed = 0;
	while (a->top)
	{
		if (a->top->index < pushed + chunk_size)
		{
			pb(a, b);
			if (b->top->index < pushed + chunk_size / 2)
				rb(b);
			pushed++;
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
