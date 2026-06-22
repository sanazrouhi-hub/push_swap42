/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkhadka <shkhadka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 18:03:37 by shkhadka          #+#    #+#             */
/*   Updated: 2026/06/22 18:14:48 by shkhadka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	int		temp;
	t_node	*top;

	if (!stack_a->top || !stack_a->top->next)
		return ;
	top = stack_a->top;
	temp = top->value;
	top->value = top->next->value;
	top->next->value = temp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack_b)
{
	int		temp;
	t_node	*top;

	if (!stack_b->top || !stack_b->top->next)
		return ;
	top = stack_b->top;
	temp = top->value;
	top->value = top->next->value;
	top->next->value = temp;
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;
	int	swapped;

	swapped = 0;
	if (stack_a->top && stack_a->top->next)
	{
		temp = stack_a->top->value;
		stack_a->top->value = stack_a->top->next->value;
		stack_a->top->next->value = temp;
		swapped = 1;
	}
	if (stack_b->top && stack_b->top->next)
	{
		temp = stack_b->top->value;
		stack_b->top->value = stack_b->top->next->value;
		stack_b->top->next->value = temp;
		swapped = 1;
	}
	if (swapped)
		write(1, "ss\n", 3);
}
