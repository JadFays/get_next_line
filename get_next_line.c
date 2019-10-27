/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fajadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:04:50 by fajadron          #+#    #+#             */
/*   Updated: 2019/10/27 04:45:48 by fajadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

char	*ft_create_str(char **ptr_memory, int len)
{
	int		i;
	char	*stock_line;
	char	*memory;

	if (!(stock_line = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	memory = *ptr_memory;
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
	char		*buf;
	static char	*memory = NULL;

	if (!line || !fd || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) && ret != -1)
	{
		buf[ret] = '\0';
		memory = ft_strjoin(memory, buf);
		if (ft_check_back(buf))
			break;
	}
	if (memory && *memory != '\0')
	{
		*line = ft_create_str(&memory, ft_length_char(memory));
		memory = ft_memory_after_back(memory);
		return(1);
	}
	if (!memory || !*line)
		return (-1);
	return (0);
}

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
	/*printf("return = %d\n", get_next_line(fd, &str));
	printf("return = %d\n", get_next_line(fd, &str));*/
	if (close(fd) == -1)
	{
		printf("close error");
		return (1);
	}
	return (0);
}
