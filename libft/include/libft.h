#ifndef LIBFT_H
#define LIBFT_H

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;

int     ft_isdigit(int c);
void    *ft_memset(void *b, int c, size_t len);

int     ft_atoi(const char *str);
void    *ft_calloc(size_t nmemb, size_t size);

void    ft_putstr_fd(char *s, int fd);
void    ft_putendl_fd(char *s, int fd);

t_list  *ft_lstnew(void *content);
void    ft_lstadd_front(t_list **lst, t_list *new);
int     ft_lstsize(t_list *lst);
void    ft_lstadd_back(t_list **lst, t_list *new);
void    ft_lstdelone(t_list *lst, void (*del)(void *));
void    ft_lstclear(t_list **lst, void (*del)(void *));

#endif
