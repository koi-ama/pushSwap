/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 00:00:00 by user             #+#    #+#             */
/*   Updated: 2024/05/08 00:00:00 by user            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	get_median(t_stack *stack, int size)
{
	int		*array;
	int		i;
	t_stack	*current;
	int		median;

	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		return (-1);
	current = stack;
	i = 0;
	while (current && i < size)
	{
		array[i++] = current->index;
		current = current->next;
	}
	sort_array(array, size);
	median = array[size / 2];
	free(array);
	return (median);
}

int	get_max_bits(int size)
{
	int	max_bits;
	int	max_num;

	max_bits = 0;
	max_num = size - 1;
	while (max_num)
	{
		max_bits++;
		max_num >>= 1;
	}
	return (max_bits);
}
