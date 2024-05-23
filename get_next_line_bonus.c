/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 08:29:04 by hvecchio          #+#    #+#             */
/*   Updated: 2024/05/23 10:15:04 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char		buffer[MAX_FD][BUFFER_SIZE + 1];
	char			*line;
	size_t			bytesread;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > MAX_FD)
		return (NULL);
	line = ft_strjoin(calloc(1, sizeof(char)), buffer[fd]);
	if (line == NULL)
		return (NULL);
	bytesread = 1;
	while (bytesread > 0 && ft_strchr_id(line, '\n') == -1)
	{
		bytesread = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytesread < 0)
			return (free(line), NULL);
		buffer[fd][bytesread] = 0;
		line = ft_strjoin(line, buffer[fd]);
		if (line == NULL)
			return (NULL);
	}
	ft_clean(line, buffer[fd], '\n');
	if (line[0] == 0)
		return (NULL);
	return (line);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	result = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, ft_strlen(s1) + 1);
	ft_strlcat(result, s2, ft_strlen(s2) + ft_strlen(s1) + 1);
	return (result);
}

int	ft_strchr_id(char *str, char to_find)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	i = 0;
	while (str[i] != (char)to_find)
	{
		if (str[i] == 0)
			return (-1);
		i++;
	}
	return (i);
}

void	ft_clean(char *line, char *buffer, char to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && line[i] != to_find)
		i++;
	if (line[i] == to_find)
		i++;
	while (line[i] && buffer[j])
	{
		buffer[j] = line[i];
		line[i] = 0;
		i++;
		j++;
	}
	buffer[j] = 0;
}
