/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkhadka <shkhadka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 18:41:59 by shkhadka          #+#    #+#             */
/*   Updated: 2026/06/22 18:42:03 by shkhadka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack_a)
{
	t_node	*prev;
	t_node	*last;

	if (!stack_a->top || !stack_a->top->next)
		return ;
	prev = NULL;
	last = stack_a->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack_a->top;
	stack_a->top = last;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack_b)
{
	t_node	*prev;
	t_node	*last;

	if (!stack_b->top || !stack_b->top->next)
		return ;
	prev = NULL;
	last = stack_b->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack_b->top;
	stack_b->top = last;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	write(1, "rrr\n", 4);
}
