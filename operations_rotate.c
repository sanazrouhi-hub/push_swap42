/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shivakhadka <shivakhadka@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 18:04:24 by shkhadka          #+#    #+#             */
/*   Updated: 2026/06/29 13:00:45 by shivakhadka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_stack *stack)
{
	t_node *temp;
	t_node *last;

	if (!stack->top || !stack->top->next)
		return;
	temp = stack->top;
	stack->top = stack->top->next;
	stack->top->prev = NULL;
	temp->next = NULL;
	last = stack->top;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->prev = last;
}
void ra(t_stack *stack_a)
{
	if (!stack_a->top || !stack_a->top->next)
		return;
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void rb(t_stack *stack_b)
{

	if (!stack_b->top || !stack_b->top->next)
		return;
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void rr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top && stack_a->top->next)
		rotate(stack_a);
	if (stack_b->top && stack_b->top->next)
		rotate(stack_b);
	write(1, "rr\n", 3);
}
