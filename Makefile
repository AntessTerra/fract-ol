# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 12:29:28 by jbartosi          #+#    #+#              #
#    Updated: 2023/02/08 16:43:41 by jbartosi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CFLAGS = -Wall -Wextra -Werror
PRINTF = ft_printf
LIBFT = ft_printf/libft
MLX = minilibx

SRC = main.c colors.c
OBJ = $(SRC:.c=.o)

all: lib $(NAME)

lib:
	@make -C $(PRINTF)
	@make -C $(MLX)
	@echo "Finished making libraries :D"

$(NAME): $(OBJ)
	cc $(CFLAGS) -L $(LIBFT) -L $(PRINTF) -L $(MLX) -o $@ $^ -lft -lftprintf -lmlx -lXext -lX11 -lm

clean:
	@make clean -C $(PRINTF)
	@rm -f $(OBJ)

fclean:
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@make fclean -C $(PRINTF)

re:	fclean
	@make all

.PHONY: re, fclean, clean

