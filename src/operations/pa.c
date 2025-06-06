/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamakasu <kamakasu@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:31:15 by koiama            #+#    #+#             */
/*   Updated: 2025/05/13 17:17:14 by kamakasu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!b || !*b)
		return ;
	temp = *b;
	*b = (*b)->next;
	if (!*a)
	{
		temp->next = NULL;
		*a = temp;
	}
	else
	{
		temp->next = *a;
		*a = temp;
	}
	if (*a && (*a)->print_ops)
		ft_putendl_fd("pa", 1);
}
