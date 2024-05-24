/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:21:51 by hvecchio          #+#    #+#             */
/*   Updated: 2024/05/24 03:58:55 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	char 	*str;
	char 	*str2;
	char 	*str3;
	char 	*str4;
		int	fd;
	int	fd2;
	int	fd3;
	int	fd4;
	int	i;

	fd = 0;
	i = 0;
    fd4 = open("./foo.txt", O_RDONLY);
    fd2 = open("./bible.txt", O_RDONLY);
    fd3 = open("./emptylines.txt", O_RDONLY);
    fd = open("./no_nl.txt", O_RDONLY);
    str = "test";
    str2 = "test";
    str3 = "test";
    str4 = "test";

	while (str)
	{
		str = get_next_line(fd);
		//str2 = get_next_line(fd2);
		//str3 = get_next_line(fd3);
		//str4 = get_next_line(fd4);
		i++;
		printf("Open A #%d -> %d | %s", i, fd, str);
		//printf("Open B #%d -> %d | %s", i, fd2, str2);
		//printf("Open C #%d -> %d | %s", i, fd3, str3);
		//printf("Open D #%d -> %d | %s", i, fd4, str4);
		free(str);
		//free(str2);
		//free(str3);
		//free(str4);
	}
	close(fd);
	close(fd2);
	close(fd3);
	close(fd4);
}
