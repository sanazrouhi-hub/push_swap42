/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkhadka <shkhadka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 18:04:24 by shkhadka          #+#    #+#             */
/*   Updated: 2026/06/22 18:11:09 by shkhadka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a)
{
	t_node	*temp;
	t_node	*last;

	if (!stack_a->top || !stack_a->top->next)
		return ;
	temp = stack_a->top;
	stack_a->top = stack_a->top->next;
	temp->next = NULL;
	last = stack_a->top;
	while (last->next)
		last = last->next;
	last->next = temp;
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack_b)
{
	t_node	*temp;
	t_node	*last;

	if (!stack_b->top || !stack_b->top->next)
		return ;
	temp = stack_b->top;
	stack_b->top = stack_b->top->next;
	temp->next = NULL;
	last = stack_b->top;
	while (last->next)
		last = last->next;
	last->next = temp;
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;
	t_node	*last;

	if (stack_a->top && stack_a->top->next)
	{
		temp = stack_a->top;
		stack_a->top = stack_a->top->next;
		temp->next = NULL;
		last = stack_a->top;
		while (last->next)
			last = last->next;
		last->next = temp;
	}
	if (stack_b->top && stack_b->top->next)
	{
		temp = stack_b->top;
		stack_b->top = stack_b->top->next;
		temp->next = NULL;
		last = stack_b->top;
		while (last->next)
			last = last->next;
		last->next = temp;
	}
	write(1, "rr\n", 3);
}
