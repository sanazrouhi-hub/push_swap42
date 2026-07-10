/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhi <srouhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 16:15:13 by srouhi            #+#    #+#             */
/*   Updated: 2026/07/10 20:43:03 by srouhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static void	sort_small(t_stack *a, t_stack *b, int size)
{
	if (size == 2)
	{
		if (a->top->value > a->top->next->value)
			sa(a);
	}
	else if (size == 3)
		sort_three(&a);
	else
		sort_four_five(&a, &b);
}

static void	run_strategy(t_stack *a, t_stack *b, char *flag)
{
	if (flag && ft_strcmp(flag, "--simple") == 0)
		big_sort(a, b);
	else if (flag && ft_strcmp(flag, "--medium") == 0)
		chunk_sort(a, b);
	else if (flag && ft_strcmp(flag, "--complex") == 0)
		radix_sort(a, b);
	else
		adaptive(a, b);
}

void	run_sort(t_stack *a, t_stack *b, char *flag)
{
	int	size;

	size = lst_size(a);
	if (size <= 1)
		return ;
	if (size <= 5)
		sort_small(a, b, size);
	else
		run_strategy(a, b, flag);
}
