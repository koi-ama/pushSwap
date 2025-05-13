/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamakasu <kamakasu@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:52:34 by kamakasu          #+#    #+#             */
/*   Updated: 2025/05/13 23:44:53 by kamakasu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdlib.h>

int	validate_instruction(char *s)
{
	size_t	len;

	len = ft_strlen(s);
	if (len > 0 && s[len - 1] == '\n')
		s[--len] = '\0';
	if (!ft_strcmp(s, "sa") || !ft_strcmp(s, "sb") || !ft_strcmp(s, "ss")
		|| !ft_strcmp(s, "pa") || !ft_strcmp(s, "pb") || !ft_strcmp(s, "ra")
		|| !ft_strcmp(s, "rb") || !ft_strcmp(s, "rr") || !ft_strcmp(s, "rra")
		|| !ft_strcmp(s, "rrb") || !ft_strcmp(s, "rrr"))
		return (1);
	return (0);
}

void	execute_instruction(t_stack **a, t_stack **b, char *instruction)
{
	if (ft_strcmp(instruction, "sa") == 0)
		op_sa(a);
	else if (ft_strcmp(instruction, "sb") == 0)
		op_sb(b);
	else if (ft_strcmp(instruction, "ss") == 0)
		op_ss(a, b);
	else if (ft_strcmp(instruction, "pa") == 0)
		op_pa(a, b);
	else if (ft_strcmp(instruction, "pb") == 0)
		op_pb(a, b);
	else if (ft_strcmp(instruction, "ra") == 0)
		op_ra(a);
	else if (ft_strcmp(instruction, "rb") == 0)
		op_rb(b);
	else if (ft_strcmp(instruction, "rr") == 0)
		op_rr(a, b);
	else if (ft_strcmp(instruction, "rra") == 0)
		op_rra(a);
	else if (ft_strcmp(instruction, "rrb") == 0)
		op_rrb(b);
	else if (ft_strcmp(instruction, "rrr") == 0)
		op_rrr(a, b);
}

void	execute_push_swap(t_stack **a, t_stack **b, char *instruction)
{
	if ((ft_strcmp(instruction, "pa") == 0 && !*b) || (ft_strcmp(instruction,
				"pb") == 0 && !*a) || ((ft_strcmp(instruction, "ss") == 0
				|| ft_strcmp(instruction, "sa") == 0) && (!*a || !(*a)->next))
		|| ((ft_strcmp(instruction, "ss") == 0 || ft_strcmp(instruction,
					"sb") == 0) && (!*b || !(*b)->next))
		|| ((ft_strcmp(instruction, "ra") == 0 || ft_strcmp(instruction,
					"rr") == 0) && (!*a || !(*a)->next))
		|| ((ft_strcmp(instruction, "rra") == 0 || ft_strcmp(instruction,
					"rrr") == 0) && (!*a || !(*a)->next))
		|| ((ft_strcmp(instruction, "rb") == 0 || ft_strcmp(instruction,
					"rr") == 0) && !*b) || ((ft_strcmp(instruction, "rrb") == 0
				|| ft_strcmp(instruction, "rrr") == 0) && !*b))
		error_exit(a, b);
	execute_instruction(a, b, instruction);
}

void	read_one_instruction(t_stack **a, t_stack **b, char *instruction)
{
	size_t	len;

	if (!instruction || instruction[0] == '\n' || instruction[0] == '\0')
	{
		free(instruction);
		return ;
	}
	len = ft_strlen(instruction);
	while (len > 0 && ft_strchr("\n\r", instruction[len - 1]))
		instruction[--len] = '\0';
	if (!validate_instruction(instruction))
	{
		free(instruction);
		error_exit(a, b);
	}
	execute_push_swap(a, b, instruction);
	free(instruction);
}

void	read_instructions(t_stack **a, t_stack **b)
{
	char	*instruction;

	while (1)
	{
		instruction = get_next_line(STDIN_FILENO);
		if (!instruction)
			break ;
		read_one_instruction(a, b, instruction);
	}
}
