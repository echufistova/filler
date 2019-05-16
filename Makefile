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

LIBFT = libft/libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = ./ft_intro.c ./ft_infa.c ./ft_insertable.c

OUT = $(SRC:.c=.o)

HDR = ./filler.h

all: lib $(NAME)

lib:
	make -C libft

$(NAME): $(OUT) $(LIBFT)
	gcc -o $(NAME) $(OUT) $(LIBFT) -g

%.o: %.c $(HDR)
	gcc $(FLAGS) -o $@ -c $< -I libft -g

clean:
	make clean -C libft
	/bin/rm -f $(OUT)
	/bin/rm -f *~

fclean: clean
	make fclean -C libft
	/bin/rm -f $(NAME)

re: fclean all