/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fajadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:05:23 by fajadron          #+#    #+#             */
/*   Updated: 2019/10/29 21:58:30 by fajadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2048
#endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <limits.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
int		ft_check_back(char *buf);
int		ft_length_char(char *buf);
void	ft_create_str(char *memory, char **line);
char	*ft_strjoin(char *memory, char *buf);
char	*ft_memory_after_back(char *memory);

#endif
