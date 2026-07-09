/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shivakhadka <shivakhadka@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 13:18:34 by shkhadka          #+#    #+#             */
/*   Updated: 2026/07/09 14:22:58 by shivakhadka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_to_stack(t_stack *stack, t_node *node)
{
	if (!node)
		return;
	node->next = stack->top;
	node->prev = NULL;
	if (stack->top)
		stack->top->prev = node;
	stack->top = node;
	stack->size++;
}

t_node *pop_to_stack(t_stack *stack)
{
	t_node *temp;

	if (!stack->top)
		return (NULL);
	temp = stack->top;
	stack->top = stack->top->next;
	if (stack->top)
		stack->top->prev = NULL;
	temp->next = NULL;
	temp->prev = NULL;
	stack->size--;
	return (temp);
}
