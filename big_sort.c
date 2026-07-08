/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhi <srouhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 15:35:05 by srouhi            #+#    #+#             */
/*   Updated: 2026/07/03 15:35:15 by srouhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack *a, t_stack *b)
{
	int	i;

	i = a->size;
	while (i > 3)
	{
		pb(a, b);
		i--;
	}
}

void	move_min_to_top(t_stack *a)
{
	t_node	*current;
	t_node	*min_node;

	current = a->top;
	min_node = a->top;
	while (current)
	{
		if (current->value < min_node->value)
			min_node = current;
		current = current->next;
	}
	while (a->top != min_node)
	{
		position_update(a);
		if (min_node->pos <= a->size / 2)
			ra(a);
		else
			rra(a);
	}
}

void	big_sort(t_stack *a, t_stack *b)
{
	t_node	*cheapest;

	push_to_b(a, b);
	sort_three(&a);
	while (b->size > 0)
	{
		position_update(a);
		position_update(b);
		cheapest = find_cheapest(a, b);
		execute_move(a, b, cheapest);
	}
	move_min_to_top(a);
}
