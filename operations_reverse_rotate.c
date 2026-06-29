/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shivakhadka <shivakhadka@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 18:41:59 by shkhadka          #+#    #+#             */
/*   Updated: 2026/06/29 13:05:44 by shivakhadka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate(t_stack *stack)
{
	t_node *prev;
	t_node *last;

	if (!stack->top || !stack->top->next)
		return;
	prev = NULL;
	last = stack->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = NULL;
	last->prev = NULL;
	last->next = stack->top;
	stack->top->prev = last;
	stack->top = last;
}

void rra(t_stack *stack_a)
{
	if (!stack_a->top || !stack_a->top->next)
		return;
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void rrb(t_stack *stack_b)
{
	if (!stack_b->top || !stack_b->top->next)
		return;
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top && stack_a->top->next)
		reverse_rotate(stack_a);
	if (stack_b->top && stack_b->top->next)
		reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
