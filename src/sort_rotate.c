/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 00:00:00 by user             #+#    #+#             */
/*   Updated: 2024/05/08 00:00:00 by user            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack **a, t_stack **b, int *count_a, int *count_b)
{
	while (*count_a > 0 && *count_b > 0)
	{
		op_rr(a, b);
		(*count_a)--;
		(*count_b)--;
	}
	while (*count_a > 0)
	{
		op_ra(a);
		(*count_a)--;
	}
	while (*count_b > 0)
	{
		op_rb(b);
		(*count_b)--;
	}
}

void	rev_rotate_both(t_stack **a, t_stack **b, int *count_a, int *count_b)
{
	while (*count_a > 0 && *count_b > 0)
	{
		op_rrr(a, b);
		(*count_a)--;
		(*count_b)--;
	}
	while (*count_a > 0)
	{
		op_rra(a);
		(*count_a)--;
	}
	while (*count_b > 0)
	{
		op_rrb(b);
		(*count_b)--;
	}
}
