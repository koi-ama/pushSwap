/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamakasu <kamakasu@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:29:46 by koiama            #+#    #+#             */
/*   Updated: 2025/05/13 18:26:21 by kamakasu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdlib.h>

static void	init_stacks(int argc, char **argv, t_stack **a, t_stack **b)
{
	if (!validate_input(argc, argv))
		error_exit(NULL, NULL);
	if (argc == 2 && argv[1][0] == '\0')
		error_exit(NULL, NULL);
	*a = parse_input(argc, argv);
	if (!*a && argc > 1)
		error_exit(NULL, NULL);
	*b = NULL;
	set_print_ops(*a, 0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	init_stacks(argc, argv, &a, &b);
	handle_checker_execution(&a, &b);
	clear_stack(&a);
	clear_stack(&b);
	return (0);
}
