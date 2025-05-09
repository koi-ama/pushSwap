/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koiama <koiama@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-09 17:43:53 by koiama            #+#    #+#             */
/*   Updated: 2025-05-09 17:43:53 by koiama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	op_ra(t_stack **a)
{
	rotate_stack(a);
	ft_putendl_fd("ra", 1);
}

void	op_rb(t_stack **b)
{
	rotate_stack(b);
	ft_putendl_fd("rb", 1);
}

void	op_rr(t_stack **a, t_stack **b)
{
	rotate_stack(a);
	rotate_stack(b);
	ft_putendl_fd("rr", 1);
}
