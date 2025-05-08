NAME      = libft.a
CC        = cc
CFLAGS    = -Wall -Wextra -Werror
AR        = ar rcs
RM        = rm -f
INCLUDES  = .

SRCS      = ft_isdigit.c ft_memset.c ft_atoi.c ft_calloc.c ft_putstr_fd.c \
            ft_putendl_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
            ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c

OBJS      = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
