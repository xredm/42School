/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mredkole <mredkole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:02:49 by mredkole          #+#    #+#             */
/*   Updated: 2023/02/23 14:07:40 by mredkole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*arr;

	arr = malloc(count * size);
	if (!arr)
		return (0);
	ft_bzero(arr, count * size);
	return (arr);
}

void	ft_bzero(void *arr, size_t size)
{
	char	*str;
	size_t	i;

	str = (char *)arr;
	i = 0;
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
}

char	*ft_strjoin(char const *result, char const *buffer)
{
	char	*new_res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!result || !buffer)
		return (0);
	new_res = malloc(sizeof(char) * (ft_strlen(result)
				+ ft_strlen(buffer) + 1));
	if (!new_res)
		return (0);
	while (result[i] != '\0')
	{
		new_res[i] = result[i];
		i++;
	}
	while (buffer[j] != '\0')
	{
		new_res[i] = buffer[j];
		i++;
		j++;
	}
	new_res[ft_strlen(result) + ft_strlen(buffer)] = '\0';
	return (new_res);
}

char	*ft_strchr(const char *arr, int c)
{
	char	*str;

	str = (char *)arr;
	while (*str != c && *str != '\0')
		str++;
	if (*str == c)
		return (str);
	else
		return (0);
}
