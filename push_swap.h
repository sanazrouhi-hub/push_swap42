/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhi <srouhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:30:28 by srouhi            #+#    #+#             */
/*   Updated: 2026/06/19 14:55:53 by srouhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>

# include <unistd.h>

# include <stdlib.h>

typedef struct s_stack
{
	int					value;
	int					indext;
	struct s_stack		*next;
	struct s_stack		*prev;
}	t_stack;
#endif
