/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 00:00:00 by user             #+#    #+#             */
/*   Updated: 2024/05/08 00:00:00 by user            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#ifdef DEBUG
static void	print_stack_debug(t_stack *stack, const char *msg)
{
	t_stack	*current;

	ft_putstr_fd((char *)msg, 2);
	ft_putstr_fd(": ", 2);
	current = stack;
	while (current)
	{
		ft_putstr_fd("[v:", 2);
		ft_putnbr_fd(current->value, 2);
		ft_putstr_fd(" i:", 2);
		ft_putnbr_fd(current->index, 2);
		ft_putstr_fd("] ", 2);
		current = current->next;
	}
	ft_putstr_fd("\n", 2);
}
#endif

static void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;

#ifdef DEBUG
	print_stack_debug(*a, "Initial stack");
#endif
	size = stack_size(*a);
	if (size <= 1)
		return ;
	else if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			op_sa(a);
	}
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else
		sort_large(a, b, size);
#ifdef DEBUG
	print_stack_debug(*a, "Final stack");
#endif
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (!validate_input(argc, argv))
		error_exit(NULL, NULL);
	a = parse_input(argc, argv);
	b = NULL;
	sort_stack(&a, &b);
	clear_stack(&a);
	clear_stack(&b);
	return (0);
}
