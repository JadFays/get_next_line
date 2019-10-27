/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fajadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:05:06 by fajadron          #+#    #+#             */
/*   Updated: 2019/10/27 02:50:36 by fajadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

int		ft_check_back(char *buf)
{
	if (!buf)
		return (1);
	while (*buf != '\0')
	{
		if (*buf == '\n')
			return (1);
		buf++;
	}
	return (0);
}

/*char	*ft_memory(char *buf)
{
	int		i;
	char	*memory;

	if (!buf)
		return (NULL);
	i = 0;
	while (buf[i] != '\0')
		i++;
	if (!(memory = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (buf[i] != '\0')
	{
		memory[i] = buf[i];
		i++;
	}
	memory[i] = '\0';
	return (memory);
}*/

int		ft_length_char(char *str)
{
	int	lenght = 0;

	while (*str)
	{
		if (*str == '\n' || *str == '\0')
		{
			return (lenght);
		}
		lenght++;
		str++;
	}
	return (0);
}

char	*ft_strjoin(char *memory, char *buf)
{
	int		i;
	int		len;
	char	*str;

	if (!memory && !buf)
		return (NULL);
	i = 0;
	len = 0;
	while (memory && memory[i++] != '\0')
		len++;
	i = 0;
	while (buf && buf[i++] != '\0')
		len++;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	 i = 0;
	while (memory && *memory != '\0')
		str[i++] = *memory++;
	while (buf && *buf != '\0')
		str[i++] = *buf++;
	str[i] = '\0';
	return (str);
}

char	*ft_memory_after_back(char *memory)
{
	int		i;
	int		check;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	check = 0;
	while (memory[i + len] != '\0')
	{
		if (memory[i - 1] == '\n' && check == 0)
			check = 1;
		if (check == 1)
			len++;
		else
			i++;
	}
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	len = 0;
	while (memory[i] != '\0')
		str[len++] = memory[i++];
	str[len] = '\0';
	return (str);
}