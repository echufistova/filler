/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intro.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:58:52 by ychufist          #+#    #+#             */
/*   Updated: 2018/11/20 19:49:31 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		search_min_i(int **field, int i, int j, t_game game)
{
	int tmp;

	tmp = field[i][j];
	if (i != 0 && field[i - 1][j] >= 0)
	{
		if (tmp >= 0)
			tmp = (field[i - 1][j] > tmp) ? tmp : field[i - 1][j];
		else
			tmp = field[i - 1][j];
	}
	if (i != game.field_size.y - 1 && field[i + 1][j] >= 0)
	{
		if (tmp >= 0)
			tmp = (field[i + 1][j] > tmp) ? tmp : field[i + 1][j];
		else
			tmp = field[i + 1][j];
	}
	return (tmp);
}

int		search_min(int **field, int i, int j, t_game game)
{
	int tmp;

	tmp = search_min_i(field, i, j, game);
	if (j != 0 && field[i][j - 1] >= 0)
	{
		if (tmp >= 0)
			tmp = (field[i][j - 1] > tmp) ? tmp : field[i][j - 1];
		else
			tmp = field[i][j - 1];
	}
	if (j != game.field_size.x - 1 && field[i][j + 1] >= 0)
	{
		if (tmp >= 0)
			tmp = (field[i][j + 1] > tmp) ? tmp : field[i][j + 1];
		else
			tmp = field[i][j + 1];
	}
	return ((tmp >= 0) ? tmp + 1 : tmp);
}

void	algorithm(t_game game)
{
    t_point		c;
	int			**dop_field;
	int			i;

	dop_field = create_arr(game.field_size.y, game.field_size.x);
	while (!check_int_arr_equal(game.field, dop_field,
				game.field_size.y, game.field_size.x))
    {
		if (i == 1)
			del_arr(dop_field, game.field_size.y);
		i = 1;
		dop_field = create_same_arr(game.field, game.field_size.y,
				game.field_size.x);
		c.y = -1;
		while (++c.y < game.field_size.y)
		{
			c.x = -1;
			while (++c.x < game.field_size.x)
			{
				if (game.field[c.y][c.x] != -2 && game.field[c.y][c.x] != 0)
					game.field[c.y][c.x] =
						search_min(game.field, c.y, c.x, game);
			}
		}
	}
}

void	the_game(t_game *game, int *i, char *line, char *dop)
{
	if (line[0] == '0')
	{
		dop = ft_strsub(line, 4, game->field_size.x);
		game->field[ft_atoi(line)] = get_filler_field(dop, *game);
		ft_strdel(&dop);
	}
	else if (line[1] == 'i')
	{
		game->piece_size = f_size(line);
		game->piece = (char **) malloc(sizeof(char *) * (game->piece_size.y));
	}
	else if (line[0] == '*' || line[0] == '.')
	{
		game->piece[(*i)++] = ft_strsub(line, 0, game->piece_size.x);
		game->stars_counter += stars(line);
		if (game->piece_size.y == *i)
		{
			get_piece(game);
			algorithm(*game);
			get_coord(*game);
			clean_all(game);
			*i = 0;
		}
	}
}

int		main(void)
{
	int		i;
	char	*line;
	char	*dop;
	t_game	game;

	i = -1;
	line = ft_strnew(0);
	dop = NULL;
	game.stars_counter = 0;
	while (get_next_line(0, &line) > 0 && ++i < 1)
	{
		game.player = (i == 0) ? get_player(line[10]) : game.player;
		game.enemy = (game.player == 'O') ? 'X' : 'O';
		ft_strdel(&line);
	}
	game.field_size = (i == 1) ? f_size(line) : game.field_size;
	i = 0;
	game.field = (int**)malloc(sizeof(int*) * (game.field_size.y));
	while (get_next_line(0, &line) > 0)
	{
		the_game(&game, &i, line, dop);
		ft_strdel(&line);
	}
	return (0);
}
