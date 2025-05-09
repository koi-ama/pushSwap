/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 00:00:00 by user             #+#    #+#             */
/*   Updated: 2024/05/08 00:00:00 by user            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(t_stack *stack, int value)
{
	t_stack	*current;

	current = stack;
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

int	is_sorted(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
		return (1);
	current = stack;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	validate_input(int argc, char **argv)
{
	int		i;
	int		num;
	char	**args;

	if (argc == 1)
		return (0);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	i = 0;
	while (args[i])
	{
		if (!is_valid_number(args[i]))
		{
			if (argc == 2)
				ft_free_split(args);
			return (0);
		}
		num = ft_atoi(args[i]);
		if (num == 0 && args[i][0] != '0')
		{
			if (argc == 2)
				ft_free_split(args);
			return (0);
		}
		i++;
	}
	if (argc == 2)
		ft_free_split(args);
	return (1);
}

t_stack	*parse_input(int argc, char **argv)
{
	int		i;
	int		num;
	char	**args;
	t_stack	*stack;
	t_stack	*new;

	stack = NULL;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	i = 0;
	while (args[i])
	{
		num = ft_atoi(args[i]);
		if (is_duplicate(stack, num))
		{
			clear_stack(&stack);
			if (argc == 2)
				ft_free_split(args);
			error_exit(&stack, NULL);
		}
		new = create_node(num);
		if (!new)
		{
			clear_stack(&stack);
			if (argc == 2)
				ft_free_split(args);
			error_exit(&stack, NULL);
		}
		add_node_back(&stack, new);
		i++;
	}
	if (argc == 2)
		ft_free_split(args);
	return (stack);
}
