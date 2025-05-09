/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamakasu <kamakasu@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:30:25 by koiama            #+#    #+#             */
/*   Updated: 2025/05/10 04:12:40 by kamakasu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_min_to_b(t_stack **a, t_stack **b)
{
	int	min;
	int	pos;
	int	size;

	if (!a || !*a || !(*a)->next)
		return ;
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

static void	sort_four_helper(t_stack **a, t_stack **b, int pos)
{
	if (pos == 0)
		op_pb(a, b);
	else if (pos == 1)
	{
		op_sa(a);
		op_pb(a, b);
	}
	else if (pos == 2)
	{
		op_ra(a);
		op_ra(a);
		op_pb(a, b);
	}
	else if (pos == 3)
	{
		op_rra(a);
		op_pb(a, b);
	}
}

static void	sort_four(t_stack **a, t_stack **b)
{
	int	min;
	int	pos;

	if (!a || !*a || !(*a)->next)
		return ;
	min = get_min_value(*a);
	pos = get_position(*a, min);
	sort_four_helper(a, b, pos);
	if (*a && (*a)->next && (*a)->next->next)
		sort_three(a);
	if (b && *b)
		op_pa(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	size;

	if (!a || !*a)
		return ;
	size = stack_size(*a);
	if (size == 4)
		sort_four(a, b);
	else if (size == 5)
	{
		move_min_to_b(a, b);
		move_min_to_b(a, b);
		if (*b && (*b)->value < (*b)->next->value)
			op_sb(b);
		sort_three(a);
		op_pa(a, b);
		op_pa(a, b);
	}
}

void	sort_six_to_fifteen(t_stack **a, t_stack **b, int size)
{
	int	i;

	i = 0;
	while (size - i > 5)
	{
		move_min_to_b(a, b);
		i++;
	}
	sort_five(a, b);
	while (i--)
		op_pa(a, b);
}
