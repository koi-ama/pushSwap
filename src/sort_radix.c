/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamakasu <kamakasu@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:30:48 by koiama            #+#    #+#             */
/*   Updated: 2025/05/10 04:13:01 by kamakasu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	simple_radix_sort(t_stack **a, t_stack **b, int size)
{
	int	i;
	int	j;
	int	num;
	int	max_bits;

	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			num = (*a)->index;
			if ((num >> i) & 1)
				op_ra(a);
			else
				op_pb(a, b);
			j++;
		}
		while (*b)
			op_pa(a, b);
		i++;
	}
}

void	radix_sort(t_stack **a, t_stack **b, int size)
{
	if (!a || !*a || !b)
		return ;
	simple_radix_sort(a, b, size);
	rotate_min_to_top(a);
}
