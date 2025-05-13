/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamakasu <kamakasu@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:29:51 by koiama            #+#    #+#             */
/*   Updated: 2025/05/13 20:15:46 by kamakasu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

/* Checker execution functions */
int		validate_instruction(char *s);
void	execute_instruction(t_stack **a, t_stack **b, char *instruction);
void	execute_push_swap(t_stack **a, t_stack **b, char *instruction);
void	read_one_instruction(t_stack **a, t_stack **b, char *instruction);
void	read_instructions(t_stack **a, t_stack **b);

/* Checker utility functions */
void	handle_single_instruction(t_stack **a, t_stack **b);
void	handle_checker_execution(t_stack **a, t_stack **b);

void	print_stacks(t_stack *a, char *op_name);

#endif
