# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vviovi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 13:42:59 by vviovi            #+#    #+#              #
#    Updated: 2023/01/23 15:09:43 by vviovi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -O3 -ggdb3

CC = clang

NAME = pipex

INCLUDES = -I . -I libft

LIBFTFLAGS = -L libft -lft

SRC = 	mandatory/main.c \
		mandatory/utils.c \
		mandatory/init_arg.c \
		mandatory/pipex_utils.c

SRC_BONUS = 	bonus/main_bonus.c \
				bonus/utils_bonus.c \
				bonus/init_arg_bonus.c \
				bonus/pipex_utils_bonus.c

ifdef BONUS
		SRC = $(SRC_BONUS)
endif

OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:.c=.o}

%.o : %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	@$(MAKE) -C libft
	@echo "╔═════════════════╗"
	@echo "║ Compiling pipex ║"
	@echo "╚═════════════════╝"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFTFLAGS) -o $(NAME)

clean :
	@$(MAKE) -C libft clean
	@echo "╔════════════════╗"
	@echo "║ Cleaning pipex ║"
	@echo "╚════════════════╝"
	@rm -f $(OBJ) $(OBJ_BONUS)

fclean : clean
	@$(MAKE) -C libft fclean
	rm -f $(NAME)

re : fclean all

all : $(NAME)

bonus :
	@echo "╔════════════════╗"
	@echo "║  BONUS  pipex  ║"
	@echo "╚════════════════╝"
	@make BONUS=1

.PHONY: clean fclean re all bonus
