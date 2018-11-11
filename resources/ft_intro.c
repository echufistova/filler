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

int *get_piece(char *line)
{
    int *res;
    int i;

    res = (int*)malloc(sizeof(int) * ft_strlen(line));
    i = 0;
    while (line[i] != '\0')
    {
        if (line[i] == '*')
            res[i] = 1;
        else
            res[i] = 0;
        i++;
        ft_printf(" %d", res[i - 1]);
    }
    ft_printf("\n");
    return (res);
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
    else if (line[i] == 'i')
        dop = ft_strsub(line, 7 + i, ft_strlen(line) - 7 - i);
    coord.x = ft_atoi(dop);
    ft_strdel(&dop);
    printf("high: %d width: %d\n", coord.y, coord.x);
    return (coord);
}

void get_coord(t_game game)
{
    int i;
    int j;

    i = 0;
    while (i < game.field_size.y)
    {
        j = 0;
        while (j < game.field_size.x)
        {
            if (game.field_size[i + game.piece_size.y][j] == -2)
            {
                
            }
            j++;
        }
        i++;
    }
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

void algorithm(int **field, t_game game)
{
    t_point coord;
    int **dop_field;
    int i;

    i = 0;
    
    ft_printf("here2 algo\n");
    dop_field = create_arr(game.field_size.y, game.field_size.x); 
    while (!check_int_arr_equal(field, dop_field, game.field_size.y, game.field_size.x))
    {
        if (i == 1)
            del_arr(dop_field, game.field_size.y, game.field_size.x);
        i = 1;
        dop_field = create_same_arr(field, game.field_size.y, game.field_size.x);
        ft_printf("here3\n");
        coord.y = -1;
        while (++coord.y < game.field_size.y)
        {
            coord.x = -1;
            while (++coord.x < game.field_size.x)
            {
                if (field[coord.y][coord.x] != -2 && field[coord.y][coord.x] != 0)
                    field[coord.y][coord.x] = search_min(field, coord.y, coord.x, game);
               ft_printf("%d  ", field[coord.y][coord.x]);
            }
           ft_printf("\n");
        }
    }
//    get_coord(game);
}

int *get_filler_field(char *line, t_game game)
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
           ft_printf("%d  ", field[i]);
        }
        ft_printf("     filler\n");
        return (field);
}

int main(void)
{
	int i;
    int j;
    int fd;
    char *line;
    char *dop;
    t_game game;

    i = -1;
    line = ft_strnew(0);
    //fd = open("test.txt", O_WRONLY);
    fd = open("/home/echufy/filler/resources/test.txt", O_RDONLY);
    // fd = 0;
    while (get_next_line(fd, &line) > 0 && ++i < 2)
    {
        game.player = (i == 0) ? get_player(line[10]) : game.player;
        game.enemy = (game.player == 'O') ? 'X' : 'O';
        game.field_size = (i == 1) ? f_size(line) : game.field_size;
//        i++;
    }
    i = 0;
    ft_printf("player: %c\n", game.player);
    ft_printf(" enemy: %c\n", game.enemy);
    game.field = (int**)malloc(sizeof(int*) * (game.field_size.y));
    while (get_next_line(fd, &line) > 0)
    {
        if (line[0] == '0')
        {
            dop = ft_strsub(line, 4, game.field_size.x);
            game.field[ft_atoi(line)] = get_filler_field(dop, game);//ft_strsub(line, 4, game.field_size.x);
            ft_strdel(&dop);
            //ft_printf("%d \n", game.field[ft_atoi(line)]);
        }
//        if (ft_atoi(line) == game.field_size.y - 1)
//            //get_piece_size()
//            filler(game);
        if (line[1] == 'i')
        {
            game.piece_size = f_size(line);
            game.piece = (int**)malloc(sizeof(int*) * (game.piece_size.y));
        }
        if (line[0] == '*' || line[0] == '.')
        {
            game.piece[i] = get_piece(line);
            i++;
//            ft_printf("%s\n", game.piece[i - 1]);
        }
//        if (line[0] == '*' || line[0] == '.')
//            game.piece_size = get_piece(line, game);
        ft_strdel(&line);
    }
    //filler(game);
//    game.piece = (char**)malloc(sizeof(char*) * (game.piece_size.y + 1));
    printf("ok\n");
	return (0);
}
