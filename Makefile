# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ychufist <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/19 16:49:26 by ychufist          #+#    #+#              #
#    Updated: 2018/11/19 16:52:17 by ychufist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ychufist.filler

LIBFT = ./resources/libft/libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = ./resources/ft_intro.c ./resources/ft_int_arr.c

OUT = $(SRC:.c=.o)

HDR = ./resources/filler.h

all: lib $(NAME)

lib:
	make -C resources/libft

$(NAME): $(OUT) $(LIBFT)
	gcc -o $(NAME) $(OUT) $(LIBFT)

%.o: %.c $(HDR)
	gcc $(FLAGS) -o $@ -c $< -I ./resources/libft

clean:
	make clean -C ./resources/libft
	/bin/rm -f $(OUT)
	/bin/rm -f *~

fclean: clean
	make fclean -C ./resources/libft
	/bin/rm -f $(NAME)

re: fclean all