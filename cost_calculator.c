/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkhadka <shkhadka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 15:35:39 by srouhi            #+#    #+#             */
/*   Updated: 2026/07/09 16:44:18 by shkhadka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	position_update(t_stack *stack)
{
	t_node	*current;
	int		i;

	i = 0;
	current = stack->top;
	while (current)
	{
		current->pos = i;
		current = current->next;
		i++;
	}
}

int	cost_to_top(t_stack *stack, t_node *node)
{
	if (node->pos <= stack->size / 2)
		return (node->pos);
	return (-(stack->size - node->pos));
}

static int	calc_maching_costs(int cost_a, int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
	{
		if (cost_a > cost_b)
			return (cost_a);
		else
			return (cost_b);
	}
	if (cost_a < 0 && cost_b < 0)
	{
		if (cost_a < cost_b)
			return (cost_a);
		else
			return (cost_b);
	}
	if (cost_a < 0)
		cost_a = -cost_a;
	if (cost_b < 0)
		cost_b = -cost_b;
	return (cost_a = cost_b);
}

int	total_cost(t_stack *stack_a, t_stack *stack_b, t_node *b_node)
{
	t_node	*target;
	int		cost_a;
	int		cost_b;

	target = find_target(stack_a, b_node->value);
	cost_a = cost_to_top(stack_a, target);
	cost_b = cost_to_top(stack_b, b_node);
	return (calc_maching_costs(cost_a, cost_b));
}
