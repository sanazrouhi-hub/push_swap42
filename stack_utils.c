/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhi <srouhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 14:06:36 by srouhi            #+#    #+#             */
/*   Updated: 2026/06/19 14:56:09 by srouhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lst_new(int value)
{
	t_stack		*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*lst_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	lst_add_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*last_node;

	if (!stack || !new_node)
		return ;
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	last_node = lst_last(*stack);
	last_node->next = new_node;
	new_node->prev = last_node;
}

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next_node;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*stack = NULL;
}
