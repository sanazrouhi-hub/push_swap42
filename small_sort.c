#include "push_swap.h"

void update_position(t_stack *stack)
{
	int position;

	position = 0;
	while (stack)
	{
		stack->index = position;
		position++;
		stack = stack->next;
	}
}

static int find_min_value(t_stack *stack)
{
	int min_value;

	if (!stack)
		return (0);
	min_value = stack->value;
	while (stack)
	{
		if (stack->value < min_value)
			min_value = stack->value;
		stack = stack->next;
	}
	return (min_value);
}

void sort_three(t_stack *stack)
{
	int firstl
	int second;
	int third;

	if (!stack_a || !*stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
		return;
	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(stack_a);
	else if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a);
}

void	sort_four_five(t_stack **stack_a, t_stack **stack_b)
{
	int		min_val;
	int		size;
	t_stack	*tmp;

	while (lst_size(*stack_a) > 3)
	{
		update_positions(*stack_a);
		min_val = find_min_value(*stack_a);
		size = lst_size(*stack_a);
		while ((*stack_a)->value != min_val)
		{
			tmp = *stack_a;
			while (tmp && tmp->value != min_val)
				tmp = tmp->next;
			if (tmp->index <= size / 2)
				ra(stack_a);
			else
				rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}