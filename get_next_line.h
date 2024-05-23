/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 02:56:07 by hvecchio          #+#    #+#             */
/*   Updated: 2024/05/23 13:10:45 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# define MAX_FD 1024

# include <stdlib.h>
# include <unistd.h>

typedef struct s_buffer
{
	char	content[MAX_FD][BUFFER_SIZE];
	size_t	size[MAX_FD];
}	t_buffer;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr_id(char *str, char to_find);
void	ft_clean(char *line, char *buffer, char to_find);
void	ft_bzero(void *ptr, size_t n);
void	*ft_calloc(size_t n, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);

#endif
