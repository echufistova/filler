/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:49:04 by ychufist          #+#    #+#             */
/*   Updated: 2018/11/20 19:58:29 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check(t_game game, t_point ij, int k)
{
	if (ij.y + game.stars_coord[k].y >= 0 &&
				ij.y + game.stars_coord[k].y < game.field_size.y &&
				ij.x + game.stars_coord[k].x >= 0 &&
				ij.x + game.stars_coord[k].x < game.field_size.x &&
	game.field[ij.y + game.stars_coord[k].y][ij.x + game.stars_coord[k].x] != 0)
		return (1);
	return (0);
}

int		insertable(t_game game, t_point ij)
{
	int counter;
	int sum;
	int k;

	counter = 0;
	sum = 0;
	k = 0;
	while (k < game.stars_counter)
	{
		if (counter < 2 && check(game, ij, k))
		{
			sum += game.field[ij.y + game.stars_coord[k].y][ij.x +
				game.stars_coord[k].x];
			if (game.field[ij.y + game.stars_coord[k].y][ij.x +
				game.stars_coord[k].x] == -2)
				counter++;
			k++;
		}
		else
			return (0);
	}
	if (counter == 1)
		return (sum);
	else
		return (0);
}

void	get_piece(t_game *game)
{
	t_point		ij;
	int			k;

	ij.y = -1;
	k = 0;
	game->stars_coord = (t_point*)malloc(sizeof(t_point) * game->stars_counter);
	while (++ij.y < game->piece_size.y)
	{
		ij.x = -1;
		while (++ij.x < game->piece_size.x)
		{
			if (game->piece[ij.y][ij.x] == '*' && k == 0)
			{
				game->begin_coord.y = ij.y;
				game->begin_coord.x = ij.x;
				game->stars_coord[k].y = 0;
				game->stars_coord[k++].x = 0;
			}
			else if (game->piece[ij.y][ij.x] == '*' && k > 0)
			{
				game->stars_coord[k].y = ij.y - game->begin_coord.y;
				game->stars_coord[k++].x = ij.x - game->begin_coord.x;
			}
		}
	}
}

void	get_coord(t_game game)
{
	t_point		ij;
	t_point		res;
	t_point		min_curdist;

	ij.y = -1;
	min_curdist.x = 100000;
	res.x = 0;
	res.y = 0;
	while (++ij.y < game.field_size.y)
	{
		ij.x = -1;
		while (++ij.x < game.field_size.x)
			if (insertable(game, ij))
			{
				min_curdist.y = insertable(game, ij);
				if (min_curdist.x > min_curdist.y)
				{
					min_curdist.x = min_curdist.y;
					res.y = ij.y;
					res.x = ij.x;
				}
			}
	}
	ft_printf("%d %d\n", res.y - game.begin_coord.y,
			res.x - game.begin_coord.x);
}
