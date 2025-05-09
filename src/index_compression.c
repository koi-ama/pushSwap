/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_compression.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 00:00:00 by user             #+#    #+#             */
/*   Updated: 2024/05/08 00:00:00 by user            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#ifdef DEBUG
static void	print_stack_debug(t_stack *stack, const char *msg)
{
	t_stack	*current;

	ft_putstr_fd((char *)msg, 2);
	ft_putstr_fd(": ", 2);
	current = stack;
	while (current)
	{
		ft_putstr_fd("[v:", 2);
		ft_putnbr_fd(current->value, 2);
		ft_putstr_fd(" i:", 2);
		ft_putnbr_fd(current->index, 2);
		ft_putstr_fd("] ", 2);
		current = current->next;
	}
	ft_putstr_fd("\n", 2);
}
#endif

/* ソートされている配列で、値に対応するインデックスを設定 */
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

/* バブルソートで配列をソート */
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

/* インデックス圧縮の実装 */
void	compress_indices(t_stack **a)
{
	t_stack	*current;
	int		*array;
	int		size;
	int		i;

	if (!a || !*a)
		return ;
	size = stack_size(*a);
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		return ;
#ifdef DEBUG
	print_stack_debug(*a, "Before compression");
#endif
	current = *a;
	i = 0;
	while (current)
	{
		array[i++] = current->value;
		current = current->next;
	}
	sort_array(array, size);
	set_indices(a, array, size);
#ifdef DEBUG
	print_stack_debug(*a, "After compression");
#endif
	free(array);
}

/* スタックの最小値の位置を取得 */
int	get_pos_of_min(t_stack *stack)
{
	int		min_index;
	int		position;
	int		i;
	t_stack	*current;

	if (!stack)
		return (-1);
	min_index = stack->index;
	position = 0;
	i = 0;
	current = stack;
	while (current)
	{
		if (current->index < min_index)
		{
			min_index = current->index;
			position = i;
		}
		i++;
		current = current->next;
	}
	return (position);
}

/* 最小値を上に持ってくる最適な回転方法を選択 */
void	rotate_min_to_top(t_stack **a)
{
	int	position;
	int	size;

	if (!a || !*a)
		return ;
	position = get_pos_of_min(*a);
	size = stack_size(*a);
	if (position <= size / 2)
	{
		while (position--)
			op_ra(a);
	}
	else
	{
		position = size - position;
		while (position--)
			op_rra(a);
	}
}
