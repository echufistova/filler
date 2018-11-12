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
	int stars_counter;
	char player;
	char enemy;
	int **field;
	char **piece;
	t_point piece_size;
	t_point field_size;
	t_point *stars_coord;
}				t_game;

int check_int_arr_equal(int **tab, int **tab2, int hign, int length);
int **create_same_arr(int **tab, int hign, int length);
int **create_arr(int high, int length);
void del_arr(int **tab, int high, int length);

#endif //FILLER_FILLER_H
