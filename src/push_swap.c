/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamakasu <kamakasu@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:30:14 by koiama            #+#    #+#             */
/*   Updated: 2025/05/10 04:12:30 by kamakasu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size <= 1)
		return ;
	if (is_sorted(*a))
		return ;
	compress_indices(a);
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			op_sa(a);
	}
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else if (size <= 15)
		sort_six_to_fifteen(a, b, size);
	else if (size <= 100)
		sort_hundred(a, b);
	else
		radix_sort(a, b, size);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	if (!validate_input(argc, argv))
		error_exit(NULL, NULL);
	a = parse_input(argc, argv);
	if (!a)
		error_exit(NULL, NULL);
	b = NULL;
	sort_stack(&a, &b);
	clear_stack(&a);
	clear_stack(&b);
	return (0);
}
