/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamakasu <kamakasu@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 04:09:06 by kamakasu          #+#    #+#             */
/*   Updated: 2025/05/18 14:26:58 by kamakasu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <limits.h>
# include <stddef.h>

/* Data Structures */
typedef struct s_node
{
	int				value;
	int				index;
	int				print_ops;
	struct s_node	*next;
}					t_node;

typedef t_node		t_stack;

typedef struct s_quick_sort_data
{
	int				pivot;
	int				pushed;
	int				rotated;
}					t_quick_sort_data;

/* Stack Operations */
void				op_sa(t_stack **a);
void				op_sb(t_stack **b);
void				op_ss(t_stack **a, t_stack **b);
void				op_pa(t_stack **a, t_stack **b);
void				op_pb(t_stack **a, t_stack **b);
void				op_ra(t_stack **a);
void				op_rb(t_stack **b);
void				op_rr(t_stack **a, t_stack **b);
void				op_rra(t_stack **a);
void				op_rrb(t_stack **b);
void				op_rrr(t_stack **a, t_stack **b);

/* Stack Management */
t_stack				*create_node(int value);
void				add_node_front(t_stack **stack, t_stack *new);
void				add_node_back(t_stack **stack, t_stack *new);
void				clear_stack(t_stack **stack);
int					stack_size(t_stack *stack);

/* Input Validation */
int					validate_input(int argc, char **argv);
int					is_duplicate(t_stack *stack, int value);
int					is_sorted(t_stack *stack);
t_stack				*parse_input(int argc, char **argv);
void				set_print_ops(t_stack *stack, int value);
int					is_eol(char c);

/* Sorting Algorithms */
void				sort_three(t_stack **a);
void				sort_five(t_stack **a, t_stack **b);
void				sort_six_to_fifteen(t_stack **a, t_stack **b, int size);
void				sort_hundred(t_stack **a, t_stack **b);
void				quick_sort_a(t_stack **a, t_stack **b, int size);
void				quick_sort_b(t_stack **b, t_stack **a, int size);
void				radix_sort(t_stack **a, t_stack **b, int size);

/* Rotation Operations */
void				rotate_both(t_stack **a, t_stack **b, int *count_a,
						int *count_b);
void				rev_rotate_both(t_stack **a, t_stack **b, int *count_a,
						int *count_b);
void				smart_rotate(t_stack **stack, int target_pos,
						void (*rot)(t_stack **),
						void (*rev_rot)(t_stack **));

/* Index Compression */
void				compress_indices(t_stack **a);
void				rotate_min_to_top(t_stack **a);
int					get_pos_of_min(t_stack *stack);

/* Utility Functions */
void				error_exit(t_stack **a, t_stack **b);
int					get_min_value(t_stack *stack);
int					get_max_value(t_stack *stack);
int					get_position(t_stack *stack, int val);
int					get_position_index(t_stack *stack, int index);
int					get_max_index(t_stack *stack);

/* Array Sorting Utilities */
int					get_median(t_stack *stack, int size);
int					get_max_bits(int size);

#endif
