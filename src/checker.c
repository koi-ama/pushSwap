/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 00:00:00 by user             #+#    #+#             */
/*   Updated: 2024/05/08 00:00:00 by user            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

#ifdef DEBUG
void	print_stacks(t_stack *a, t_stack *b, char *op_name)
{
	t_stack	*curr_a;
	t_stack	*curr_b;
	int		max_len;
	int		i;

	curr_a = a;
	curr_b = b;
	max_len = 0;
	i = 0;
	while (curr_a || curr_b)
	{
		if (curr_a)
			curr_a = curr_a->next;
		if (curr_b)
			curr_b = curr_b->next;
		max_len++;
	}
	ft_putstr_fd("\n=== Operation: ", 1);
	if (op_name)
		ft_putstr_fd(op_name, 1);
	else
		ft_putstr_fd("Initial", 1);
	ft_putendl_fd(" ===", 1);
	ft_putendl_fd("Stack A | Stack B", 1);
	ft_putendl_fd("--------|--------", 1);
	curr_a = a;
	curr_b = b;
	while (i < max_len)
	{
		if (curr_a)
		{
			ft_putstr_fd(" ", 1);
			ft_putnbr_fd(curr_a->value, 1);
			curr_a = curr_a->next;
		}
		else
			ft_putstr_fd("  ", 1);
		ft_putstr_fd("     | ", 1);
		if (curr_b)
		{
			ft_putstr_fd(" ", 1);
			ft_putnbr_fd(curr_b->value, 1);
			curr_b = curr_b->next;
		}
		ft_putchar_fd('\n', 1);
		i++;
	}
	ft_putendl_fd("-----------------", 1);
}
#endif

static int	validate_instruction(char *instruction)
{
	if (!instruction)
		return (0);
	if (ft_strcmp(instruction, "sa\n") == 0 || ft_strcmp(instruction,
			"sb\n") == 0 || ft_strcmp(instruction, "ss\n") == 0
		|| ft_strcmp(instruction, "pa\n") == 0 || ft_strcmp(instruction,
			"pb\n") == 0 || ft_strcmp(instruction, "ra\n") == 0
		|| ft_strcmp(instruction, "rb\n") == 0 || ft_strcmp(instruction,
			"rr\n") == 0 || ft_strcmp(instruction, "rra\n") == 0
		|| ft_strcmp(instruction, "rrb\n") == 0 || ft_strcmp(instruction,
			"rrr\n") == 0)
		return (1);
	return (0);
}

static int	execute_instruction(t_stack **a, t_stack **b, char *instruction)
{
	char	*op;

	op = ft_strdup(instruction);
	if (op && op[ft_strlen(op) - 1] == '\n')
		op[ft_strlen(op) - 1] = '\0';
#ifdef DEBUG
	print_stacks(*a, *b, op);
#endif
	if (ft_strcmp(instruction, "sa\n") == 0)
		op_sa(a);
	else if (ft_strcmp(instruction, "sb\n") == 0)
		op_sb(b);
	else if (ft_strcmp(instruction, "ss\n") == 0)
		op_ss(a, b);
	else if (ft_strcmp(instruction, "pa\n") == 0)
		op_pa(a, b);
	else if (ft_strcmp(instruction, "pb\n") == 0)
		op_pb(a, b);
	else if (ft_strcmp(instruction, "ra\n") == 0)
		op_ra(a);
	else if (ft_strcmp(instruction, "rb\n") == 0)
		op_rb(b);
	else if (ft_strcmp(instruction, "rr\n") == 0)
		op_rr(a, b);
	else if (ft_strcmp(instruction, "rra\n") == 0)
		op_rra(a);
	else if (ft_strcmp(instruction, "rrb\n") == 0)
		op_rrb(b);
	else if (ft_strcmp(instruction, "rrr\n") == 0)
		op_rrr(a, b);
#ifdef DEBUG
	print_stacks(*a, *b, NULL);
#endif
	free(op);
	return (1);
}

static void	read_instructions(t_stack **a, t_stack **b)
{
	char	*instruction;

#ifdef DEBUG
	print_stacks(*a, *b, NULL);
#endif
	while (1)
	{
		instruction = get_next_line(0);
		if (!instruction)
			break ;
		if (!validate_instruction(instruction))
		{
			free(instruction);
			error_exit(a, b);
		}
		execute_instruction(a, b, instruction);
		free(instruction);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (!validate_input(argc, argv))
		error_exit(NULL, NULL);
	a = parse_input(argc, argv);
	b = NULL;
	read_instructions(&a, &b);
#ifdef DEBUG
	ft_putstr_fd("\n=== Final State ===\n", 1);
	print_stacks(a, b, NULL);
	ft_putstr_fd("Result: ", 1);
#endif
	if (is_sorted(a) && !b)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	clear_stack(&a);
	clear_stack(&b);
	return (0);
}
