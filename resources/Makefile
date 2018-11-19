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

NAME =  fill

SRC = ft_int_arr.c ft_intro.c

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC)
	make -C libft
	gcc -o $(NAME) $(FLAGS) -L libft -lft $(SRC)

clean:
	make clean -C libft

fclean:
	make fclean -C libft
	/bin/rm -f $(NAME)

re:
	fclean all

# NAME = psaprono.filler

# SRC = ft_intro.c ft_int_arr.c

# OBJ = $(SRC:.c=.o)

# LIBFT_DIR = libft/

# LIBFT = $(LIBFT_DIR)libftprintf

# LIBFT_FLAGS = -lft -L $(LIBFT_DIR)

# CC_FLAGS = -Wall -Werror -Wextra

# LINK_FLAGS = $(LIBFT_FLAGS)

# HEADER_FLAGS = -I. -I $(LIBFT_DIR)


# all: $(NAME)

# $(NAME):$(LIBFT) $(OBJ) filler.h
# 	gcc $(OBJ) $(LINK_FLAGS) -o $(NAME)

# %.o: %.c
# 	gcc -O3 -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

# $(LIBFT):
# 	make -C $(LIBFT_DIR)

# clean:
# 	rm -f $(OBJ)
# 	make clean -C $(LIBFT_DIR)

# fclean: clean
# 	rm -f $(NAME)
# 	make fclean -C $(LIBFT_DIR)

# re: fclean all
