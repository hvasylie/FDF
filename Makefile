# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/22 15:46:21 by hvasylie          #+#    #+#              #
#    Updated: 2019/08/24 23:30:15 by hvasylie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = *.c
HEADER = fdf.h
LIBFT = libft/libft.a
MINILIBX = minilibx_macos/liblmx.a
O =$(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(LIBFT) $(MINILIBX) $(O)
		Make -C libft
		Make -C minilibx_macos
		gcc $(CFLAGS) $(SRC) -o $(NAME) -I $(HEADER) -L. $(LIBFT) -L ./minilibx_macos -lmlx -framework OpenGL -framework AppKit

		@echo "Compiled!"

$(O): $(LIBFT)
		gcc $(FLAGS) -c $(SRC)
$(LIBFT):
		make libft
$(MINILIBX):
		make minilibx_macos


clean :
		-rm -f $(O)
		@echo "Cleaned!"

fclean : clean
		make fclean -C libft
		-rm -f $(NAME)
		@echo "Everything is cleaned"

re: fclean all