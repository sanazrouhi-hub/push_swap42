/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkhadka <shkhadka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 15:43:47 by srouhi            #+#    #+#             */
/*   Updated: 2026/07/09 16:34:11 by shkhadka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_min_node(t_stack *stack_a)
{
	t_node	*current;
	t_node	*min_node;

	current = stack_a->top;
	min_node = stack_a->top;
	while (current)
	{
		if (current->value < min_node->value)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

t_node	*find_target(t_stack *stack_a, int value)
{
	t_node	*current;
	t_node	*target;
	int		best;

	current = stack_a->top;
	target = NULL;
	best = INT_MAX;
	while (current)
	{
		if (current->value > value && current->value < best)
		{
			best = current->value;
			target = current;
		}
		current = current->next;
	}
	if (target)
		return (target);
	return (find_min_node(stack_a));
}
