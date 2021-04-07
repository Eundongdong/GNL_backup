/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjkim <eunjkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:59:33 by eunjkim           #+#    #+#             */
/*   Updated: 2021/03/16 16:20:00 by eunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"


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
	*line = ft_strdup(*b_buf); //b_buf line에 복제
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

int					save_end(char **b_buf,char **line)
{
	int		check;

	//printf("\n~~~\n%s\n~~~",*b_buf);
	if (!(*b_buf))
	{
		*line = ft_strdup("");
		return (0);//EOF
	}
	else
	{
		
		if ((check = nl_exist(*b_buf)) >= 0)
			return(save_cut(b_buf,line,check));
	}
	// 여기서부터 이상함
	*line = ft_strdup(*b_buf);
	free(*b_buf);
	*b_buf = 0;
	return (0);
	
	//backup이 비었는지 if 로 확인
	//안비어있으면 save_cut으로 다시
	//비어있으면 EOF
	//read에서 -1이 나올때 예외처리
}

int 				get_next_line(int fd, char **line)
{
	char			t_buf[BUFFER_SIZE + 1];
	static char		*b_buf[OPEN_MAX];
	ssize_t			r_size;
	int				check;
	char			*temp;

	if (fd < 0 || fd > OPEN_MAX || line == 0 || BUFFER_SIZE <= 0)
			return (-1); 
			
	while((r_size = read(fd,t_buf,BUFFER_SIZE))> 0) //몇 개 읽었는지 r_size에 저장
	{	

		temp = NULL;
		t_buf[r_size] = '\0'; //문자열로 사용하고자 끝에 널 추가
		temp = ft_strjoin(b_buf[fd],t_buf);
		free(b_buf[fd]);
		b_buf[fd] = temp;
		//printf("===\n%s\n===",b_buf[fd]);
		//백업에 읽은거 추가하기
		check = nl_exist(b_buf[fd]);
		//printf("$$$$$$$\n%d\n$$$$$",check);
		if (check >= 0)
				return(save_cut(&b_buf[fd],line,check));//\n이 있으니까 그 전까지 line에 저장 그 후는 b_buf에 저장
	}
	if (r_size == -1)
		return(-1);
	//printf("#####\n%s\n#####",b_buf[fd]);
	return(save_end(&b_buf[fd],line));//EOF or \n이 없을떄
}

// int 				main()
// {
// 	int r;
// 	int fd;
// 	char *line;

// 	fd = open("test.txt", O_RDONLY);

// 	while ((r = get_next_line(fd, &line)) > 0)
// 	{
// 		printf(" %d %s\n", r,line);
// 		free(line);
// 		line = NULL;
// 	}
// 	printf("%d %s\n",r,line);
// 	free(line);
// 	line = NULL;
// }