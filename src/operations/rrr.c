/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 00:00:00 by user             #+#    #+#             */
/*   Updated: 2024/05/08 00:00:00 by user            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rrr(t_stack **a, t_stack **b)
{
	t_stack *last_a;
	t_stack *second_last_a;
	t_stack *last_b;
	t_stack *second_last_b;

	if ((!a || !*a || !(*a)->next) && (!b || !*b || !(*b)->next))
		return ;
	if (a && *a && (*a)->next)
	{
		last_a = *a;
		while (last_a->next)
		{
			second_last_a = last_a;
			last_a = last_a->next;
		}
		second_last_a->next = NULL;
		last_a->next = *a;
		*a = last_a;
	}
	if (b && *b && (*b)->next)
	{
		last_b = *b;
		while (last_b->next)
		{
			second_last_b = last_b;
			last_b = last_b->next;
		}
		second_last_b->next = NULL;
		last_b->next = *b;
		*b = last_b;
	}
	ft_putendl_fd("rrr", 1);
}