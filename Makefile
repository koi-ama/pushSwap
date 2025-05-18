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

COMMON_SRC = $(SRC_DIR)/common.c \
            $(SRC_DIR)/input_validation.c \
			$(SRC_DIR)/input_parse.c \
            $(SRC_DIR)/operations/sa.c \
            $(SRC_DIR)/operations/sb.c \
            $(SRC_DIR)/operations/ss.c \
            $(SRC_DIR)/operations/pa.c \
            $(SRC_DIR)/operations/pb.c \
            $(SRC_DIR)/operations/rr.c \
            $(SRC_DIR)/operations/rrr.c \
            $(SRC_DIR)/index_compression.c \
            $(SRC_DIR)/stack_utils.c \
            $(SRC_DIR)/stack_check.c \
            $(SRC_DIR)/stack_size.c

PUSH_SWAP_SRC = $(SRC_DIR)/push_swap.c \
               $(SRC_DIR)/sort_three.c \
               $(SRC_DIR)/sort_five.c \
			   $(SRC_DIR)/sort_hundred.c \
               $(SRC_DIR)/sort_quick_a.c \
               $(SRC_DIR)/sort_quick_b.c \
               $(SRC_DIR)/sort_array.c \
               $(SRC_DIR)/sort_radix.c \
               $(SRC_DIR)/sort_rotate.c

CHECKER_SRC = $(SRC_DIR)/checker.c

COMMON_OBJ = $(COMMON_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
PUSH_SWAP_OBJ = $(PUSH_SWAP_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
CHECKER_OBJ = $(CHECKER_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(COMMON_OBJ) $(PUSH_SWAP_OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(COMMON_OBJ) $(PUSH_SWAP_OBJ) $(LIBFT) -o $(NAME)

checker: $(LIBFT) $(OBJ_DIR) $(COMMON_OBJ) $(CHECKER_OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(COMMON_OBJ) $(CHECKER_OBJ) $(LIBFT) -o checker

bonus: checker

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