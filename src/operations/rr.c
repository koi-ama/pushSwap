/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamakasu <kamakasu@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 04:08:37 by kamakasu          #+#    #+#             */
/*   Updated: 2025/05/13 17:17:23 by kamakasu         ###   ########.fr       */
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
	if (*a && (*a)->print_ops)
		ft_putendl_fd("ra", 1);
}

void	op_rb(t_stack **b)
{
	rotate_stack(b);
	if (*b && (*b)->print_ops)
		ft_putendl_fd("rb", 1);
}

void	op_rr(t_stack **a, t_stack **b)
{
	rotate_stack(a);
	rotate_stack(b);
	if ((a && *a && (*a)->print_ops) || (b && *b && (*b)->print_ops))
		ft_putendl_fd("rr", 1);
}
