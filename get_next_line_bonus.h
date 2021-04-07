/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjkim <eunjkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:27:54 by eunjkim           #+#    #+#             */
/*   Updated: 2021/03/16 15:52:54 by eunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef	GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

int 	get_next_line(int fd, char **line);
int		save_end(char **b_buf,char **line);
int		save_cut(char **b_buf, char **line, int check);
int		nl_exist(char *b_buf);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *ptr, const void *src, unsigned int n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);
#endif
