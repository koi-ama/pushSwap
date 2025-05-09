/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamakasu <kamakasu@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 22:27:21 by kamakasu          #+#    #+#             */
/*   Updated: 2024/09/09 21:42:38 by kamakasu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getc(int fd)
{
	static t_fd	fd_list[FOPEN_MAX];

	if (fd_list[fd].read_byte == 0)
	{
		fd_list[fd].read_byte = read(fd, fd_list[fd].buff, BUFFER_SIZE);
		if (fd_list[fd].read_byte < 0)
			return (fd_list[fd].read_byte++, -42);
		fd_list[fd].buff_ptr = fd_list[fd].buff;
	}
	fd_list[fd].read_byte--;
	if (fd_list[fd].read_byte < 0)
		return (fd_list[fd].read_byte++, EOF);
	return (*fd_list[fd].buff_ptr++);
}

static void	*ft_gnl_memcpy(char *dst, const char *src, size_t n)
{
	while (n--)
	{
		*dst++ = *src++;
	}
	return (dst);
}

static int	ft_putc(t_line *line, char c)
{
	char	*new_line;

	if (line->capacity <= line->len)
	{
		line->capacity = line->len * 2;
		if (line->capacity == 0)
			line->capacity = 1;
		new_line = malloc(line->capacity + 1);
		if (!new_line)
			return (-1);
		ft_gnl_memcpy(new_line, line->str, line->len);
		free(line->str);
		line->str = new_line;
	}
	line->str[line->len++] = c;
	return (0);
}

char	*get_next_line(int fd)
{
	t_line	line;
	int		c;

	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	line.str = NULL;
	line.len = 0;
	line.capacity = 0;
	while (1)
	{
		c = ft_getc(fd);
		if (c == EOF)
			break ;
		if (c == -42)
			return (free(line.str), NULL);
		if (ft_putc(&line, (char)c) == -1)
			return (free(line.str), NULL);
		if (c == '\n')
			break ;
	}
	if (!line.len)
		return (NULL);
	ft_putc(&line, '\0');
	return (line.str);
} 