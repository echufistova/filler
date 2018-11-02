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

char get_player(char c)
{
    if (c == '1')
        return ('O');
    else if (c == '2')
        return ('X');
    return (0);
}  

t_point f_size(char *line)
{
    char *dop;
    t_point coord;
    int i;

    dop = ft_strsub(line, 8, ft_strlen(line) - 8);
    i = ft_atoi(dop);
    coord.y = i;
    ft_strdel(&dop);
    i = ft_intlength(i);
    dop = ft_strsub(line, 9 + i, ft_strlen(line) - 9 - i);
    coord.x = ft_atoi(dop);
    ft_strdel(&dop);
    printf("high: %d width: %d\n", coord.y, coord.x);
    return (coord);
}

void algorithm(int **field, int **dop_field, t_game game)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while (i < game.field_size.y)
    {
        j = 0;
        while (j < game.field_size.x)
        {
            // tmp = field[i][j];
            if (field[i][j + 1] >= 0)
                tmp = field[i][j + 1];

          //  ft_printf("%d  ", dop_field[i][j]);
            j++;
        }
        //ft_printf("\n");
        i++;
    }
}

void filler(t_game game)
{
    int field[game.field_size.y][game.field_size.x];
    int dop_field[game.field_size.y][game.field_size.x];
    t_point coord;

    coord.y = -1;
    ft_printf("here\n");
    while (++coord.y < game.field_size.y)
    {
        coord.x = -1;
        while (++coord.x < game.field_size.x)
        {
            if (game.field[coord.y][coord.x] == game.player)
            {
                field[coord.y][coord.x] = -2;
                dop_field[coord.y][coord.x] = -2;
            }
            else if (game.field[coord.y][coord.x] == game.enemy)
            {
                field[coord.y][coord.x] = 0;
                dop_field[coord.y][coord.x] = 0;
            }
            else 
            {
                field[coord.y][coord.x] = -1;
                dop_field[coord.y][coord.x] = -1;
            }
           ft_printf("%d  ", dop_field[coord.y][coord.x]);
        }
        ft_printf("\n");
    }
    //algorithm(field, dop_field, game);
}

int main(int ac, char **av)
{
	int i;
    int j;
    int fd;
    char *line;
    t_game game;


    i = 0;
    line = ft_strnew(0);
    //fd = open("test.txt", O_WRONLY);
    fd = open("test.txt", O_RDONLY);
    // fd = 0;
    while (get_next_line(fd, &line) > 0 && i < 2)
    {
        game.player = (i == 0) ? get_player(line[10]) : game.player;
        game.enemy = (game.player == 'O') ? 'X' : 'O';
        game.field_size = (i == 1) ? f_size(line) : game.field_size;
        i++;
    }
    ft_printf("player: %c\n", game.player);
    ft_printf(" enemy: %c\n", game.enemy);
    game->field = (char**)malloc(sizeof(char*) * game->field_size.y);
    while (get_next_line(fd, &line) > 0)
    {
        if (line[0] == '0')
        {
            //ft_printf("here\n");
            game.field[ft_atoi(line)] = ft_strsub(line, 4, game.field_size.x);
            ft_printf("%s\n", game.field[ft_atoi(line)]);
        }
        // ft_printf("ft_atoi(line) %d\n", ft_atoi(line));
        if (ft_atoi(line) == game.field_size.y - 1)
            filler(game);
        //get_field(line, &game);
        //dprintf(fd, "%s\n", line);
        //ft_printf("8 2\n");
        // if (ft_strstr(line, "[./players/ychufist.filler]") && i <= 8)
        //     my_player = get_player(i);
        // else if (i == 9)
        //     field_size = f_size(line, i);
        // else if (i == 11 + field_size.y)
        //     figure_size = f_size(line, i);
        // ft_strdel(&line);
        //i++;
    }
    //ft_printf("%d\n", ft_atoi("017.............."));
    // i = 0;
    // while (i < game.field_size.y)
    // {
    //     ft_printf("%s\n", game.field[i]);
    //     i++;
    // }
	return (0);
}
