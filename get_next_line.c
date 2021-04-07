/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjkim <eunjkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:59:33 by eunjkim           #+#    #+#             */
/*   Updated: 2021/03/16 16:20:00 by eunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					nl_exist(char *b_buf)
{
	int		i;

	i = 0;
	while (b_buf[i])
	{
		if (b_buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int					save_cut(char **b_buf, char **line, int check)
{
	char			*temp;
	int				len;

	(*b_buf)[check] = '\0';
	*line = ft_strdup(*b_buf);
	len = ft_strlen(*b_buf + check + 1);
	if (len == 0)
	{
		free(*b_buf);
		*b_buf = 0;
		return (1);
	}
	temp = ft_strdup(*b_buf + check + 1);
	free(*b_buf);
	*b_buf = temp;
	return (1);
}

int					save_end(char **b_buf, char **line)
{
	int		check;

	if (!(*b_buf))
	{
		*line = ft_strdup("");
		return (0);
	}
	else
	{
		if ((check = nl_exist(*b_buf)) >= 0)
			return (save_cut(b_buf, line, check));
	}
	*line = ft_strdup(*b_buf);
	free(*b_buf);
	*b_buf = 0;
	return (0);
}

int					get_next_line(int fd, char **line)
{
	char			t_buf[BUFFER_SIZE + 1];
	static char		*b_buf[OPEN_MAX];
	ssize_t			r_size;
	int				check;
	char			*temp;

	if (fd < 0 || fd > OPEN_MAX || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	while ((r_size = read(fd, t_buf, BUFFER_SIZE)) > 0)
	{
		temp = NULL;
		t_buf[r_size] = '\0';
		temp = ft_strjoin(b_buf[fd], t_buf);
		free(b_buf[fd]);
		b_buf[fd] = temp;
		check = nl_exist(b_buf[fd]);
		if (check >= 0)
			return (save_cut(&b_buf[fd], line, check));
	}
	if (r_size == -1)
		return (-1);
	return (save_end(&b_buf[fd], line));
}
