/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fajadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:04:50 by fajadron          #+#    #+#             */
/*   Updated: 2019/10/30 22:17:37 by fajadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

void	ft_create_str(char *memory, char **line)
{
	int		i;

	*line = (char*)malloc(sizeof(char) * (ft_length_char(memory) + 1));
	if (!line)
		return ;
	i = 0;
	while (memory[i] != '\n' && memory[i] != '\0')
	{
		(*line)[i] = memory[i];
		i++;
	}
	(*line)[i] = '\0';
}

int		ft_create_and_stock(char **memory, char **line)
{
	ft_create_str(*memory, &*line);
	if (!line)
		return (ft_free(*memory));
	*memory = ft_memory_after_back(*memory);
	if (!*memory)
		return (ft_free(*memory));
	return (1);
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
			break ;
	}
	if (ret == -1)
		return (ft_free(memory[fd]));
	if (memory[fd] && *memory[fd] != '\0')
		return (ft_create_and_stock(&memory[fd], &*line));
	*line = NULL;
	return (0);
}
