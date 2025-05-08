/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 00:00:00 by user             #+#    #+#             */
/*   Updated: 2024/05/08 00:00:00 by user            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rr(t_stack **a, t_stack **b)
{
	t_stack *first_a;
	t_stack *last_a;
	t_stack *first_b;
	t_stack *last_b;

	if ((!a || !*a || !(*a)->next) && (!b || !*b || !(*b)->next))
		return ;
	if (a && *a && (*a)->next)
	{
		first_a = *a;
		*a = first_a->next;
		last_a = *a;
		while (last_a->next)
			last_a = last_a->next;
		last_a->next = first_a;
		first_a->next = NULL;
	}
	if (b && *b && (*b)->next)
	{
		first_b = *b;
		*b = first_b->next;
		last_b = *b;
		while (last_b->next)
			last_b = last_b->next;
		last_b->next = first_b;
		first_b->next = NULL;
	}
	ft_putendl_fd("rr", 1);
}