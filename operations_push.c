/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkhadka <shkhadka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 18:05:53 by shkhadka          #+#    #+#             */
/*   Updated: 2026/06/22 18:07:39 by shkhadka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	value;

	if (!stack_b->top)
		return ;
	value = pop_to_stack(stack_b);
	push_to_stack(stack_a, value);
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	value;

	if (!stack_a->top)
		return ;
	value = pop_to_stack(stack_a);
	push_to_stack(stack_b, value);
	write(1, "pb\n", 3);
}
