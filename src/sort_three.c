/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 00:00:00 by user             #+#    #+#             */
/*   Updated: 2024/05/08 00:00:00 by user            ###   ########.fr       */
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
