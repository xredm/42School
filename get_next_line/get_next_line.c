/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mredkole <mredkole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:02:58 by mredkole          #+#    #+#             */
/*   Updated: 2023/02/21 21:08:18 by mredkole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*read_file(int fd, char *buff_total)
{
	char	*buffer;
	int	bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	bytes = 1; //to enter the loop -1 error; 
	// strchr '\n' to quit if nl is found
	while (bytes != 0 && !strchr(buff_total, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);//while not eof
		if (bytes == -1)//on error; or interrupt
		{
			free(buffer);
			return (0);
		}
		buffer[bytes] = '\0';
		buff_total = strjoin(buff_total, buffer);//join and free
	}
	free(buffer);
	return (buff_total);
}

char	*take_line(char *buff_total)//takes line to return
{
	int	i;
	char	*arr;

	i = 0;
	if (!buff_total)//check if no line
		return (0);
	while (buff_total[i] && buff_total[i] != '\n')//find eol
		i++;
	arr = malloc(sizeof(char) * (i + 2));//allocate till eol
	if (!arr)
		return (0);
	i = 0;
	while (buff_total[i] && buff_total[i] != '\n')
	{
		arr[i] = buff_total[i];
		i++;
	}
	if (buff_total[i] == '\n')//if nl found we add it as well
	{
		arr[i] = buff_total[i];
		i++;
	}
	arr[i] = '\0';//we finish the line
	return (arr);
}

char	*next_line(char *buff_total)//we delete the line that we found
{
	int	i;
	int	j;
	char	*arr;

	i = 0;
	j = 0;
	while (buff_total[i] && buff_total[i] != '\n')
		i++;//find the len of the current line
	if (!buff_total[i])
	{
		free(buff_total);
		return (0);//if there is nothing after then NULL
	}
	//len of the file - len of the line
	arr = malloc(sizeof(char) * (strlen(buff_total) - i + 1));
	if (!arr)
		return (0);
	i++;//got to next line
	while (buff_total[i])
		arr[i++] = buff_total[j++];//fill up
	arr[i] = '\0';
	free(buff_total);
	return (arr);
}

char	*get_next_line(int fd)
{
	static char	*buff_total;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
			return (0);
	buff_total = read_file(fd, buff_total);
	if (!buff_total)
		return (0);
	line = take_line(buff_total);
	buff_total = next_line(buff_total);
	return (line);
}

int	main(void)
{
	char *line;
	int i;
	int fd;
	int fd1;
	int fd2;
	int fd3;
	
	i = 1;
	fd = open("bla.txt", O_RDONLY);
	fd1 = open("bla1.txt", O_RDONLY);
	fd2 = open("bla2.txt", O_RDONLY);
	fd3 = open("bla3.txt", O_RDONLY);
	while (i < 7)
	{
		line = get_next_line(fd);
		printf("%d line is: %s", i, line);
		free(line);
		line = get_next_line(fd1);
		printf("%d line is: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("%d line is: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("%d line is: %s", i, line);
		free(line);
	}
	close(fd);
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}