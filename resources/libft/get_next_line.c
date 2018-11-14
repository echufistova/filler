/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 18:50:02 by ychufist          #+#    #+#             */
/*   Updated: 2018/10/25 14:09:01 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

//int		get_line(char ***line, char **stack, char **dop)
//{
//	unsigned int i;
//
//	i = 0;
//	while ((*stack)[i] != '\n' && (*stack)[i] != '\0')
//		i++;
//	if ((*stack)[i] == '\n')
//	{
//		**line = ft_strsub(*stack, 0, (size_t)i);
//		i++;
//		*dop = ft_strsub(*stack, i, ft_strlen(*stack) - i);
//		free(*stack);
//		*stack = ft_strdup(*dop);
//		free(*dop);
//		return (1);
//	}
//	return (0);
//}
//
//int		check_last(int ret, char **stack_fd, char **line, char **dop)
//{
//	if (!ret)
//	{
//		if (*stack_fd && ft_strlen(*stack_fd) != 0)
//		{
//			if (get_line(&line, stack_fd, dop) == 1)
//				return (1);
//			*line = ft_strdup(*stack_fd);
//			ft_bzero(*stack_fd, ft_strlen(*stack_fd));
//			return (1);
//		}
//		return (0);
//	}
//	return (1);
//}
//
//int		get_next_line(const int fd, char **line)
//{
//	int				ret;
//	char			*dop;
//	static char		*stack[8192];
//	char			buf[BUFF_SIZE + 1];
//
//	if (BUFF_SIZE <= 0 || read(fd, buf, 0) < 0)
//		return (-1);
//	while ((ret = read(fd, buf, BUFF_SIZE)))
//	{
//		buf[ret] = '\0';
//		if (!stack[fd])
//			stack[fd] = ft_strdup(buf);
//		else
//		{
//			dop = ft_strjoin(stack[fd], buf);
//			free(stack[fd]);
//			stack[fd] = ft_strdup(dop);
//			free(dop);
//		}
//		if (get_line(&line, &stack[fd], &dop) == 1)
//			break ;
//	}
//	return (check_last(ret, &stack[fd], line, &dop));
//}

t_str	*find_fd(t_str **list, int fd)
{
	t_str *tmp;
	t_str *node;

	tmp = *list;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (fd)
	{
		tmp = *list;
		node = (t_str *)malloc(sizeof(t_str));
		node->content = ft_memalloc(BUFF_SIZE);
		read(fd, node->content, BUFF_SIZE);
		node->fd = fd;
		node->next = NULL;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
		return (node);
	}
	return (0);
}

t_str	*lstnew(t_str **list, int fd)
{
	t_str *tmp;
	t_str *node;

	tmp = NULL;
	node = NULL;
	if (!(*list))
	{
		(*list) = (t_str *)malloc(sizeof(t_str));
		(*list)->content = ft_memalloc(BUFF_SIZE);
		read(fd, (*list)->content, BUFF_SIZE);
		(*list)->fd = fd;
		(*list)->next = NULL;
		return (*list);
	}
	if ((node = find_fd(list, fd)))
		return (node);
	return (0);
}

char	*combine(char *str, char *buff)
{
	int		i;
	int		j;
	int		len;
	char	*tmp;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	tmp = (char *)malloc(sizeof(char) * (len + BUFF_SIZE + 1));
	while (i < len)
		tmp[j++] = str[i++];
	i = 0;
	while (buff[i] != '\0')
		tmp[j++] = buff[i++];
	tmp[j] = '\0';
	free(str);
	return (tmp);
}

int		get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	int				var;
	char			*ptr;
	static t_str	*list;
	t_str			*node;

	if (fd < 0 || read(fd, 0, 0) == -1)
		return (-1);
	node = lstnew(&list, fd);
	while (!((ptr = ft_strchr(node->content, '\n'))))
	{
		ft_bzero(buff, BUFF_SIZE + 1);
		if ((read(fd, buff, BUFF_SIZE)) == 0)
			break ;
		node->content = combine(node->content, buff);
	}
	if ((var = ft_strlen(node->content)) == 0 && !ptr)
		return (0);
	if (ptr)
		var -= ft_strlen(ptr++);
	else
		ptr = "\0";
	*line = ft_strsub(node->content, 0, var);
	node->content = ft_strcpy(node->content, ptr);
	return (1);
}