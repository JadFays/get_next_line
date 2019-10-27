/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fajadron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:05:23 by fajadron          #+#    #+#             */
/*   Updated: 2019/10/27 02:49:09 by fajadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 6

int		get_next_line(int fd, char **line);
int		ft_check_back(char *buf);
int		ft_length_char(char *buf);
//char	*ft_memory(char *buf);
char	*ft_create_str(char **memory, int len);
char	*ft_strjoin(char *memory, char *buf);
char	*ft_memory_after_back(char *memory);

#endif
