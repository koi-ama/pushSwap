/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 00:00:00 by user             #+#    #+#             */
/*   Updated: 2024/05/08 00:00:00 by user            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/include/libft.h"

/* Data Structures */
typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef t_node	t_stack;

/* Stack Operations */
void	op_sa(t_stack **a);
void	op_sb(t_stack **b);
void	op_ss(t_stack **a, t_stack **b);
void	op_pa(t_stack **a, t_stack **b);
void	op_pb(t_stack **a, t_stack **b);
void	op_ra(t_stack **a);
void	op_rb(t_stack **b);
void	op_rr(t_stack **a, t_stack **b);
void	op_rra(t_stack **a);
void	op_rrb(t_stack **b);
void	op_rrr(t_stack **a, t_stack **b);

/* Stack Management */
t_stack	*create_node(int value);
void	add_node_front(t_stack **stack, t_stack *new);
void	add_node_back(t_stack **stack, t_stack *new);
void	clear_stack(t_stack **stack);
int		stack_size(t_stack *stack);

/* Input Validation */
int		validate_input(int argc, char **argv);
int		is_duplicate(t_stack *stack, int value);
int		is_sorted(t_stack *stack);
t_stack	*parse_input(int argc, char **argv);

/* Sorting Algorithms */
void	sort_three(t_stack **a);
void	sort_five(t_stack **a, t_stack **b);
void	sort_large(t_stack **a, t_stack **b, int size);

/* Utility Functions */
void	error_exit(t_stack **a, t_stack **b);
int		get_min_value(t_stack *stack);
int		get_max_value(t_stack *stack);
int		get_position(t_stack *stack, int value);

#endif 