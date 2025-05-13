/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamakasu <kamakasu@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:30:57 by koiama            #+#    #+#             */
/*   Updated: 2025/05/13 17:17:28 by kamakasu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		op_sa(a);
	else if (first > second && second > third && first > third)
	{
		op_sa(a);
		op_rra(a);
	}
	else if (first > second && second < third && first > third)
		op_ra(a);
	else if (first < second && second > third && first < third)
	{
		op_sa(a);
		op_ra(a);
	}
	else if (first < second && second > third && first > third)
		op_rra(a);
}
