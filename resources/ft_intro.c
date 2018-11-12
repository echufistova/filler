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

    //res = (int*)malloc(sizeof(int) * ft_strlen(line));
    res = 0;
    i = 0;
    while (line[i] != '\0')
    {
        if (line[i] == '*')
            res++;
        i++;
        //ft_printf(" %d", res[i - 1]);
    }
    // ft_printf("k-st zirok: %d\n", res);
    return (res);
}

void get_piece(t_game *game)
{
    t_point ij;
    t_point begin;
    int k;

    ij.y = -1;
    k = 0;
    game->stars_coord = (t_point*)malloc(sizeof(t_point) * game->stars_counter);
 //   ft_printf(" edwqe game.stars_counter %d\n", game->stars_counter);
//    ft_printf("hello\n");
    while (++ij.y < game->piece_size.y)
    {
        ij.x = -1;
        while (++ij.x < game->piece_size.x)
        {
            if (game->piece[ij.y][ij.x] == '*' && k == 0)
            {
                begin.y = ij.y;
                begin.x = ij.x;
                game->stars_coord[k].y = 0;
                game->stars_coord[k++].x = 0;
//                ft_printf("stars[%d].y: %d, stars[%d].x: %d\n", k - 1,
    //                game->stars_coord[k - 1].y, k - 1, game->stars_coord[k - 1].x);   
            }
            else if (game->piece[ij.y][ij.x] == '*' && k > 0)
            {
                game->stars_coord[k].y = ij.y - begin.y;
                game->stars_coord[k++].x = ij.x - begin.x;
 //           ft_printf("stars[%d].y: %d, stars[%d].x: %d\n", k - 1,
         //           game->stars_coord[k - 1].y, k - 1, game->stars_coord[k - 1].x);
            }
        }
    }
//    ft_printf("game.stars_counter %d\n", game->stars_counter);
    //return (game.piece_starsstars);
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
   // printf("high: %d width: %d\n", coord.y, coord.x);
    return (coord);
}

int distance(t_game game, t_point ij)
{
    int res;

    res = 0;

    return (res);
}

