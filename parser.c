/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhi <srouhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 14:06:00 by srouhi            #+#    #+#             */
/*   Updated: 2026/06/22 17:44:34 by srouhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(t_stack *stack, int num)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->value == num)
			return (1);
		current = current->next;
	}
	return (0); 
}


int	parse_and_fill_stack(t_stack *stack_a, int argc, char **argv)
{
	int			i;
	int			value;
	t_node		*new_node;

	i = 1;
	while (i < argc)
	{
		if (!ft_is_number(argv[i]))
			return (0);
		if (!ft_atoi_safe(argv[i], &value))
			return (0);
		if (check_duplicate(stack_a, value))
			return (0);
		new_node = lst_new(value);
		if (!new_node)
			return (0);
		lst_add_back(&(stack_a->top), new_node);
		stack_a->size++;
		i++;
	}
	return (1);
}
