/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koiama <koiama@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-09 17:31:15 by koiama            #+#    #+#             */
/*   Updated: 2025-05-09 17:31:15 by koiama           ###   ########.fr       */
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
	ft_putendl_fd("pa", 1);
}
