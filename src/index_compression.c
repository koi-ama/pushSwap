/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_compression.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamakasu <kamakasu@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:30:02 by koiama            #+#    #+#             */
/*   Updated: 2025/05/10 04:12:14 by kamakasu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_indices(t_stack **a, int *sorted, int size)
{
	t_stack	*current;
	int		i;

	i = 0;
	while (i < size)
	{
		current = *a;
		while (current)
		{
			if (current->value == sorted[i])
			{
				current->index = i;
				break ;
			}
			current = current->next;
		}
		i++;
	}
}

static void	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static int	check_duplicates(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void	fill_array(t_stack *stack, int *array)
{
	int	i;

	i = 0;
	while (stack)
	{
		array[i++] = stack->value;
		stack = stack->next;
	}
}

void	compress_indices(t_stack **a)
{
	t_stack	*current;
	int		*array;
	int		size;

	if (!a || !*a)
		return ;
	size = stack_size(*a);
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		return ;
	current = *a;
	fill_array(current, array);
	if (check_duplicates(array, size))
	{
		free(array);
		error_exit(a, NULL);
		return ;
	}
	sort_array(array, size);
	set_indices(a, array, size);
	free(array);
}
