/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intro.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:58:52 by ychufist          #+#    #+#             */
/*   Updated: 2018/10/25 14:14:15 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char get_player(char c) {
    if (c == '1')
        return ('O');
    else if (c == '2')
        return ('X');
    return (0);
}

int stars(char *line)
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

void get_piece(t_game *game)
{
    t_point ij;
    int k;

    ij.y = -1;
    k = 0;
    game->begin_coord.y = 0;
    game->begin_coord.x = 0;
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
                game->stars_coord[k].y = ij.y - game->begin_coord.y;
        }
    }
}

t_point f_size(char *line)
{
    char *dop;
    t_point coord;
    int i;

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

void clean_all(t_game *game)
{
    int i;

    i = 0;
    del_arr(game->field, game->field_size.y);
    while (i < game->piece_size.y)
    {
        ft_strdel(&game->piece[i]);
        i++;
    }
    i = 0;
    while (i < game->stars_counter)
    {
        game->stars_coord[i].y = 0;
        game->stars_coord[i].x = 0;
        i++;
    }
}

int insertable(t_game game, t_point ij)
{
    int counter;
    int sum;
    int k;

    counter = 0;
    sum = 0;
    k = 0;
    while (k < game.stars_counter)
    {
        if (counter < 2 && ij.y + game.stars_coord[k].y >= 0 &&
        ij.y + game.stars_coord[k].y < game.field_size.y &&
        ij.x + game.stars_coord[k].x >= 0 &&
        ij.x + game.stars_coord[k].x < game.field_size.x &&
                game.field[ij.y + game.stars_coord[k].y][ij.x + game.stars_coord[k].x] != 0)
        {
            sum += game.field[ij.y + game.stars_coord[k].y][ij.x + game.stars_coord[k].x];
            if (game.field[ij.y + game.stars_coord[k].y][ij.x + game.stars_coord[k].x] == -2)
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

void get_coord(t_game game)
{
    t_point ij;
    t_point res;
    int min;
    int cur_dist;

    ij.y = -1;
    min = 100000;
    res.x = 0;
    res.y = 0;
    while (++ij.y < game.field_size.y)
    {
        ij.x = -1;
        while (++ij.x < game.field_size.x)
        {
            if (insertable(game, ij))
            {
                cur_dist = insertable(game, ij);
                if (min > cur_dist)
                {
                    min = cur_dist;
                    res.y = ij.y;
                    res.x = ij.x;
                }
            }
        }
    }
     if (min != 0)
         ft_printf("%d %d\n", res.y - game.begin_coord.y, res.x - game.begin_coord.x);
     else
         ft_printf("%d %d\n", 0, 0);

}

int search_min(int **field, int i, int j, t_game game)
{
    int tmp;

    tmp = field[i][j];
    if (i != 0 && field[i - 1][j] >= 0)
    {
        if (tmp  >= 0)
            tmp = (field[i - 1][j] > tmp) ? tmp : field[i - 1][j];
        else
            tmp = field[i - 1][j];
    }
    if (i != game.field_size.y - 1 && field[i + 1][j] >= 0)    
    {
        if (tmp  >= 0)
            tmp = (field[i + 1][j] > tmp) ? tmp : field[i + 1][j];
        else
            tmp = field[i + 1][j];
    }
    if (j != 0 && field[i][j - 1] >= 0)
    {
        if (tmp  >= 0)
            tmp = (field[i][j - 1] > tmp) ? tmp : field[i][j - 1];
        else
            tmp = field[i][j - 1];
    }
    if (j != game.field_size.x - 1 && field[i][j + 1] >= 0)
    {
        if (tmp  >= 0)
            tmp = (field[i][j + 1] > tmp) ? tmp : field[i][j + 1];
        else
            tmp = field[i][j + 1];
    }
    if (tmp >= 0)
        return (tmp + 1);
    return (tmp);
}

void algorithm(t_game game)
{
    t_point coord;
    int **dop_field;
    int i;

    i = 0;
    
//    ft_printf("here2 algo\n");
    dop_field = create_arr(game.field_size.y, game.field_size.x); 
    while (!check_int_arr_equal(game.field, dop_field, game.field_size.y, game.field_size.x))
    {
        if (i == 1)
            del_arr(dop_field, game.field_size.y);
        i = 1;
        dop_field = create_same_arr(game.field, game.field_size.y, game.field_size.x);
        coord.y = -1;
        while (++coord.y < game.field_size.y)
        {
            coord.x = -1;
            while (++coord.x < game.field_size.x)
            {
                if (game.field[coord.y][coord.x] != -2 && game.field[coord.y][coord.x] != 0)
                    game.field[coord.y][coord.x] = search_min(game.field, coord.y, coord.x, game);
            }
        }

    }
    get_coord(game);
}

int *get_filler_field(char *line, t_game game)
{
    int *field;
    int i;

    i = -1;
    field = (int*)malloc(sizeof(int) * game.field_size.x);
        while (line[++i] != '\0')
        {
            if (line[i] == game.player || line[i] == 'o')
                field[i] = -2;
            else if (line[i] == game.enemy || line[i] == 'x')
                field[i] = 0;
            else
                field[i] = -1;
        }
        return (field);
}

int main(void)
{
	int i;
    char *line;
    char *dop;
    t_game game;

    i = -1;
    line = ft_strnew(0);
    game.stars_counter = 0;
    while (get_next_line(0, &line) > 0 && ++i < 1)
    {
        game.player = (i == 0) ? get_player(line[10]) : game.player;
        game.enemy = (game.player == 'O') ? 'X' : 'O';
    }
    game.field_size = (i == 1) ? f_size(line) : game.field_size;
    i = 0;
    game.field = (int**)malloc(sizeof(int*) * (game.field_size.y));
    while (get_next_line(0, &line) > 0)
    {
        if (line[0] == '0')
        {
            dop = ft_strsub(line, 4, game.field_size.x);
            game.field[ft_atoi(line)] = get_filler_field(dop, game);
            ft_strdel(&dop);
        }
        else if (line[1] == 'i')
        {
            game.piece_size = f_size(line);
            game.piece = (char **) malloc(sizeof(char *) * (game.piece_size.y));
        }
        else if (line[0] == '*' || line[0] == '.') {
            game.piece[i] = ft_strsub(line, 0, game.piece_size.x);
            game.stars_counter += stars(line);
            i++;
            if (game.piece_size.y == i)
            {
                get_piece(&game);
                algorithm(game);
                clean_all(&game);
                i = 0;
                game.field = (int**)malloc(sizeof(int*) * (game.field_size.y));
                game.stars_counter = 0;
                game.piece_size.y = 0;
                game.piece_size.x = 0;

            }
        }
        ft_strdel(&line);
    }
	return (0);
}
