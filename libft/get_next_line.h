/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 17:12:57 by ychufist          #+#    #+#             */
/*   Updated: 2018/11/20 20:00:47 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <inttypes.h>

int get_next_line(int fd, char **line);
#endif
