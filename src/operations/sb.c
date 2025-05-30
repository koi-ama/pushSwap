/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamakasu <kamakasu@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:31:58 by koiama            #+#    #+#             */
/*   Updated: 2025/05/13 17:17:15 by kamakasu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sb(t_stack **b)
{
	t_stack	*first;
	t_stack	*second;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*b = second;
	if (*b && (*b)->print_ops)
		ft_putendl_fd("sb", 1);
}
