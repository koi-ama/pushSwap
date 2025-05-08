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

static void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;

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
}

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	if (!validate_input(argc, argv))
		error_exit(NULL, NULL);
	a = parse_input(argc, argv);
	b = NULL;
	sort_stack(&a, &b);
	clear_stack(&a);
	clear_stack(&b);
	return (0);
}