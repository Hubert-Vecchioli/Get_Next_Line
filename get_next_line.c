/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 02:55:47 by hvecchio          #+#    #+#             */
/*   Updated: 2024/05/20 03:51:54 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
   	char				*buffer;
	ssize_t				bytesread;

    // Check de protection
    if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
        return (NULL)
    // lire le doc
    bytesread = 1;
    while () // continuer tant qu'on a pas de \n ou bytesread <0
        bytesread = read(fd, buffer, BUFFER_SIZE);
        // Ajouter dans un 2eme buffer ligne
    // free buffer
    //return the full line content
}