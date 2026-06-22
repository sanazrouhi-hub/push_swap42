/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkhadka <shkhadka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 13:18:34 by shkhadka          #+#    #+#             */
/*   Updated: 2026/06/22 13:57:36 by shkhadka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_stack(t_stack *stack, int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->value = value;
	new->next = stack->top;
	stack->top = new;
	stack->size++;
}

int	pop_to_stack(t_stack *stack)
{
	t_node *temp;
	int value;

	if (!stack->top)
		return (0);
	temp = stack->top;
	value = temp->value;
	stack->top = temp->next;
	free(temp);
	stack->size--;
	return (value);
}