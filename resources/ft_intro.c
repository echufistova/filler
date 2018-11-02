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

void create_field(t_game *game)
{
    int i;
    int j;

    i = 0;
    game->field = (char**)malloc(sizeof(char*) * game->field_size.y);
    // while (i < game->field_size.y)
    // {
    //     game->field[i] = (char*)malloc(sizeof(char) * game->field_size.x);
    //     i++;
    // }
}

int main(int ac, char **av)
{
	int i;
    int j;
    int fd;
    char *line;
    char *help;
    t_point field_size;
    t_point figure_size;
    t_game game;


    i = 0;
    line = ft_strnew(0);
    //fd = open("test.txt", O_WRONLY);
    fd = open("test.txt", O_RDONLY);
    // fd = 0;
    while (get_next_line(fd, &line) > 0 && i < 2)
    {
        game.player = (i == 0) ? get_player(line[10]) : game.player;
        game.field_size = (i == 1) ? f_size(line) : game.field_size;
        i++;
    }
    ft_printf("player: %c\n", game.player);
    create_field(&game);//game.field = (char**)malloc(sizeof(char*) * game.field_size.y);
    ft_printf("player: %c\n", game.player);
    while (get_next_line(fd, &line) > 0)
    {
        if (line[0] == '0')
        {
            //ft_printf("here\n");
            game.field[line[2] - 48] = ft_strsub(line, 4, game.field_size.x);
            ft_printf("%s\n", game.field[line[2] - 48]);
        }
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
    // i = 0;
    // while (i < game.field_size.y)
    // {
    //     ft_printf("%s\n", game.field[i]);
    //     i++;
    // }
	return (0);
}
