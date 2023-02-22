/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mredkole <mredkole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:02:49 by mredkole          #+#    #+#             */
/*   Updated: 2023/02/21 21:08:21 by mredkole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	strlen(const char *arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		i++;
	}
	return (i);
}

char	*strchr(const char *buff_total, int c)
{
	while ((char)c != *buff_total)
	{
		if (!*buff_total)
			return (0);
		buff_total++;
	}
	return ((char *)buff_total);
}

char	*strjoin(char *buff_total, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*arr;

	if(!buff_total)
	{
		buff_total = malloc(sizeof(char) * 1);
		buff_total[0] = '\0';
	}
	if (!buffer)
		return (0);
	arr = malloc(sizeof(char) * ((strlen(buff_total) + strlen(buffer))));
	if (!arr)
		return (0);
	i = 0;
	j = 0;
	while (buff_total[i])
		arr[i++] = buff_total[j++];
	j = 0;
	while (buffer[j])
		arr[i++] = buffer[j++];
	arr[strlen(buff_total) + strlen(buffer)] = '\0';
	free(buff_total);
	return (arr);
}

