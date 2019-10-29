/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fajadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:04:50 by fajadron          #+#    #+#             */
/*   Updated: 2019/10/29 16:10:31 by fajadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

char	*ft_create_str(char *memory, int len)
{
	int		i;
	char	*stock_line;

	if (!memory)
		return (NULL);
	if (!(stock_line = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (memory[i] != '\n' && memory[i] != '\0')
	{
		stock_line[i] = memory[i];
		i++;
	}
	stock_line[i] = '\0';
	return (stock_line);
}

int		get_next_line(int fd, char **line)
{
	int			ret;
	char		buf[BUFFER_SIZE + 1];
	static char	*memory[OPEN_MAX];


	if (!line || BUFFER_SIZE <= 0)
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) && ret != -1)
	{
		buf[ret] = '\0';
		if (!(memory[fd] = ft_strjoin(memory[fd], buf)))
			return (-1);
		if (ft_check_back(buf))
			break;
	}
	if (memory[fd] && *memory[fd] != '\0')
	{
		if (!(*line = ft_create_str(memory[fd], ft_length_char(memory[fd]))))
			return (-1);
		if (!(memory[fd] = ft_memory_after_back(memory[fd])))
			return (-1);
		return(1);
	}
	if (!memory[fd])
		return (-1);
	return (0);
}
/*
int		main(void)
{
	int		fd;
	char	*str;

	fd = open("./file_test", O_RDONLY);
	if (fd == -1)
	{
		printf("open error");
		return (1);
	}
	get_next_line(fd, &str);
	printf("--str = %s--\n", str);
	get_next_line(fd, &str);
	printf("--str = %s--\n", str);
	get_next_line(fd, &str);
	printf("--str = %s--\n", str);
	get_next_line(fd, &str);
	printf("--str = %s--\n", str);
	get_next_line(fd, &str);
	printf("--str = %s--\n", str);
	get_next_line(fd, &str);
	printf("--str = %s--\n", str);
	get_next_line(fd, &str);
	printf("--str = %s--\n", str);
	printf("return = %d\n", get_next_line(fd, &str));
	printf("return = %d\n", get_next_line(fd, &str));
	printf("return = %d\n", get_next_line(fd, &str));
	printf("return = %d\n", get_next_line(fd, &str));
	printf("return = %d\n", get_next_line(fd, &str));
	if (close(fd) == -1)
	{
		printf("close error");
		return (1);
	}
	return (0);
}*/
