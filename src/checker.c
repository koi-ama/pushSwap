/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamakasu <kamakasu@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:29:46 by koiama            #+#    #+#             */
/*   Updated: 2025/05/18 14:25:07 by kamakasu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stacks(int argc, char **argv, t_stack **a, t_stack **b)
{
	if (!validate_input(argc, argv))
		error_exit(NULL, NULL);
	if (argc == 2 && argv[1][0] == '\0')
		error_exit(NULL, NULL);
	*a = parse_input(argc, argv);
	if (!*a && argc > 1)
		error_exit(NULL, NULL);
	*b = NULL;
	set_print_ops(*a, 0);
}

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

void	read_instructions(t_stack **a, t_stack **b)
{
	char	*instruction;
	size_t	len;

	instruction = get_next_line(STDIN_FILENO);
	while (instruction)
	{
		len = ft_strlen(instruction);
		while (len && is_eol(instruction[len - 1]))
			instruction[--len] = '\0';
		if (len == 0 || !validate_instruction(instruction))
		{
			free(instruction);
			error_exit(a, b);
		}
		execute_instruction(a, b, instruction);
		free(instruction);
		instruction = get_next_line(STDIN_FILENO);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	init_stacks(argc, argv, &a, &b);
	read_instructions(&a, &b);
	if (is_sorted(a) && stack_size(b) == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	clear_stack(&a);
	clear_stack(&b);
	return (0);
}
