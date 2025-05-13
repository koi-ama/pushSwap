/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamakasu <kamakasu@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:53:21 by kamakasu          #+#    #+#             */
/*   Updated: 2025/05/13 18:35:42 by kamakasu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdlib.h>

void	handle_single_instruction(t_stack **a, t_stack **b)
{
	char	*instruction;

	instruction = get_next_line(STDIN_FILENO);
	if (!instruction)
	{
		if (is_sorted(*a) && !*b)
			ft_putendl_fd("OK", 1);
		else
			ft_putendl_fd("KO", 1);
		clear_stack(a);
		clear_stack(b);
		exit(0);
	}
	while (instruction)
	{
		free(instruction);
		instruction = get_next_line(STDIN_FILENO);
	}
	error_exit(a, b);
}

void	handle_checker_execution(t_stack **a, t_stack **b)
{
	if (stack_size(*a) <= 1)
	{
		handle_single_instruction(a, b);
	}
	read_instructions(a, b);
	if (is_sorted(*a) && stack_size(*b) == 0)
	{
		ft_putendl_fd("OK", 1);
	}
	else
	{
		ft_putendl_fd("KO", 1);
	}
}
