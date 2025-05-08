# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <user@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 00:00:00 by user             #+#    #+#              #
#    Updated: 2024/05/08 00:00:00 by user            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./include -I./libft/include

SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft

SRC = $(wildcard $(SRC_DIR)/*.c) \
      $(wildcard $(SRC_DIR)/operations/*.c)

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

BONUS_SRC = $(SRC_DIR)/checker.c \
            $(wildcard $(SRC_DIR)/operations/*.c)

BONUS_OBJ = $(BONUS_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) -o $(NAME)

bonus: $(LIBFT) $(OBJ_DIR) $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(BONUS_OBJ) $(LIBFT) -o $(BONUS)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/operations

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all bonus clean fclean re 