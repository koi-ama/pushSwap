/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamakasu <kamakasu@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:32:02 by koiama            #+#    #+#             */
/*   Updated: 2025/05/13 17:17:16 by kamakasu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ss(t_stack **a, t_stack **b)
{
	t_stack	*first_a;
	t_stack	*second_a;
	t_stack	*first_b;
	t_stack	*second_b;

	if ((!a || !*a || !(*a)->next) && (!b || !*b || !(*b)->next))
		return ;
	if (a && *a && (*a)->next)
	{
		first_a = *a;
		second_a = first_a->next;
		first_a->next = second_a->next;
		second_a->next = first_a;
		*a = second_a;
	}
	if (b && *b && (*b)->next)
	{
		first_b = *b;
		second_b = first_b->next;
		first_b->next = second_b->next;
		second_b->next = first_b;
		*b = second_b;
	}
	if ((a && *a && (*a)->print_ops) || (b && *b && (*b)->print_ops))
		ft_putendl_fd("ss", 1);
}
