/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkhadka <shkhadka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 18:05:53 by shkhadka          #+#    #+#             */
/*   Updated: 2026/07/09 16:14:11 by shkhadka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	if (!stack_b->top)
		return ;
	node = pop_to_stack(stack_b);
	push_to_stack(stack_a, node);
	write(1, "pa\n", 3);
	bench_add(stack_a->bench, OP_PA);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	if (!stack_a->top)
		return ;
	node = pop_to_stack(stack_a);
	push_to_stack(stack_b, node);
	write(1, "pb\n", 3);
	bench_add(stack_a->bench, OP_PB);
}
