/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koiama <koiama@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-09 17:43:59 by koiama            #+#    #+#             */
/*   Updated: 2025-05-09 17:43:59 by koiama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate_stack(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	op_rra(t_stack **a)
{
	rev_rotate_stack(a);
	ft_putendl_fd("rra", 1);
}

void	op_rrb(t_stack **b)
{
	rev_rotate_stack(b);
	ft_putendl_fd("rrb", 1);
}

void	op_rrr(t_stack **a, t_stack **b)
{
	rev_rotate_stack(a);
	rev_rotate_stack(b);
	ft_putendl_fd("rrr", 1);
}
