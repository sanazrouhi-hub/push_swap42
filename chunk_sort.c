/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shivakhadka <shivakhadka@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 14:01:46 by srouhi            #+#    #+#             */
/*   Updated: 2026/07/09 13:25:23 by shivakhadka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int get_chunk_index(t_stack *stack, int value)
{
	t_node *current;
	t_node *compare;
	int index;

	current = stack->top;
	index = 0;
	while (current)
	{
		compare = stack->top;
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

static void move_max_to_top(t_stack *b)
{
	t_node *curr;
	t_node *max_node;

	if (!b || !b->top)
		return;
	position_update(b);
	curr = b->top;
	max_node = b->top;
	while (curr)
	{
		if (curr->value > max_node->value)
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

void chunk_sort(t_stack *a, t_stack *b)
{
	int chunk_size;
	int i;

	if (lst_size(a) <= 100)
		chunk_size = 15;
	else
		chunk_size = 30;
	(void)chunk_size;
	i = 0;
	while (a->top)
	{
		if (get_chunk_index(a, a->top->value) <= i)
		{
			pb(a, b);
			i++;
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
