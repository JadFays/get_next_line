/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fajadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:05:06 by fajadron          #+#    #+#             */
/*   Updated: 2019/10/30 22:07:08 by fajadron         ###   ########.fr       */
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

int		ft_length_char(char *str)
{
	int	length;

	length = 0;
	while (*str)
	{
		if (*str == '\n')
			return (length);
		length++;
		str++;
	}
	return (length);
}

char	*ft_strjoin(char *memory, char *buf)
{
	int		i;
	int		len;
	char	*str;

	if (!buf)
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
	len = 0;
	while (memory && memory[len] != '\0')
		str[i++] = memory[len++];
	if (memory)
		free(memory);
	while (buf && *buf != '\0')
		str[i++] = *buf++;
	str[i] = '\0';
	return (str);
}

char	*ft_memory_after_back(char *memory)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	while (memory[i] != '\0' && memory[i] != '\n')
		i++;
	if (memory[i] == '\n')
		i++;
	while (memory[i + len] != '\0')
		len++;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	len = 0;
	while (memory[i] != '\0')
		str[len++] = memory[i++];
	str[len] = '\0';
	free(memory);
	return (str);
}

int		ft_free(char *memory)
{
	free(memory);
	return (-1);
}
