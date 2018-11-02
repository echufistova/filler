//
// Created by Yevheniya CHUFISTOVA on 10/25/18.
//

#ifndef FILLER_FILLER_H
#define FILLER_FILLER_H

#include "libft/libft.h"
#include "libft/ft_printf.h"
#include "libft/get_next_line.h"

typedef	struct s_player
{
	char big_letter;
	char small_letter;
}				t_player;

typedef struct s_point
{
	int x;
	int y;
}				t_point;

typedef	struct s_game
{
	char player;
	char enemy;
	char **field;
	t_point field_size;
}				t_game;

#endif //FILLER_FILLER_H
