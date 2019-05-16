/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:45:46 by ychufist          #+#    #+#             */
/*   Updated: 2018/11/20 19:57:29 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	get_player(char c)
{
	if (c == '1')
		return ('O');
	else if (c == '2')
		return ('X');
	return (0);
}

int		stars(char *line)
{
	int res;
	int i;

	res = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '*')
			res++;
		i++;
	}
	return (res);
}

void	clean_all(t_game *game)
{
	int i;

	i = 0;
	del_arr(game->field, game->field_size.y, game->field_size.x);
	while (i < game->piece_size.y)
	{
		ft_strdel(&game->piece[i]);
		i++;
	}
	free(game->piece);
	i = 0;
	while (i < game->stars_counter)
	{
		game->stars_coord[i].y = 0;
		game->stars_coord[i].x = 0;
		i++;
	}
	free(game->stars_coord);
	game->field = (int**)malloc(sizeof(int*) * (game->field_size.y));
	game->stars_counter = 0;
	game->piece_size.y = 0;
	game->piece_size.x = 0;
}

t_point	f_size(char *line)
{
	char		*dop;
	t_point		coord;
	int			i;

	if (line[1] == 'l')
		dop = ft_strsub(line, 8, ft_strlen(line) - 8);
	else if (line[1] == 'i')
		dop = ft_strsub(line, 6, ft_strlen(line) - 6);
	i = ft_atoi(dop);
	coord.y = i;
	ft_strdel(&dop);
	i = ft_intlength(i);
	if (line[1] == 'l')
		dop = ft_strsub(line, 9 + i, ft_strlen(line) - 9 - i);
	else if (line[1] == 'i')
		dop = ft_strsub(line, 7 + i, ft_strlen(line) - 7 - i);
	coord.x = ft_atoi(dop);
	ft_strdel(&dop);
	return (coord);
}

int		*get_filler_field(char *line, t_game game)
{
	int *field;
	int i;

	i = -1;
	field = (int*)malloc(sizeof(int) * game.field_size.x);
	while (line[++i] != '\0')
	{
		if (line[i] == game.player)
			field[i] = -2;
		else if (line[i] == game.enemy)
			field[i] = 0;
		else
			field[i] = -1;
	}
	return (field);
}
