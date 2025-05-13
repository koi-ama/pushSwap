/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamakasu <kamakasu@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:31:21 by koiama            #+#    #+#             */
/*   Updated: 2025/05/13 17:17:22 by kamakasu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!a || !*a)
		return ;
	temp = *a;
	*a = (*a)->next;
	if (!*b)
	{
		temp->next = NULL;
		*b = temp;
	}
	else
	{
		temp->next = *b;
		*b = temp;
	}
	if (*b && (*b)->print_ops)
		ft_putendl_fd("pb", 1);
}
