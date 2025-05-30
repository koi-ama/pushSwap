/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamakasu <kamakasu@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:38:25 by koiama            #+#    #+#             */
/*   Updated: 2025/05/18 14:29:18 by kamakasu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*create_stack_node(int num, t_stack **stack)
{
	t_stack	*new;

	if (is_duplicate(*stack, num))
	{
		clear_stack(stack);
		return (NULL);
	}
	new = create_node(num);
	if (!new)
	{
		clear_stack(stack);
		return (NULL);
	}
	return (new);
}

static void	cleanup_and_exit(t_stack **stack, char **args, int argc)
{
	if (argc == 2)
		ft_free_split(args);
	error_exit(stack, NULL);
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
		num = (int)ft_atoi(args[i]);
		new = create_stack_node(num, &stack);
		if (!new)
			cleanup_and_exit(&stack, args, argc);
		add_node_back(&stack, new);
		i++;
	}
	if (argc == 2)
		ft_free_split(args);
	return (stack);
}

int	is_eol(char c)
{
	return (c == '\n' || c == '\r');
}
