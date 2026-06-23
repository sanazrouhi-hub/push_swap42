/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhi <srouhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:30:28 by srouhi            #+#    #+#             */
/*   Updated: 2026/06/22 17:37:26 by srouhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>

# include <unistd.h>

# include <stdlib.h>

typedef struct s_node
{
	int						value;
	//int						index;
	struct s_node			*next;
	struct s_node			*prev;
}	t_node;


typedef struct s_stack
{
	t_node			*top;
	int				size;
}	t_stack;

t_node	*lst_new(int value);
t_node	*lst_last(t_node *stack);
void	lst_add_back(t_node **stack, t_node *new_node);
int		ft_is_number(char *str);
int		ft_atoi_safe(char *str, int *result);
int		check_duplicate(t_stack *stack, int num);
int		parse_and_fill_stack(t_stack *stack_a, int argc, char **argv);
void	push_to_stack(t_stack *stack, int value);
int		pop_to_stack(t_stack *stack);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	rotate(t_stack *stack);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate(t_stack *stack);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
#endif
