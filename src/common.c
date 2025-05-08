/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 00:00:00 by user             #+#    #+#             */
/*   Updated: 2024/05/08 00:00:00 by user            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int value)
{
	t_stack	*new;

	new = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

void	add_node_front(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;
	new->next = *stack;
	*stack = new;
}

void	add_node_back(t_stack **stack, t_stack *new)
{
	t_stack	*current;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	current = *stack;
	while (current->next)
		current = current->next;
	current->next = new;
}

void	clear_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

int	stack_size(t_stack *stack)
{
	int		size;
	t_stack	*current;

	size = 0;
	current = stack;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

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

void	error_exit(t_stack **a, t_stack **b)
{
	if (a)
		clear_stack(a);
	if (b)
		clear_stack(b);
	ft_putendl_fd("Error", 2);
	exit(1);
}