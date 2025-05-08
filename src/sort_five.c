/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 00:00:00 by user             #+#    #+#             */
/*   Updated: 2024/05/08 00:00:00 by user            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_min_to_b(t_stack **a, t_stack **b)
{
	int	min;
	int	pos;
	int	size;

	min = get_min_value(*a);
	pos = get_position(*a, min);
	size = stack_size(*a);
	if (pos <= size / 2)
	{
		while (pos--)
			op_ra(a);
	}
	else
	{
		pos = size - pos;
		while (pos--)
			op_rra(a);
	}
	op_pb(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	move_min_to_b(a, b);
	move_min_to_b(a, b);
	sort_three(a);
	op_pa(a, b);
	op_pa(a, b);
}