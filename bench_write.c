/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bench_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhi <srouhi@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 14:29:04 by srouhi            #+#    #+#             */
/*   Updated: 2026/07/13 14:29:13 by srouhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_str(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(2, s, i);
}

void	put_nbr(int n)
{
	char	c;

	if (n < 0)
	{
		write(2, "-", 1);
		put_nbr(-n);
		return ;
	}
	if (n >= 10)
		put_nbr(n / 10);
	c = '0' + (n % 10);
	write(2, &c, 1);
}
