/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 08:29:04 by hvecchio          #+#    #+#             */
/*   Updated: 2024/05/24 04:03:10 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_buffer	buffer[MAX_FD];
	char			*line;
	size_t			line_len;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > MAX_FD)
		return (NULL);
	line = ft_bfrjoin(NULL, &buffer[fd], 0);
	if (line == NULL)
		return (NULL);
	line_len = buffer[fd].size;
	buffer[fd].size = ft_max(1, buffer[fd].size);
	while (buffer[fd].size > 0 && ft_strchr(line, '\n') == 0)
	{
		buffer[fd].size = read(fd, buffer[fd].content, BUFFER_SIZE);
		if (buffer[fd].size > 0)
			line = ft_bfrjoin(line, &buffer[fd], line_len);
		line_len += buffer[fd].size;
		if (line == NULL || line_len == 0)
			return (free(line), NULL);
	}
	return (ft_clean(line, &buffer[fd], line_len, '\n'));
}

size_t	ft_max(size_t a, size_t b)
{
	if (a >= b)
		return (a);
	return (b);
}

char	*ft_bfrjoin(char *line, t_buffer *buffer, size_t line_len)
{
	char		*result;
	size_t		i;

	if (line_len + (*buffer).size == 0)
		return (calloc(1, sizeof(char)));
	result = malloc((line_len + (*buffer).size) * sizeof(char));
	if (!result)
		return (free(line), NULL);
	i = 0;
	while (i < line_len)
	{
		result[i] = line[i];
		i++;
	}
	result[i] = 0;
	while (i < line_len + (*buffer).size)
	{
		result[i] = (*buffer).content[i - line_len];
		i++;
	}
	result[i] = 0;
	free(line);
	return (result);
}

int	ft_strchr(char *str, char to_find)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	i = 0;
	while (str[i] != to_find)
	{
		if (str[i] == 0)
			return (0);
		i++;
	}
	return (i + 1);
}

char	*ft_clean(char *line, t_buffer *buffer, size_t line_len, char to_find)
{
	char	*result;
	size_t	result_len;
	size_t	i;

	if (ft_strchr(line, to_find) == 0)
		result_len = line_len;
	else
		result_len = ft_strchr(line, to_find);
	result = malloc(sizeof(char) * (result_len + 1));
	if (!result)
		return (free(line), NULL);
	i = -1;
	while (++i < result_len)
		result[i] = line[i];
	i--;
	result[result_len] = 0;
	while (++i < line_len)
		(*buffer).content[i - result_len] = line[i];
	(*buffer).size = line_len - result_len;
	free(line);
	return (result);
}
