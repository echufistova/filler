/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 17:12:57 by ychufist          #+#    #+#             */
/*   Updated: 2018/07/16 17:16:22 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#ifndef GET_NEXT_LINE_H
//# define GET_NEXT_LINE_H
//# define BUFF_SIZE 30
//
//# include <sys/types.h>
//# include <sys/stat.h>
//# include <fcntl.h>
//
//# include <string.h>
//# include <stdlib.h>
//# include <unistd.h>
//# include <stdio.h>
//# include <inttypes.h>
//
//int get_next_line(int fd, char **line);
//
//#endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 4
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

typedef struct		s_str
{
    int				fd;
    char			*content;
    struct s_str	*next;
}					t_str;

int					get_next_line(const int fd, char **line);

#endif