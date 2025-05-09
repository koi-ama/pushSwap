/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamakasu <kamakasu@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:30:52 by koiama            #+#    #+#             */
/*   Updated: 2025/05/10 04:13:06 by kamakasu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack **a, t_stack **b, int *count_a, int *count_b)
{
	while (*count_a > 0 && *count_b > 0)
	{
		op_rr(a, b);
		(*count_a)--;
		(*count_b)--;
	}
	while (*count_a > 0)
	{
		op_ra(a);
		(*count_a)--;
	}
	while (*count_b > 0)
	{
		op_rb(b);
		(*count_b)--;
	}
}

void	rev_rotate_both(t_stack **a, t_stack **b, int *count_a, int *count_b)
{
	while (*count_a > 0 && *count_b > 0)
	{
		op_rrr(a, b);
		(*count_a)--;
		(*count_b)--;
	}
	while (*count_a > 0)
	{
		op_rra(a);
		(*count_a)--;
	}
	while (*count_b > 0)
	{
		op_rrb(b);
		(*count_b)--;
	}
}

void	smart_rotate(t_stack **stack, int target_pos, void (*rot)(t_stack **),
		void (*rev_rot)(t_stack **))
{
	int	size;
	int	rotations;

	size = stack_size(*stack);
	if (target_pos <= size / 2)
	{
		rotations = target_pos;
		while (rotations--)
			rot(stack);
	}
	else
	{
		rotations = size - target_pos;
		while (rotations--)
			rev_rot(stack);
	}
}

int	get_pos_of_min(t_stack *stack)
{
	int		min_index;
	int		position;
	int		i;
	t_stack	*current;

	if (!stack)
		return (-1);
	min_index = stack->index;
	position = 0;
	i = 0;
	current = stack;
	while (current)
	{
		if (current->index < min_index)
		{
			min_index = current->index;
			position = i;
		}
		i++;
		current = current->next;
	}
	return (position);
}

void	rotate_min_to_top(t_stack **a)
{
	int	position;
	int	size;

	if (!a || !*a)
		return ;
	position = get_pos_of_min(*a);
	size = stack_size(*a);
	if (position <= size / 2)
	{
		while (position--)
			op_ra(a);
	}
	else
	{
		position = size - position;
		while (position--)
			op_rra(a);
	}
}
