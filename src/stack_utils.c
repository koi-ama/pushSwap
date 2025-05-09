/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koiama <koiama@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-09 17:31:08 by koiama            #+#    #+#             */
/*   Updated: 2025-05-09 17:31:08 by koiama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_value(t_stack *stack)
{
	int		min;
	t_stack	*current;

	if (!stack)
		return (0);
	min = stack->value;
	current = stack->next;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	get_max_value(t_stack *stack)
{
	int		max;
	t_stack	*current;

	if (!stack)
		return (0);
	max = stack->value;
	current = stack->next;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	get_position(t_stack *stack, int value)
{
	int		pos;
	t_stack	*current;

	pos = 0;
	current = stack;
	while (current)
	{
		if (current->value == value)
			return (pos);
		pos++;
		current = current->next;
	}
	return (-1);
}

int	get_position_index(t_stack *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

int	get_max_index(t_stack *stack)
{
	int		max;
	t_stack	*current;

	if (!stack)
		return (0);
	max = stack->index;
	current = stack->next;
	while (current)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	return (max);
}
