/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:40:13 by ychufist          #+#    #+#             */
/*   Updated: 2018/11/20 18:10:26 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_FILLER_H
# define FILLER_FILLER_H

# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "libft/get_next_line.h"

typedef	struct	s_player
{
	char big_letter;
	char small_letter;
}				t_player;

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef	struct	s_game
{
	int			stars_counter;
	char		player;
	char		enemy;
	int			**field;
	char		**piece;
	t_point		begin_coord;
	t_point		piece_size;
	t_point		field_size;
	t_point		*stars_coord;
}				t_game;

void			clean_all(t_game *game);
int				stars(char *line);
char			get_player(char c);
t_point			f_size(char *line);
int				*get_filler_field(char *line, t_game game);
int				insertable(t_game game, t_point ij);
void			algorithm(t_game game);
int				search_min(int **field, int i, int j, t_game game);
void			get_coord(t_game game);
void			get_piece(t_game *game);
#endif
