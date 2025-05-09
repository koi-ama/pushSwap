/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koiama <koiama@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-09 17:30:36 by koiama            #+#    #+#             */
/*   Updated: 2025-05-09 17:30:36 by koiama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	quick_sort_small_a(t_stack **a, int size)
{
	if (size <= 3)
	{
		if (size == 2 && (*a)->index > (*a)->next->index)
			op_sa(a);
		else if (size == 3)
			sort_three(a);
		return ;
	}
}

static void	quick_sort_partition_a(t_stack **a, t_stack **b, int size,
		t_quick_sort_data *data)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((*a)->index < data->pivot)
		{
			op_pb(a, b);
			data->pushed++;
		}
		else
		{
			data->rotated++;
			op_ra(a);
		}
		i++;
	}
}

void	quick_sort_a(t_stack **a, t_stack **b, int size)
{
	t_quick_sort_data	data;

	if (size <= 3)
	{
		quick_sort_small_a(a, size);
		return ;
	}
	data.pivot = get_median(*a, size);
	data.pushed = 0;
	data.rotated = 0;
	quick_sort_partition_a(a, b, size, &data);
	rev_rotate_both(a, b, &data.rotated, &data.pushed);
	quick_sort_a(a, b, size - data.pushed);
	quick_sort_b(b, a, data.pushed);
}
