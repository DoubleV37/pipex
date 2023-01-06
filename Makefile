# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vviovi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 13:42:59 by vviovi            #+#    #+#              #
#    Updated: 2023/01/06 13:48:09 by vviovi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -O3 -ggdb3

CC = clang

NAME = pipex

INCLUDES = -I . -I libft

LIBFTFLAGS = -L libft -lft

SRC = 	main.c \

OBJ = ${SRC:.c=.o}

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
	@rm -f $(OBJ)

fclean : clean
	@$(MAKE) -C libft fclean
	rm -f $(NAME)

re : fclean all

all : $(NAME)

.PHONY: clean fclean re all
