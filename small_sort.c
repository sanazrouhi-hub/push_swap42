#include "push_swap.h"

void	update_positions(t_stack *stack)
{
	int		pos;
	t_node	*current;

	if (!stack || !stack->top)
		return ;
	pos = 0;
	current = stack->top;
	while (current)
	{
		current->pos = pos;
		pos++;
		current = current->next;
	}
}

static int	find_min_value(t_stack *stack)
{
	int		min_val;
	t_node	*current;

	if (!stack || !stack->top)
		return (INT_MAX);
	current = stack->top;
	min_val = current->value;
	while (current)
	{
		if (current->value < min_val)
			min_val = current->value;
		current = current->next;
	}
	return (min_val);
}

void	sort_three(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	if (!stack_a || !*stack_a || !(*stack_a)->top || !(*stack_a)->top->next)
		return ;
	if (!(*stack_a)->top->next->next)
		return ;
	first = (*stack_a)->top->value;
	second = (*stack_a)->top->next->value;
	third = (*stack_a)->top->next->next->value;
	if (first > second && second < third && first < third)
		sa(*stack_a);
	else if (first > second && second > third)
	{
		sa(*stack_a);
		rra(*stack_a);
	}
	else if (first > second && second < third && first > third)
		ra(*stack_a);
	else if (first < second && second > third && first < third)
	{
		sa(*stack_a);
		ra(*stack_a);
	}
	else if (first < second && second > third && first > third)
		rra(*stack_a);
}

void	sort_four_five(t_stack **stack_a, t_stack **stack_b)
{
	int		min_val;
	int		size;
	t_node	*tmp;

	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	while (lst_size(*stack_a) > 3)
	{
		update_positions(*stack_a);
		min_val = find_min_value(*stack_a);
		size = lst_size(*stack_a);
		while ((*stack_a)->top->value != min_val)
		{
			tmp = (*stack_a)->top;
			if (tmp->pos <= size / 2)
				ra(*stack_a);
			else
				rra(*stack_a);
		}
		pb(*stack_a, *stack_b);
	}
	sort_three(stack_a);
	while ((*stack_b)->top)
		pa(*stack_a, *stack_b);
}