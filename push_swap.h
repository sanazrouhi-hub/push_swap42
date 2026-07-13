/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkhadka <shkhadka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:30:28 by srouhi            #+#    #+#             */
/*   Updated: 2026/07/13 15:42:58 by shkhadka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR
}					t_op;

typedef struct s_bench
{
	int				on;
	int				count[11];
	double			disorder;
	char			*name;
	char			*complexity;
}					t_bench;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
	int				pos;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
	t_bench			*bench;
}					t_stack;

t_node				*lst_new(int value);
t_node				*lst_last(t_node *stack);
void				free_stack(t_stack *stack);
void				lst_add_back(t_node **stack, t_node *new_node);
int					ft_is_number(char *str);
int					ft_atoi_safe(char *str, int *result);
int					check_duplicate(t_stack *stack, int num);
int					parse_and_fill_stack(t_stack *stack_a, int argc,
						char **argv, int start);
void				push_to_stack(t_stack *stack, t_node *node);
t_node				*pop_to_stack(t_stack *stack);
void				sa(t_stack *stack_a);
void				sb(t_stack *stack_b);
void				ss(t_stack *stack_a, t_stack *stack_b);
void				pa(t_stack *stack_a, t_stack *stack_b);
void				pb(t_stack *stack_a, t_stack *stack_b);
void				rotate(t_stack *stack);
void				ra(t_stack *stack_a);
void				rb(t_stack *stack_b);
void				rr(t_stack *stack_a, t_stack *stack_b);
void				reverse_rotate(t_stack *stack);
void				rra(t_stack *stack_a);
void				rrb(t_stack *stack_b);
void				rrr(t_stack *stack_a, t_stack *stack_b);
t_node				*find_target(t_stack *stack_a, int value);
void				position_update(t_stack *stack);
int					cost_to_top(t_stack *stack, t_node *node);
int					total_cost(t_stack *stack_a, t_stack *stack_b,
						t_node *b_node);
int					lst_size(t_stack *stack);
void				update_positions(t_stack *stack);
void				sort_three(t_stack **stack_a);
void				sort_four_five(t_stack **stack_a, t_stack **stack_b);
void				execute_move(t_stack *a, t_stack *b, t_node *b_node);
t_node				*find_cheapest(t_stack *a, t_stack *b);
void				push_to_b(t_stack *a, t_stack *b);
void				move_min_to_top(t_stack *a);
void				big_sort(t_stack *a, t_stack *b);
void				chunk_sort(t_stack *a, t_stack *b);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
void				radix_sort(t_stack *stack_a, t_stack *stack_b);
void				adaptive(t_stack *a, t_stack *b);
void				run_sort(t_stack *a, t_stack *b, char *flag);
int					ft_strcmp(const char *s1, const char *s2);
int					is_sorted(t_stack *stack);
void				bench_init(t_bench *bench);
void				bench_attach(t_bench *bench, t_stack *a, t_stack *b);
void				bench_add(t_bench *bench, t_op op);
void				bench_set(t_bench *bench, char *name, char *complexity);
void				print_bench(t_bench *b);
double				measure_disorder(t_stack *a);
void				put_str(char *s);
void				put_nbr(int n);

#endif
