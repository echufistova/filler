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

int search_min(int **field, int i, int j, t_game game)
{
    int tmp;
    int up;
    int down;
    int left;
    int right;

    tmp = field[i][j];
    up = 30;
    down = 30;
    left = 30;
    right = 30;
   // min = 0;
    // min = field[i][j] > ;
    if (i != 0 && field[i - 1][j] >= 0)
    {
        up = field[i - 1][j];
        if (field[i][j] > 0)
            up = (up > field[i][j]) ? field[i][j] : up;
        //if (tmp >= 0)
        // ft_printf("here1\n");
        // tmp = (field[i - 1][j] >= 0) ? field[i - 1][j] : tmp;
        // min = (tmp > min && tmp >= 0) ? min : tmp;

    }
    if (i != game.field_size.y - 1 && field[i + 1][j] >= 0)    
    {
        down = field[i + 1][j];
        if (field[i][j] > 0)
            down = (down > field[i][j]) ? field[i][j] : down;
        // if (tmp >= 0)
        //     min = (field[i + 1][j] >= tmp) ? tmp : field[i + 1][j];
        // ft_printf("here2\n");
        // tmp = (field[i + 1][j] >= 0) ? field[i + 1][j] : tmp;
        // min = (tmp > min && tmp >= 0) ? min : tmp;
    }
    if (j != 0 && field[i][j - 1] >= 0)
    {
        left = field[i][j - 1];
        if (field[i][j] > 0)
            left = (left > field[i][j]) ? field[i][j] : left;
        // ft_printf("here3\n");
        // tmp = (field[i][j - 1] >= 0) ? field[i][j - 1] : tmp;
        // min = (tmp > min && tmp >= 0) ? min : tmp;
    }
    if (j != game.field_size.x - 1 && field[i][j + 1] >= 0)
    {
        right = field[i][j + 1];
        if (field[i][j] > 0)
            right = (right > field[i][j]) ? field[i][j] : right;
        // ft_printf("here4\n");
        // tmp = (field[i][j + 1] >= 0) ? field[i][j + 1] : tmp;
        // min = (tmp > min && tmp >= 0) ? min : tmp;
    }
    // ft_printf("%d\n %d\n %d\n %d\n",
    //     (i - 1 ) < 0 ? -9 :field[i - 1][j],
    //     (i + 1 ) > game.field_size.y ? -9 : field[i + 1][j],
    //     (j - 1) < 0 ? -9 : field[i][j - 1],
    //     (j + 1) > game.field_size.x ? -9 :field[i][j + 1]);
    up = (up > down) ? down : up;
    left = (left > right) ? right : left;
    tmp = ((up > down) ? down : up) > ((left > right) ? right : left) ? (left > right) ? right : left : (up > down) ? down : up;
    if (tmp > 0)
    {  
        ft_printf("min res bla: %d\n\n\n\n", tmp);       
        return (tmp + 1);
    }
        ft_printf("min res: %d\n\n\n\n", tmp);       
    return (tmp);
}

void algorithm(int **field, t_game game)
{
    t_point coord;
    int **dop2_field;
    int **dop_field;//[game.field_size.y][game.field_size.x];
    int tmp;
    int i;

    i = 0;
    
    ft_printf("here2 algo\n");
    dop_field = create_arr(game.field_size.y, game.field_size.x); 
    while (!check_int_arr_equal(field, dop_field, game.field_size.y, game.field_size.x))
    {
        //ft_printf("check_int_arr_equal : %d\n",
        // check_int_arr_equal(field, dop_field, game.field_size.y, game.field_size.x));
        if (i == 1)
            del_arr(dop_field, game.field_size.y, game.field_size.x);
        i = 1;
        // ft_printf("here2\n");
        dop_field = create_same_arr(field, game.field_size.y, game.field_size.x);
        ft_printf("here3\n");
        coord.y = -1;
        while (++coord.y < game.field_size.y)
        {
           // ft_printf("here4\n");
            coord.x = -1;
            while (++coord.x < game.field_size.x)
            {
               //ft_printf("here5");
            // tmp = field[i][j];
            //if (field[i][j + 1] >= 0 )
                if (field[coord.y][coord.x] != -2 && field[coord.y][coord.x] != 0)
                    field[coord.y][coord.x] = search_min(field, coord.y, coord.x, game);
               ft_printf("%d  ", field[coord.y][coord.x]);
            }
           ft_printf("\n");
        }
        // del_arr(dop_field, game.field_size.y, game.field_size.x);
        // dop_field = create_same_arr(dop2_field, game.field_size.y, game.field_size.x);
    }
}

void filler(t_game game)
{
    int **field;//[game.field_size.y][game.field_size.x];
    //int dop_field[game.field_size.y][game.field_size.x];
    t_point coord;

  //  ft_printf("here\n");
    coord.y = -1;
    field = create_arr(game.field_size.y, game.field_size.x);
    //ft_printf("here\n");
    while (++coord.y < game.field_size.y)
    {
       // ft_printf("here1\n");
        coord.x = -1;
        while (++coord.x < game.field_size.x)
        {
            // ft_printf("here1\n");
            if (game.field[coord.y][coord.x] == game.player)
            {
                field[coord.y][coord.x] = -2;
                // dop_field[coord.y][coord.x] = -2;
            }
            else if (game.field[coord.y][coord.x] == game.enemy)
            {
                field[coord.y][coord.x] = 0;
                // dop_field[coord.y][coord.x] = 0;
            }
            else 
            {
                field[coord.y][coord.x] = -1;
                // dop_field[coord.y][coord.x] = -1;
            }
           ft_printf("%d  ", field[coord.y][coord.x]);
        }
        ft_printf("     filler\n");
    }
    ft_printf("\n");
    algorithm(field, game);
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
    game.field = (char**)malloc(sizeof(char*) * game.field_size.y);
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
    printf("ok\n");
	return (0);
}
