/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:15:34 by hvecchio          #+#    #+#             */
/*   Updated: 2024/05/23 10:16:59 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*result;

	if (size != 0 && n > (size_t) - 1 / size)
		return (NULL);
	result = malloc(n * size);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, (n * size));
	return (result);
}

void	ft_bzero(void *ptr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size < 1)
		return (ft_strlen(src));
	while (src[i] && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_size;
	size_t	src_len;

	if ((dest == NULL || src == NULL) && !size)
		return (0);
	i = 0;
	dest_size = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (dest_size >= size)
		return (src_len + size);
	while (src[i] && i < (size - dest_size - 1))
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = 0;
	return (dest_size + src_len);
}

size_t	ft_strlen(const char *str)
{
	size_t	lenght;

	if (!str)
		return (0);
	lenght = 0;
	while (str[lenght])
	{
		lenght++;
	}
	return (lenght);
}
