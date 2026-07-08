/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhi <srouhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 14:06:00 by srouhi            #+#    #+#             */
/*   Updated: 2026/07/03 15:21:29 by srouhi           ###   ########.fr       */
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

static void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

static int	fill_stack(t_stack *stack, char **args, int start)
{
	int		i;
	int		value;
	t_node	*new_node;

	i = start;
	while (args[i])
	{
		if (!ft_is_number(args[i]))
			return (0);
		if (!ft_atoi_safe(args[i], &value))
			return (0);
		if (check_duplicate(stack, value))
			return (0);
		new_node = lst_new(value);
		if (!new_node)
			return (0);
		lst_add_back(&(stack->top), new_node);
		stack->size++;
		i++;
	}
	return (1);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

int	parse_and_fill_stack(t_stack *stack_a, int argc, char **argv, int start)
{
	char	**split_args;
	int		success;

	if (argc < 2)
		return (0);
	if ((argc - start == 1) && ft_strchr(argv[start], ' '))
	{
		split_args = ft_split(argv[start], ' ');
		if (!split_args)
			return (0);
		success = fill_stack(stack_a, split_args, 0);
		free_matrix(split_args);
		return (success);
	}
	return (fill_stack(stack_a, argv, start));
}
