/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mredkole <mredkole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:02:58 by mredkole          #+#    #+#             */
/*   Updated: 2023/02/23 12:51:39 by mredkole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *result, char *buffer)/*here we join both and free the result*/
{
	char	*arr;

	arr = ft_strjoin(result, buffer);
	free(result);
	return (arr);
}

char	*read_file(int fd, char *result)
{
	char	*buffer;
	int		bytes;

	if (!result)/*malloc since result is empty*/
		result = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));/*malloc according to our buffer size*/
	bytes = 1;
	while (bytes > 0 && !ft_strchr(buffer, '\n'))/*stop when nl reached*/	
	{
		bytes = read(fd, buffer, BUFFER_SIZE);/*while loop until the eof is reached*/
		if (bytes == -1)/*error happened or interrupt 0 is when whole file is read*/
		{
			free(buffer);
			return (0);
		}
		buffer[bytes] = '\0';/*end it to protect from leaks*/
		result = ft_free(result, buffer);/*join result & buffer then free*/
	}
	free(buffer);
	return (result);
}

char	*get_line(char *total)/*takes one line for a return*/
{
	char	*line;
	int		i;

	i = 0;
	if (!total[i])
		return (0);
	while (total[i] && total[i] != '\n')/*find the end of the line*/
		i++;
	line = ft_calloc(i + 2, sizeof(char));/*malloc the size of the line*/
	i = 0;
	while (total[i] && total[i] != '\n')/*fill up the line*/
	{
		line[i] = total[i];
		i++;
	}
	if (total[i] == '\n')
		line[i++] = '\n';
	return (line);/*return our line*/
}

char	*next_line(char *total)/*delete prev line and get next*/
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (total[i] && total[i] != '\n')/*we find the len of the first line*/
		i++;
	if (!total[i])/*if its the end return 0*/
	{
		free(total);
		return (0);
	}
	line = ft_calloc((ft_strlen(total) - i + 1), sizeof(char));/*len of the file minus the end of the line*/
	i++;/*go to the next element*/
	j = 0;
	while (total[i])/*fill up*/
		line[j++] = total[i++];
	free(total);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*total;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	total = read_file(fd, total);/*read whole*/
	if (!total)
		return (0);
	line = get_line(total);/*get one line*/
	total = next_line(total);/*get next line, del prev*/
	return (line);
}

/*int	main(void)
{
	char	*line;
	int		fd;
	int		fd2;
	int		fd3;
	int		i;
    
	fd = open("bla1.txt", O_RDONLY);
	//bonus
	//fd2 = open("test2.txt", O_RDONLY);
	//fd3 = open("test3.txt", O_RDONLY);
    
	i = 0;
	while (i < 4)
	{
		line = get_next_line(fd);
		printf("line %d: %s", i, line);
		free(line);
		//bonuses
		//line = get_next_line(fd2);
		//printf("line %d: %s", i, line);
		//free(line);
		//line = get_next_line(fd3);
		//printf("line %d: %s", i, line);
		//free(line);
		//i++;
	}
	close(fd);
	close(fd2);
	close(fd3);
	return (0);
}*/