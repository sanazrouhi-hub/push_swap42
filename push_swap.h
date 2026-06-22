/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkhadka <shkhadka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:30:28 by srouhi            #+#    #+#             */
/*   Updated: 2026/06/22 13:17:20 by shkhadka         ###   ########.fr       */
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

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;


#endif
