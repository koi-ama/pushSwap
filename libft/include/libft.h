/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamakasu <kamakasu@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:02:32 by koiama            #+#    #+#             */
/*   Updated: 2025/05/10 04:11:14 by kamakasu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_fd
{
	int				read_byte;
	char			buff[BUFFER_SIZE];
	char			*buff_ptr;
}					t_fd;

typedef struct s_line
{
	char			*str;
	size_t			len;
	size_t			capacity;
}					t_line;

// Memory functions
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const char *src, size_t n);

// String functions
int					ft_isdigit(int c);
int					ft_atoi(const char *str);
char				**ft_split(char const *s, char c);
void				ft_free_split(char **split);
int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);

// Memory allocation
void				*ft_calloc(size_t nmemb, size_t size);

// File operations
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*get_next_line(int fd);

// List operations
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));

#endif
