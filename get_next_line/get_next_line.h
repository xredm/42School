/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mredkole <mredkole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:03:02 by mredkole          #+#    #+#             */
/*   Updated: 2023/02/21 21:08:23 by mredkole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

size_t	strlen(const char *arr);
char	*strjoin(char *buff_total, char *buffer);
char	*get_next_line(int fd);
char	*strchr(const char *buff_total, int c);
char	read_line(int fd, char *buff_total);
char	*get_line_after(char *buff_total);
char	*new_line(char *buff_total);

#endif