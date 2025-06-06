/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamakasu <kamakasu@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:30:42 by koiama            #+#    #+#             */
/*   Updated: 2025/05/13 17:17:34 by kamakasu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	quick_sort_small_b(t_stack **b, t_stack **a, int size)
{
	if (size <= 1)
	{
		if (size == 1)
			op_pa(a, b);
		return ;
	}
}

static void	quick_sort_partition_b(t_stack **b, t_stack **a, int size,
		t_quick_sort_data *data)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((*b)->index >= data->pivot)
		{
			op_pa(a, b);
			data->pushed++;
		}
		else
		{
			data->rotated++;
			op_rb(b);
		}
		i++;
	}
}

void	quick_sort_b(t_stack **b, t_stack **a, int size)
{
	t_quick_sort_data	data;

	if (size <= 1)
	{
		quick_sort_small_b(b, a, size);
		return ;
	}
	data.pivot = get_median(*b, size);
	data.pushed = 0;
	data.rotated = 0;
	quick_sort_partition_b(b, a, size, &data);
	quick_sort_a(a, b, data.pushed);
	rev_rotate_both(a, b, &data.pushed, &data.rotated);
	quick_sort_b(b, a, size - data.pushed);
}
