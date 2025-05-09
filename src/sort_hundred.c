/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koiama <koiama@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-09 17:30:31 by koiama            #+#    #+#             */
/*   Updated: 2025-05-09 17:30:31 by koiama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bring_to_top(t_stack **s, int pos, void (*ra)(t_stack **),
		void (*rra)(t_stack **))
{
	int	size;

	size = stack_size(*s);
	if (pos <= size / 2)
		while (pos--)
			ra(s);
	else
	{
		pos = size - pos;
		while (pos--)
			rra(s);
	}
}

static void	push_to_b_by_chunks(t_stack **a, t_stack **b)
{
	const int	chunk = 20;
	int			i;
	int			idx;

	i = 0;
	while (*a)
	{
		idx = (*a)->index;
		if (idx <= i)
		{
			op_pb(a, b);
			op_rb(b);
			i++;
		}
		else if (idx <= i + chunk)
		{
			op_pb(a, b);
			i++;
		}
		else
			op_ra(a);
	}
}

static void	push_back_to_a(t_stack **a, t_stack **b)
{
	int	pos;

	while (*b)
	{
		pos = get_position_index(*b, get_max_index(*b));
		bring_to_top(b, pos, op_rb, op_rrb);
		op_pa(a, b);
	}
}

void	sort_hundred(t_stack **a, t_stack **b)
{
	push_to_b_by_chunks(a, b);
	push_back_to_a(a, b);
}
