# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-gand <mel-gand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 22:09:04 by mel-gand          #+#    #+#              #
#    Updated: 2023/03/31 22:41:16 by mel-gand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Imlx -I./get_next_line/
RM = rm -rf
SRC = so_long.c check_file.c check_map.c load_img.c check_path.c mouvements.c free_map.c destroy_img.c init_var.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c ft_putnbr.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
%.o:%.c so_long.h get_next_line/get_next_line.h
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@$(RM) $(OBJ)
fclean: clean
	@$(RM) $(NAME)
re: fclean all

.PHONY: all clean re
