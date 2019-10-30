/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fajadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:04:50 by fajadron          #+#    #+#             */
/*   Updated: 2019/10/30 20:56:41 by fajadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <assert.h>
#include "./get_next_line.h"

#define mt_assert assert

void	ft_create_str(char *memory, char **line)
{
	int		i;

	i = 0;
	while (memory[i] != '\n' && memory[i] != '\0')
	{
		(*line)[i] = memory[i];
		i++;
	}
	(*line)[i] = '\0';
	//return (*stock_line);
}

int		get_next_line(int fd, char **line)
{
	int			ret;
	char		buf[BUFFER_SIZE + 1];
	static char	*memory[OPEN_MAX];


	if (!line || BUFFER_SIZE <= 0 || fd < 0 || fd > OPEN_MAX)
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(memory[fd] = ft_strjoin(memory[fd], buf)))
			return (ft_free(memory[fd]));
		if (ft_check_back(buf))
			break;
	}
	if (memory[fd] && *memory[fd] != '\0')
	{
		if (!(*line = (char*)malloc(sizeof(char) * (ft_length_char(memory[fd]) + 1))))
			return (ft_free(memory[fd]));
		ft_create_str(memory[fd], &*line);
		memory[fd] = ft_memory_after_back(memory[fd]);
		if (!memory[fd])
			return (ft_free(memory[fd]));
		return(1);
	}
	if (ret == -1)
		return (ft_free(memory[fd]));
	if (!memory[fd])
		free(memory[fd]);
	*line = NULL;
	return (0);
}
/*
   int		main(void)
   {
   char	*line;
   int out;
   int p[2];
   int fd;
   int ret;

   out = dup(1);
   pipe(p);

   fd = 1;
   dup2(p[1], fd);
   write(fd, "abcd\n", 5);
   write(fd, "efgh\n", 5);
   write(fd, "ijkl\n", 5);
   write(fd, "mnop\n", 5);
   write(fd, "qrst\n", 5);
   write(fd, "uvwx\n", 5);
   write(fd, "yzab\n", 5);
   close(p[1]);
   dup2(out, fd);
   get_next_line(p[0], &line);
   mt_assert(strcmp(line, "abcd") == 0);
   free(line);

   get_next_line(p[0], &line);
   mt_assert(strcmp(line, "efgh") == 0);
   free(line);

   get_next_line(p[0], &line);
   mt_assert(strcmp(line, "ijkl") == 0);
   free(line);

   get_next_line(p[0], &line);
   mt_assert(strcmp(line, "mnop") == 0);
   free(line);

   get_next_line(p[0], &line);
   mt_assert(strcmp(line, "qrst") == 0);
   free(line);

   get_next_line(p[0], &line);
   mt_assert(strcmp(line, "uvwx") == 0);
   free(line);

   get_next_line(p[0], &line);
   mt_assert(strcmp(line, "yzab") == 0);
   free(line);

   ret = get_next_line(p[0], &line);
   mt_assert(ret == 0);
//free(line);
}*/
/*
int		main(void)
{
	int		fd;
	char	*str = NULL;
	int i = 0;

	fd = open("./file_test", O_RDONLY);
	if (fd == -1)
	{
		printf("open error");
		return (1);
	}
	while (get_next_line(fd, &str) == 1)
	{
		printf("%d = |%s|\n", i, str);
		i++;
		free(str);
	}
	if (close(fd) == -1)
	{
		printf("close error");
		return (1);
	}
}*/
	/*fd = open("./file_test_1", O_RDONLY);
	if (fd == -1)
	{
		printf("open error");
		return (1);
	}
	free(str);
	while ((get_next_line(fd, &str)) != 0)
	{
		printf("%d = |%s|\n", i, str);
		free(str);
		i++;
	}
	if (close(fd) == -1)
	{
		printf("close error");
		return (1);
	}*/
//	return (0);
//}
