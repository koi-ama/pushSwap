#include "push_swap.h"

#ifdef DEBUG
void	print_stack_debug(t_stack *stack, const char *msg)
{
	t_stack	*current;

	ft_putstr_fd((char *)msg, 2);
	ft_putstr_fd(": ", 2);
	current = stack;
	while (current)
	{
		ft_putstr_fd("[v:", 2);
		ft_putnbr_fd(current->value, 2);
		ft_putstr_fd(" i:", 2);
		ft_putnbr_fd(current->index, 2);
		ft_putstr_fd("] ", 2);
		current = current->next;
	}
	ft_putstr_fd("\n", 2);
}

void	print_stacks_debug(t_stack *a, t_stack *b, const char *msg)
{
	ft_putstr_fd((char *)msg, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("Stack A: ", 2);
	print_stack_debug(a, "");
	ft_putstr_fd("Stack B: ", 2);
	print_stack_debug(b, "");
	ft_putstr_fd("\n", 2);
}
#endif
