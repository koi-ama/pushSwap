/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamakasu <kamakasu@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:30:08 by koiama            #+#    #+#             */
/*   Updated: 2025/05/10 04:12:25 by kamakasu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <errno.h>
#include <stdlib.h>

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_number(char *str)
{
	long long	num;

	errno = 0;
	num = ft_atoi(str);
	if (errno == ERANGE || num < INT_MIN || num > INT_MAX)
		return (0);
	if (num == 0 && str[0] != '0')
		return (0);
	return (1);
}

static int	validate_numbers(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!is_valid_number(args[i]) || !check_number(args[i]))
			return (0);
		i++;
	}
	return (1);
}

int	validate_input(int argc, char **argv)
{
	char	**args;
	int		result;

	if (argc == 1)
		return (0);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	result = validate_numbers(args);
	if (argc == 2)
		ft_free_split(args);
	return (result);
}