int insertable(t_game game, t_point ij)
{
    int counter;
    int sum;
    int k;

    counter = 0;
    sum = 0;
    k = 0;
    // ft_printf("game.stars_counter %d\n", game.stars_counter);
    while (k < game.stars_counter)
    {   
        // if (k == 4)
        
        if (counter < 2 && ij.y + game.stars_coord[k].y >= 0 &&
        ij.y + game.stars_coord[k].y < game.field_size.y &&
        ij.x + game.stars_coord[k].x >= 0 &&
        ij.x + game.stars_coord[k].x < game.field_size.x)
        {
 //           ft_printf("ij.y : %d, ij.x: %d\n", ij.y, ij.x);
 //           ft_printf("y : %d, x: %d\n", ij.y + game.stars_coord[k].y, ij.x + game.stars_coord[k].x);
            sum += game.field[ij.y + game.stars_coord[k].y][ij.x + game.stars_coord[k].x];
//            ft_printf("%d\n\n", sum);
            
            if (game.field[ij.y + game.stars_coord[k].y][ij.x + game.stars_coord[k].x] == -2)
                counter++;
            k++;
        }
        else
            return (0);
    }
    if (counter == 1)
    {
 //       ft_printf("res sum %d\n\n", sum);
        return (sum);
    }
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
    min = 0;

    //cur_dist = 0;
    while (++ij.y < game.field_size.y)
    {
        ij.x = -1;
        while (++ij.x < game.field_size.x)
        {
 //           ft_printf("hello\n");
            if (insertable(game, ij))
            {
                cur_dist = insertable(game, ij);
                min = (min < cur_dist && min != 0) ? min : cur_dist;
                res.y = ij.y;
                res.x = ij.x;
     //           ft_printf("insert %d, min %d\n", cur_dist, min);
            }
        }
    }
   // ft_printf("hoh\n");
    // if (min != 0){
        ft_printf("%d %d\n", res.x, res.y);
    //     int x = res.x  + 48;
    //     int y = res.y + 48;
    //     int fd = open("./123", O_RDWR);
    //     write(fd,&x,1);
    //     write(fd," ",1);  
    //     write(fd,&y,1);
    //     write(fd,"\n",1);
    //     close(fd);
    // }

    // else
    //     ft_printf("%d %d\n", 0, 0);
    //ft_printf("hmm\n");
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
    
 //   ft_printf("here2 algo\n");
    dop_field = create_arr(game.field_size.y, game.field_size.x); 
    while (!check_int_arr_equal(game.field, dop_field, game.field_size.y, game.field_size.x))
    {
        if (i == 1)
            del_arr(dop_field, game.field_size.y, game.field_size.x);
        i = 1;
        dop_field = create_same_arr(game.field, game.field_size.y, game.field_size.x);
//        ft_printf("here3\n");
        coord.y = -1;
        while (++coord.y < game.field_size.y)
        {
            coord.x = -1;
            while (++coord.x < game.field_size.x)
            {
                if (game.field[coord.y][coord.x] != -2 && game.field[coord.y][coord.x] != 0)
                    game.field[coord.y][coord.x] = search_min(game.field, coord.y, coord.x, game);
              // ft_printf("%d  ", game.field[coord.y][coord.x]);
            }
  //         ft_printf("\n");
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
            if (line[i] == game.player)
                field[i] = -2;
            else if (line[i] == game.enemy)
                field[i] = 0;
            else
                field[i] = -1;
           // ft_printf("%d  ", field[i]);
        }
  //      ft_printf("     filler\n");
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

     int lol = open("file123", O_WRONLY | O_CREAT);
    //     
        write(lol,"123",3);
    //     write(lol," ",1);  
    //     write(lol,&y,1);
        write(lol,"\n",1);
        //close(lol);

    //return 0;
    i = -1;
    line = ft_strnew(0);
    game.stars_counter = 0;
    // fd = open("test.txt", O_RDONLY);
    fd = 0;//
    while (get_next_line(fd, &line) > 0 && ++i < 2)
    {
        // ft_printf("hello\n");
    //     ft_printf("%s\n", line);
    //     ft_strdel(&line);
    // }
        write(lol,line,ft_strlen(line));
    //     write(lol," ",1);  
    //     write(lol,&y,1);
        write(lol,"\n",1);
        // game.player = (i == 0) ? get_player(line[10]) : game.player;
        // game.enemy = (game.player == 'O') ? 'X' : 'O';
        // game.field_size = (i == 1) ? f_size(line) : game.field_size;
    }
    i = 0;
    // ft_printf("player: %c\n", game.player);
    // ft_printf(" enemy: %c\n", game.enemy);
    // game.field = (int**)malloc(sizeof(int*) * (game.field_size.y));
    // while (1)
    // {
        while (get_next_line(fd, &line) > 0)
        {
            write(lol,line,ft_strlen(line));
    //     write(lol," ",1);  
    //     write(lol,&y,1);
        write(lol,"\n",1);
    }         // int x = res.x  + 48;
    //     int y = res.y + 48;
       
    //     close(lol);
        // ft_printf("hello\n");
        // if (line[0] == '0')
        // {
        //     dop = ft_strsub(line, 4, game.field_size.x);
        //     game.field[ft_atoi(line)] = get_filler_field(dop, game);
        //     ft_strdel(&dop);
        // }
        // if (line[1] == 'i')
        // {
        //     game.piece_size = f_size(line);
        //     game.piece = (char**)malloc(sizeof(char*) * (game.piece_size.y));
        // }
        // if (line[0] == '*' || line[0] == '.')
        // {
        //     game.piece[i] = ft_strsub(line, 0, game.piece_size.x);
        //     game.stars_counter += stars(line);
        //     i++;
        // }
        // ft_strdel(&line);
        // }
        // get_piece(&game);
        // algorithm(game);
    // }
    // printf("ok\n");
	return (0);
}
