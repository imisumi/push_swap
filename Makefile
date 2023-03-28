# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/19 21:21:36 by anolivei          #+#    #+#              #
#    Updated: 2023/03/28 18:56:31 by ichiro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
SRC_DIR = sources/main
SRC_BNS_DIR = sources/bonus
OBJ_DIR = .objs
OBJ_BNS_DIR = .objs_bns

CC = clang
HEAD = -I./includes
CFLAGS = -g 
CFLAGS = -g -Wall -Werror -Wextra
RM = /bin/rm -rf

SRC =	$(SRC_DIR)/main.c \
		$(SRC_DIR)/push.c \
		$(SRC_DIR)/rotate.c \
		$(SRC_DIR)/reverse_rotate.c \
		$(SRC_DIR)/index.c \
		$(SRC_DIR)/new_node.c \
		$(SRC_DIR)/small_stack.c \
		$(SRC_DIR)/big_stack.c \
		$(SRC_DIR)/swap.c \
		$(SRC_DIR)/group.c \
		$(SRC_DIR)/push_utils_1.c \
		$(SRC_DIR)/push_utils_2.c \
		$(SRC_DIR)/push_utils_3.c \
		$(SRC_DIR)/push_utils_4.c \
		$(SRC_DIR)/push_utils_5.c \
		$(SRC_DIR)/push_utils_500.c \
		$(SRC_DIR)/push_utils_501.c

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

SRC_BNS =	$(SRC_BNS_DIR)/checker.c \
			$(SRC_BNS_DIR)/checker_utils.c \
			$(SRC_BNS_DIR)/swap.c \
			$(SRC_BNS_DIR)/push.c \
			$(SRC_BNS_DIR)/rotate.c \
			$(SRC_BNS_DIR)/new_node.c \
			$(SRC_BNS_DIR)/reverse_rotate.c \
			$(SRC_BNS_DIR)/get_next_line.c \
			$(SRC_BNS_DIR)/get_next_line_utils.c 

OBJ_BNS = $(patsubst $(SRC_BNS_DIR)%.c, $(OBJ_BNS_DIR)%.o, $(SRC_BNS))

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(OBJ) $(HEAD) $(CFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(CFLAGS) $(HEAD) -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BNS)
		$(CC) $(OBJ_BNS) $(HEAD) $(CFLAGS) -o $(NAME_BONUS)

$(OBJ_BNS_DIR)/%.o: $(SRC_BNS_DIR)/%.c
		@mkdir -p $(OBJ_BNS_DIR)
		@$(CC) $(CFLAGS) $(HEAD) -c $< -o $@

tester: all
		bash lfrasson_tester.sh

vis:
		python3 -m push_swap_gui

debug_mac: $(OBJ)
		@gcc $(HEAD) $(SRC) $(CFLAGS) -o "push_swap_debug"

debug_linux:
		@gdd $(HEAD) $(SRC) $(CFLAGS) -o "push_swap_debug"

clean:
		@$(RM) $(OBJ_DIR)
		@$(RM) $(OBJ_BNS_DIR)

fclean: clean
		@$(RM) $(NAME)
		@$(RM) $(NAME_BONUS)
		@$(RM) push_swap_debug
		@$(RM) push_swap_debug.dSYM

re: fclean all

.PONY: all clean fclean re