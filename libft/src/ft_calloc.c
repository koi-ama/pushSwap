/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamakasu <kamakasu@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:04:14 by koiama            #+#    #+#             */
/*   Updated: 2025/05/10 04:09:19 by kamakasu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*memory;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	total_size = nmemb * size;
	if (total_size / nmemb != size)
		return (NULL);
	memory = malloc(total_size);
	if (memory == NULL)
		return (NULL);
	else
		ft_memset(memory, 0, total_size);
	return (memory);
}
